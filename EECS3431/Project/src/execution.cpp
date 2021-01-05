#include "execution.hpp"
#include "utility.hpp"

Execution::Execution()
{}

void Execution::runEngine()
{
    Space* space = Space::getInstance();
    int colCount = space->m_image->m_nColumns;
    int rowCount = space->m_image->m_nRows;
    for (int c = 0; c < colCount; c++)
    {
        for (int r = 0; r < rowCount; r++)
        {
            glm::vec3 eyeToPixelDirectionVector = Utility::findEyeToPixelDirectionVector(c, r);
            Ray* eyeToPixelRay = new Ray (space->m_camera->getEyeLoc(), eyeToPixelDirectionVector);

            glm::vec3 pixelColor = Execution::rayTrace(eyeToPixelRay, 1);
            Color* pixNormalizedColor = new Color(pixelColor[0], pixelColor[1], pixelColor[2]);
            space->m_image->setPixel(c, r, pixNormalizedColor);
        }  
    }
    space->m_image->save_image();
}

glm::vec3 Execution::rayTrace(Ray* ray, int currDepth)
{
    // Base case
    if (currDepth > Execution::MAX_DEPTH)
    {
        return glm::vec3(0, 0, 0); // Return black
    }

    Sphere* closestSphere = NULL;
    double smallestIntersectionTime = DBL_MAX; // this point is on `closestSphere`

    // Find the closest intersection with a sphere
    Space* space = Space::getInstance();
    for (Sphere* sphere : space->m_spheres)
    {
        double intersectionTime = ray->getRayIntersectionTimeWithArbitraryElipsoid(sphere->m_inverseTransMat);

        // An intersection happened
        if (intersectionTime != -1)
        {
            if (intersectionTime < smallestIntersectionTime)
            {
                closestSphere = sphere;
                smallestIntersectionTime = intersectionTime;
            }
        }
    }

    // No intersection exists with any of the objects in scene
    if (closestSphere == NULL)
    {
        // return background color
        return glm::vec3(space->m_background->m_color_r, space->m_background->m_color_g, space->m_background->m_color_b);
    }

    else
    {
        // Calculate local illumination
        glm::vec3 pointOfIntersection = ray->getPointOnRay(smallestIntersectionTime);

        // USING THE INVERSE TRANSPOSE DOES NOT WORK, THERE IS SOMETHING FUNDAMENTAL THAT I DO NOT UNDERSTAND
        // glm::vec4 poi = glm::vec4(glm::vec3(pointOfIntersection[0], pointOfIntersection[1], pointOfIntersection[2]), 1);
        // glm::vec4 tpoi = closestSphere->m_inverseTransposeTransMat * poi;
        // glm::vec3 N = glm::vec3(tpoi[0], tpoi[1], tpoi[2]);
        // glm::vec3 posS = glm::vec3(closestSphere->m_posX, closestSphere->m_posY, closestSphere->m_posZ);
        // N = glm::normalize(N - posS); 

        glm::vec3 N = Execution::getNormalizedVector(glm::vec3(closestSphere->m_posX, closestSphere->m_posY, closestSphere->m_posZ), pointOfIntersection);
        glm::vec3 reflectedVector = Execution::getNormalizedReflectedVector(N, ray->m_directionVector);
        Ray* reflectedRay = new Ray(pointOfIntersection, reflectedVector);

        // Final pixel color
        glm::vec3 pixelColor = 
                            Execution::ambient(closestSphere) + 
                            Execution::sumShadowRays(pointOfIntersection, closestSphere, N) +
                            glm::vec1(closestSphere->m_k_r) * rayTrace(reflectedRay, currDepth+1);
                            ;
        return pixelColor;
    } 
}

glm::vec3 Execution::ambient (Sphere* currSphere)
{
    Space* space = Space::getInstance();
    glm::vec3 res = glm::vec3(0.0, 0.0, 0.0); // RGB color initiated
    res[0] = currSphere->m_k_a * space->m_ambient->m_i_r * currSphere->m_color_r; // Ambient (RED)
    res[1] = currSphere->m_k_a * space->m_ambient->m_i_g * currSphere->m_color_g; // Ambient (GREEN)
    res[2] = currSphere->m_k_a * space->m_ambient->m_i_b * currSphere->m_color_b; // Ambient (BLUE)
    return res;
}

