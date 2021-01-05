#ifndef QUADRATIC_EQUATION_HPP
#define QUADRATIC_EQUATION_HPP

#include <iostream>
#include <vector>
#include <math.h>

class QuadraticEquation
{
    public:
        /* Private constructor and helper methods */
        QuadraticEquation();
        QuadraticEquation(double a, double b, double c);

        /* Attribute members of QuadraticEquation */
        double m_a;
        double m_b;
        double m_c;

        /*
        *  Description: Find the solutions of the equation, if any
        *  Use: Used by Ray objects to find the intersection of that ray with the canonical sphere
        *  Input: NA
        *  Output: `Vector<double>` that of length 2, or length 1 (just 1 solution), or length 0 (no solution)
        *  Throws: NA
        */
        std::vector<double> getSolutions();

        /*
        *  Description: Prints a string representation of this quadratic equation
        *  Use: Debugging purposes
        *  Input: NA
        *  Output: NA
        *  Throws: NA
        */
        void debugPrintState();

};

#endif
