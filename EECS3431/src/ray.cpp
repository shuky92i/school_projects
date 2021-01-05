#include "ray.hpp"
#include "utility.hpp"

Ray::Ray()
{}

Ray::Ray(glm::vec3 startingPoint, glm::vec3 directionVector)
{
    this->m_startingPoint = startingPoint;
    if (glm::length(directionVector) > 0)
    {
        this->m_directionVector = glm::normalize(directionVector);
    }
    else
    {
        this->m_directionVector = directionVector;
    }
}

glm::vec3 Ray::getPointOnRay(double t)
{
    glm::vec3 desiredPoint = this->m_startingPoint + glm::vec1(t) * this->m_directionVector;
    return desiredPoint;
}

void Ray::avoidTimeZero()
{
    this->m_startingPoint = this->getPointOnRay(0.000001);
}

double Ray::getRayIntersectionTimeWithArbitraryElipsoid(glm::mat4 transMat)
{
    Ray* inverseRay = this->getTransformed(transMat);
    std::vector<double> intersectionPoints = inverseRay->getIntersectionTimessWithCanonicalSphere();

    // No intersection 
    if (intersectionPoints.size() == 0)
    {
        return -1; // Meaning there is no intersection because time can't be negative
    }

    // 1 intersection point (ray is tangent to sphere)
    else if (intersectionPoints.size() == 1)
    {
        if (intersectionPoints[0] <= 0)
        {
            return -1;
        }
        return intersectionPoints[0];
    }

    // 2 intersection point (ray speres the sphere)
    else
    {
        double min = Utility::getMin2(intersectionPoints[0], intersectionPoints[1]);
        double max = Utility::getMax2(intersectionPoints[0], intersectionPoints[1]);

        if ((min <= 0) && (max <= 0))
        {
            return -1;
        }

        else if ((min <= 0) && (max > 0))
        {
            return max;
        }
        
        else // ((min > 0) && (max > 0))
        {
            return min;
        }       
    }    
}

bool Ray::peekIntersectionWithElipsoid(glm::mat4 inverseMat)
{
    double intersectionTime = this->getRayIntersectionTimeWithArbitraryElipsoid(inverseMat);
    if (intersectionTime == -1)
    {
        return false;
    }
    return true;
}

std::vector<double> Ray::getIntersectionTimessWithCanonicalSphere()
{
    // Form quadratic equation with canonical sphere
    double cLenSquared = glm::length(this->m_directionVector) * glm::length(this->m_directionVector); // |c|^2
    double sDotC = glm::dot(this->m_startingPoint, this->m_directionVector); // S dot c
    double sLenSquared = glm::length(this->m_startingPoint) * glm::length(this->m_startingPoint); // |s|^2
    QuadraticEquation* eq = new QuadraticEquation(cLenSquared, 2*sDotC, sLenSquared-1);

    // Find intersection points and return them to caller
    return eq->getSolutions();
}

Ray* Ray::getTransformed(glm::mat4 transMat)
{
    // Transform ray to homogeneous form first
    glm::vec4 s = glm::vec4(this->m_startingPoint[0], this->m_startingPoint[1], this->m_startingPoint[2], 1); // Point
    glm::vec4 c = glm::vec4(this->m_directionVector[0], this->m_directionVector[1], this->m_directionVector[2], 0); // Direction

    // Calculate new data
    glm::vec4 sInvTransH = transMat * s;
    glm::vec4 cInvTransH = transMat * c;

    // Back ho non-homogeneous form
    glm::vec3 sInvTrans = glm::vec3(sInvTransH[0], sInvTransH[1], sInvTransH[2]);
    glm::vec3 cInvTrans = glm::vec3(cInvTransH[0], cInvTransH[1], cInvTransH[2]);

    // Construct the new inverse transformed ray
    Ray* inverseTransRay;
    if (glm::length(cInvTrans) > 0)
    {
        inverseTransRay = new Ray(sInvTrans, glm::normalize(cInvTrans));
    }
    else
    {
        inverseTransRay = new Ray(sInvTrans, cInvTrans);
    }
    return inverseTransRay;
}

void Ray::debugPrintState()
{
    std::cout << "ray(t) = ";

    std::cout << "(";
    Utility::debugPrintVec3(this->m_startingPoint);
    std::cout << ")";

    std::cout << " + ";

    std::cout << "t(";
    Utility::debugPrintVec3(this->m_directionVector);
    std::cout << ")";
    std::cout << std::endl;

    //std::vector<double> sols = this->getIntersectionTimessWithCanonicalSphere();
    // if (sols.size() == 2)
    // {
    //     std::cout << "Inersection with canonical sphere: ";
    //     std::cout << "t0 = " << sols[0] << ", ";
    //     std::cout << "t1 = " << sols[1];
    // }
    // else if (sols.size() == 1)
    // {
    //     std::cout << "t0 = " << sols[0];
    // }
    // else
    // {
    //     std::cout << "None";
    // }
    //std::cout << std::endl;
}