glm::vec3 Execution::sumShadowRays (glm::vec3 p, Sphere* currSphere, glm::vec3 N)
{
    Space* space = Space::getInstance();
    glm::vec3 res = glm::vec3(0.0, 0.0, 0.0); // RGB color initiated

    for (Light* light: space->m_lights)
    {
        // Construct the N, L, R, V
        // glm::vec3 N = Execution::getNormalizedVector(glm::vec3(currSphere->m_posX, currSphere->m_posY, currSphere->m_posZ), p);
        glm::vec3 L = Execution::getNormalizedVector(p, glm::vec3(light->m_posX, light->m_posY, light->m_posZ));
        glm::vec3 R = Execution::getNormalizedReflectedVector(N, L);
        glm::vec3 V = Execution::getNormalizedVector(space->m_camera->getEyeLoc(), glm::vec3(light->m_posX, light->m_posY, light->m_posZ));

        if ((glm::dot(N, L) >= 0))
        {
            Ray* rayL = new Ray(p, L);
            rayL->avoidTimeZero(); // void possible intersection with currSphere
            bool wayIsClear = true;

            // Check intersection of rayL with every object in the scene except from current object
            // If no intersection, apply local illumination. Otherwise, ignore
            for (Sphere* someSphere: space->m_spheres)
            {
                bool inersectionHappens = rayL->peekIntersectionWithElipsoid(someSphere->m_inverseTransMat);
                if (inersectionHappens) // There is nothing between `p` and light
                {
                    wayIsClear = false;
                    break;
                }
            }

            if (wayIsClear)
            {
                // No intersection, which means no object stands in the of point `p` to `light`
                res[0] = 
                        res[0] +
                        currSphere->m_k_d * light->m_i_r * (glm::dot(N, L)) * currSphere->m_color_r // Diffuse (RED) 
                        +
                        currSphere->m_k_s * light->m_i_r * pow((glm::dot(R, V)), currSphere->m_spec_exp) // Spec (RED)
                        ; // RED component
                res[1] = 
                        res[1] +
                        currSphere->m_k_d * light->m_i_g * (glm::dot(N, L)) * currSphere->m_color_g // Diffuse (GREEN) 
                        +
                        currSphere->m_k_s * light->m_i_g * pow((glm::dot(R, V)), currSphere->m_spec_exp) // Spec (GREEN)
                        ; // GREEN component
                res[2] = 
                        res[2] +
                        currSphere->m_k_d * light->m_i_b * (glm::dot(N, L)) * currSphere->m_color_b // Diffuse (BLUE) 
                        +
                        currSphere->m_k_s * light->m_i_b * pow((glm::dot(R, V)), currSphere->m_spec_exp) // Spec (BLUE)
                        ; // BLUE component
            }

        }
        else
        {
            // res = glm::vec3(0.5,0.5,0.5);//res = res + Execution::ambient(currSphere);
        }
    }
    return res;
}


Ray* Execution::getEyeToPixelRay(int colPoxel, int rowPixel)
{
    glm::vec3 startingPoint = glm::vec3(0, 0, 0);
    glm::vec3 directionVec = Utility::findEyeToPixelDirectionVector(colPoxel, rowPixel);
    return new Ray(startingPoint, directionVec);
}

glm::vec3 Execution::getNormalizedVector (glm::vec3 point1, glm::vec3 point2)
{
    glm::vec3 vec = point2 - point1;
    if (glm::length(vec) > 0)
    {
        return glm::normalize(vec);
    }
     return vec;
    
}

glm::vec3 Execution::getNormalizedReflectedVector (glm::vec3 N, glm::vec3 c)
{
    double scalar = -2 * glm::dot(N, c);
    glm::vec3 vec = glm::vec1(scalar) * N + c;
    if (glm::length(vec) > 0)
    {
        return  glm::normalize(glm::vec1(scalar) * N + c);
    }
    return vec;
}