#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>
#include "space.hpp"
#include "glm-master/glm/glm.hpp"

class Utility
{
    public:
        /*
        *  Description: Throws a `std::invalid_argument` exception
        *  Use: Whenever we want to throw a `std::invalid_argument` exception with given value string
        *  Input: A string to be outputted with the exception (accessible using `e.what()`)
        *  Output: NA
        *  Throws: a `std::invalid_argument` exception
        */
       static void throwInvalidArgumentException(std::string exceptionString);

        /*
        *  Description: checks whether a given `double` is between 0 and 1 (inclusive)
        *  Use: while processing user input in `processInputLineVector`
        *  Input: A number of type `double`
        *  Output: True if input is between 0 and 1 (inclusive). False otherwise
        *  Throws: NA
        */
       static bool isBetweenZeroAndOne(double num);

        /*
        *  Description: Collects input information from given input file
        *  Use: To be called from main()
        *  Input: A string representing the file name in current directory
        *  Output: NA
        *  Throws: `std::invalid_argument` exception if one of the inputs is invalid (raised by `processInputLineVector`)
        */
        static void collectInputs (std::string fileNmae);

        /*
        *  Description: Calculat direction vector of the intial eye-pixel ray
        *  Use: Used for spawning rays between eye and a pixel on the NEAR plane
        *  Input: The coordinates of the pixel on the NEAR plane
        *  Output: A `glm::vec4` representing The direction vector of the eye-pixel ray
        *  Throws: NA
        */
        static glm::vec3 findEyeToPixelDirectionVector (int colPoxel, int rowPixel);

        /*
        *  Description: Calculat the max of 3 numbers
        *  Use: To normilize Color attributes in class colors
        *  Input: 3 double numbers
        *  Output: The max of those 3
        *  Throws: NA
        */
        static double getMax3 (double n1, double n2, double n3);


        /*
        *  Description: Calculat the min of 2 numbers
        *  Use: To find the smaller t between two solutions to the quadratic equation
        *  Input: 2 double numbers
        *  Output: The min of those 2
        *  Throws: NA
        */
        static double getMin2 (double n1, double n2);

        /*
        *  Description: Calculat the max of 2 numbers
        *  Use: To find the larger t between two solutions to the quadratic equation
        *  Input: 2 double numbers
        *  Output: The max of those 2
        *  Throws: NA
        */
        static double getMax2 (double n1, double n2);

        /*
        *  Description: prints a matrix to cout for debugging purposes
        *  Use: From anywhere
        *  Input: `glm::mat4`
        *  Output: NA
        *  Throws: `NA
        */
        static void debugPrintMat4 (glm::mat4 mat4);

        /*
        *  Description: prints a vector to cout for debugging purposes
        *  Use: From anywhere
        *  Input: `glm::vec4`
        *  Output: NA
        *  Throws: `NA
        */
        static void debugPrintVec4 (glm::vec4 vec4);

        /*
        *  Description: prints a vector to cout for debugging purposes
        *  Use: From anywhere
        *  Input: `glm::vec4`
        *  Output: NA
        *  Throws: `NA
        */
        static void debugPrintVec3 (glm::vec3 vecvec34);

    private:
        /* Private constructor to prevent creating new instances */
        Utility();

        /*
        *  Description: Takes the information given in the vector and creates the relevant C++ objects
        *  Use: Acting as a helper function to the public function `collectInputs`
        *  Input: A C++ vector containing individual words in the line
        *  Output: NA
        *  Throws: `std::invalid_argument` exception if one of the inputs is invalid (Exception origin)
        */
       static void processInputLineVector(std::vector<std::string> lineAsVector);

        /*
        *  Description: Turns a line into a C++ Vector of individual words
        *  Use: Acting as a helper function to the public function `collectInputs`
        *  Input: A string representing a line
        *  Output: A C++ vector containing individual words in the line
        *  Throws: NA
        */
       static std::vector<std::string> lineToVectorOfWords(std::string line);  
};

#endif
