#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <iostream>
#include "glm-master/glm/glm.hpp"

class Light
{
    public:
        /* Public constructors */
        Light();
        
        Light
        (
            std::string name,
            double posX,
            double posY,
            double posZ,
            double i_r, //between 0 and 1
            double i_g, //between 0 and 1
            double i_b //between 0 and 1
        );

        /* Attribute members of Light */
        std::string m_name;
        double m_posX;
        double m_posY;
        double m_posZ;
        double m_i_r; //between 0 and 1
        double m_i_g; //between 0 and 1
        double m_i_b; //between 0 and 1

 
        /*
        *  Description: Returns light coordinates as a `glm::vec3`
        *  Use: Used to ease up calculations
        *  Input: NA
        *  Output: A `glm::vec3` representing L
        *  Throws: NA
        */
        glm::vec3 getPoint ();

};

#endif
