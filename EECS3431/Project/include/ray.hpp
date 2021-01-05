#ifndef RAY_HPP
#define RAY_HPP

#include <iostream>
#include "glm-master/glm/glm.hpp"
#include "quadratic_equation.hpp"
#include "glm-master/glm/glm.hpp"

class Ray
{
    public:
        /* Public constructor */
        Ray(glm::vec3 startingPoint, glm::vec3 directionVector);

        /* Attribute members of Ray */
        glm::vec3 m_startingPoint;
        glm::vec3 m_directionVector;

        /*
        *  Description: Finds a point on the ray given a value t
        *  Use: Used in Execution calss to find the coordinates of the intersection point 
        *  Input: dobule value `t` representing the time desired
        *  Output: `glm::vec3` vector representing the desired point
        *  Throws: NA
        */
        glm::vec3 getPointOnRay(double t);

        /*
        *  Description: void time 0 which could lead to false intersections. Apply t = 0.000001
        *  Use: Used in Execution class to move the starting point of a ray so as to prevent false intersections
        *  Input: NA
        *  Output: `NA
        *  Throws: NA
        */
        void avoidTimeZero();

        /*
        *  Description: Find the intersection points of the ray with an arbitrary elipsoid in the scene.
        *  Use: Used in Execution class to beautify the code and make it mnore readable
        *  Input: The inverse of transofrmation matrix that brought the canonical sphere into what the current slipsoid is
        *  Output: `Vector<double>` that of length 2 (2 solutions), or length 1 (just 1 solution), or length 0 (no solution)
        *  Throws: NA
        */
        double getRayIntersectionTimeWithArbitraryElipsoid(glm::mat4 transMat);

        /*
        *  Description: Peeks the intersection points of the ray with an arbitrary elipsoid in the scene.
        *  Use: Used in Execution class to beautify the code and make it mnore readable
        *  Input: The inverse of transofrmation matrix that brought the canonical sphere into what the current slipsoid is
        *  Output: `true` if at least one point of intersection. `false` otherwise
        *  Throws: NA
        */
        bool peekIntersectionWithElipsoid(glm::mat4 inverseMat);

       /*
        *  Description: Prints a string representation of this array to `cout`
        *  Use: Debugging purposes
        *  Input: NA
        *  Output: NA
        *  Throws: NA
        */
        void debugPrintState();

    //private:
        /*
        *  Description: Find the intersection points of the ray with the canonical sphere, if any
        *  Use: Used in Execution class to beautify the code and make it mnore readable
        *  Input: NA
        *  Output: `Vector<double>` that of length 2 (2 solutions), or length 1 (just 1 solution), or length 0 (no solution)
        *  Throws: NA
        */
        std::vector<double> getIntersectionTimessWithCanonicalSphere();

        /*
        *  Description: Create a new ray similar to this one, inverse transform it and return it to caller
        *  Use: acting as helper function to find intersection with an arbitrary elipsoid
        *  Input: The inverse of transofrmation matrix that brought the canonical sphere into what the current slipsoid is
        *  Output: An inverse transformed ray
        *  Throws: NA
        */
        Ray* getTransformed(glm::mat4 transMat);

        Ray();
};

#endif
