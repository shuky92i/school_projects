#ifndef COLOR_HPP
#define COLOR_HPP

#include <vector>

class Color
{
    public:
        /* Public constructors */
        Color();
        
        Color(double color_r, double color_g, double color_b);

        /* Attribute members of Color */
        int m_r;
        int m_g;
        int m_b;

};

#endif
