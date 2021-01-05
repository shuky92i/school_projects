#ifndef EXECUTION_HPP
#define EXECUTION_HPP

#include "ray.hpp"
#include "sphere.hpp"

class Execution
{
    public:
        /*
        *  Description: Main method to be called from `main.cpp`
        *  Use: Run raytracer algorithm and output a ppm image
        *  Input: NA
        *  Output: ppm image file. Void to caller
        *  Throws: NA
        */
        static void runEngine();

        /*
        *  Description: raytracer recursive function
        *  Use: Called on each eye-pixel ray
        *  Input: Ray `ray`, `currDepth` indicating the depth of the ray
        *  Output: The color which the ray detects
        *  Throws: NA
        */
        static glm::vec3 rayTrace(Ray* ray, int currDepth);

        /*
        *  Description: Construct a new Ray between the eye and the given pixel location
        *  Use: Acting as a helper function to in the raytracing algorithm
        *  Input: The coordinates of the pixel on the NEAR plane
        *  Output: Ray object starting from eye location (0, 0, 0) through the given pixel location
        *  Throws: NA
        */
        static Ray* getEyeToPixelRay(int colPoxel, int rowPixel);

        /*
        *  Description: Given 2 points (i.e light and point on a sphere), create the corresponding normalized vector
        *  Use: Used as a helper function to get L, N, and V
        *  Input: Two points, vector desired is going from `point1` to `point2`
        *  Output: A `glm::vec3` representing the normalized vector from `point1` to `point2`
        *  Throws: NA
        */
        static glm::vec3 getNormalizedVector (glm::vec3 point1, glm::vec3 point2);

        /*
        *  Description: Given normal `N` and direction vector `c` of some ray, return the reflection ray 
        *               at the point of intersection
        *  Use: Used as a helper function to get R
        *  Input: Normal and direction vector
        *  Output: Reflection vector at the point of intersection
        *  Throws: NA
        */
        static glm::vec3 getNormalizedReflectedVector (glm::vec3 N, glm::vec3 c);

        /*
        *  Description: Given a sphere, find theh ambience color based on scene charactaristics
        *  Use: Used as a helper function in the main execution program
        *  Input: Sphere `currSphere`
        *  Output: A `glm::vec3` vector representation of RGB color - the ambience color
        *  Throws: NA
        */
        static glm::vec3 ambient (Sphere* currSphere);

        /*
        *  Description: Given point `p` on the sphere, find the SUM of shadow rays color contribution at that point
        *  Use: Used as a helper function in the main execution program
        *  Input: Point `p` and Sphere `sphere` where point `p` can be found on
        *  Output: A `glm::vec3` vector representation of RGB color - the SUM of shadow rays color contribution at that point
        *  Throws: NA
        */
        static glm::vec3 sumShadowRays (glm::vec3 p, Sphere* currSphere, glm::vec3 N);

    private:
        /* Private constructor and helper methods */
        Execution();

        static const int MAX_DEPTH = 4; // Each ray has depth 4, meaning it can be reflected 3 times at most


};

#endif
