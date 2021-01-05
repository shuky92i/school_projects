#include "background.hpp"
#include "utility.hpp"

Background::Background()
{
    this->m_color_r = 0;
    this->m_color_g = 0;
    this->m_color_b = 0;
}

Background::Background
(
    double color_r, 
    double color_g,
    double color_b
)
{
    if 
    (
        (Utility::isBetweenZeroAndOne(color_r)) &&
        (Utility::isBetweenZeroAndOne(color_g)) &&
        (Utility::isBetweenZeroAndOne(color_b))
    )
    {
        this->m_color_r = color_r;
        this->m_color_g = color_g;
        this->m_color_b = color_b;
    }

    else
    {
        Utility::throwInvalidArgumentException("Error: BACK input line is invalid");
    }
    

    
}
