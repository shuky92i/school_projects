#include "quadratic_equation.hpp"

QuadraticEquation::QuadraticEquation()
{
    this->m_a = 0;
    this->m_b = 0;
    this->m_c = 0;
}

QuadraticEquation::QuadraticEquation(double a, double b, double c)
{
     this->m_a = a;
    this->m_b = b;
    this->m_c = c;   
}

std::vector<double> QuadraticEquation::getSolutions()
{
    std::vector<double> sols;
    double det = this->m_b*this->m_b -4*this->m_a*this->m_c;
    if (det == 0)
    {
        double x0 = (-1*this->m_b) / (2*this->m_a);
        sols.push_back(x0);
    }
    else if (det > 0)
    {
        double x0 = (-1*this->m_b + sqrt(det)) / (2*this->m_a);
        double x1 = (-1*this->m_b - sqrt(det)) / (2*this->m_a);
        sols.push_back(x0);
        sols.push_back(x1);
    }
    return sols;
}

void QuadraticEquation::debugPrintState()
{
    std::cout << "f(t) = ";
    std::cout << this->m_a << "*t^2";
    std::cout << " + ";
    std::cout << this->m_b << "*t";
    std::cout << " + ";
    std::cout << this->m_c;
    std::cout << std::endl;

    std::vector<double> sols = this->getSolutions();
    if (sols.size() == 2)
    {
        std::cout << "Solutions: ";
        std::cout << "t0 = " << sols[0] << ", ";
        std::cout << "t1 = " << sols[1];
    }
    else if (sols.size() == 1)
    {
        std::cout << "t0 = " << sols[0];
    }
    else
    {
        std::cout << "None";
    }
    std::cout << std::endl;
}