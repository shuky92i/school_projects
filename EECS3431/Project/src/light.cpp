#include "light.hpp"
#include "utility.hpp"

Light::Light()
{
    this->m_name = "";
    this->m_posX = 0;
    this->m_posY = 0;
    this->m_posZ = 0;
    this->m_i_r = 0;
    this->m_i_g = 0;
    this->m_i_b = 0;
}

Light::Light
(
    std::string name,
    double posX,
    double posY,
    double posZ,
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
        this->m_name = name;
        this->m_posX = posX;
        this->m_posY = -1 * posY; // same reason as in the sphere
        this->m_posZ = posZ;
        this->m_i_r = i_r;
        this->m_i_g = i_g;
        this->m_i_b = i_b;
    } 
    
    else
    {
        Utility::throwInvalidArgumentException("Error: BACK input line is invalid");
    }
}

glm::vec3 Light::getPoint ()
{
    return glm::vec3(this->m_posX, this->m_posY, this->m_posZ);
}