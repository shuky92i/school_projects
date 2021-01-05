#ifndef AMBIENT_HPP
#define AMBIENT_HPP

#include <iostream>

class Ambient
{
    public:
        /* Public constructors */
        Ambient();
        
        Ambient
        (
            double i_r, //between 0 and 1
            double i_g, //between 0 and 1
            double i_b //between 0 and 1
        );

        /* Attribute members of Light */
        double m_i_r; //between 0 and 1
        double m_i_g; //between 0 and 1
        double m_i_b; //between 0 and 1
};

#endif
