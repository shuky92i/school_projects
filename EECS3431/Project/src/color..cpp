#include "color.hpp"
#include "utility.hpp"

Color::Color()
{
    this->m_r = 0;
    this->m_g = 0;
    this->m_b = 0;
}

Color::Color(double color_r, double color_g, double color_b)
{
    double normalized_color_r = color_r;
    double normalized_color_g = color_g;
    double normalized_color_b = color_b;

    // If one value is larger than 1, divide all values by that value
    double max = Utility::getMax3(color_r, color_g, color_b);
    if (max > 1)
    {
        normalized_color_r = normalized_color_r / max;
        normalized_color_g = normalized_color_g / max;
        normalized_color_b = normalized_color_b / max;
    }

    this->m_r = normalized_color_r * 255;
    this->m_g = normalized_color_g * 255;
    this->m_b = normalized_color_b * 255;
}
