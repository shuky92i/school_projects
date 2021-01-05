#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <iostream>

class Background
{
    public:
        /* Public constructors */
        Background();
        
        Background
        (
            double color_r, //between 0 and 1
            double color_g, //between 0 and 1
            double color_b //between 0 and 1
        );

        /* Attribute members of Light */
        double m_color_r; //between 0 and 1
        double m_color_g; //between 0 and 1
        double m_color_b; //between 0 and 1
};

#endif
