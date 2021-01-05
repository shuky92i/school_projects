#include "ambient.hpp"
#include "utility.hpp"

Ambient::Ambient()
{
    this->m_i_r = 0;
    this->m_i_g = 0;
    this->m_i_b = 0;
}

Ambient::Ambient
(
    double i_r,
    double i_g,
    double i_b
) 
{
    if 
    (
        (Utility::isBetweenZeroAndOne(i_r)) &&
        (Utility::isBetweenZeroAndOne(i_g)) &&
        (Utility::isBetweenZeroAndOne(i_b))
    )
    {
        this->m_i_r = i_r;
        this->m_i_g = i_g;
        this->m_i_b = i_b;
    }

    else
    {
        Utility::throwInvalidArgumentException("Error: BACK input line is invalid");
    }
}
