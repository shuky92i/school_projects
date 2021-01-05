#include "sphere.hpp"
#include "utility.hpp"

Sphere::Sphere()
{
    this->m_name = "";
    this->m_posX = 0;
    this->m_posY = 0;
    this->m_posZ = 0;
    this->m_scaleX = 0;
    this->m_scaleY = 0;
    this->m_scaleZ = 0; 
    this->m_color_r = 0;
    this->m_color_g = 0;
    this->m_color_b = 0;
    this->m_k_a = 0;
    this->m_k_d = 0;
    this->m_k_s = 0;
    this->m_k_r = 0;
    this->m_spec_exp = 0;
}

Sphere::Sphere
(
    std::string name,
    double posX,
    double posY,
    double posZ,
    double scaleX,
    double scaleY,
    double scaleZ, 
    double color_r, 
    double color_g,
    double color_b,
    double k_a,
    double k_d,
    double k_s,
    double k_r,
    int spec_exp
) 
{
    if 
    (
        (Utility::isBetweenZeroAndOne(color_r)) &&
        (Utility::isBetweenZeroAndOne(color_g)) &&
        (Utility::isBetweenZeroAndOne(color_b)) &&
        (Utility::isBetweenZeroAndOne(k_a)) &&
        (Utility::isBetweenZeroAndOne(k_d)) &&
        (Utility::isBetweenZeroAndOne(k_s)) &&
        (Utility::isBetweenZeroAndOne(k_r))
    )
    {
        this->m_name = name;
        this->m_posX = posX;
        this->m_posY = -1 * posY; // The reason for this is that pixel(0,0) is top left, not bottom left - design choice
        this->m_posZ = posZ;
        this->m_scaleX = scaleX;
        this->m_scaleY = scaleY;
        this->m_scaleZ = scaleZ; 
        this->m_color_r = color_r;
        this->m_color_g = color_g;
        this->m_color_b = color_b;
        this->m_k_a = k_a;
        this->m_k_d = k_d;
        this->m_k_s = k_s;
        this->m_k_r = k_r;
        this->m_spec_exp = spec_exp;
        this->m_inverseTransMat = this->getInverseTransformationMatrix();
        this->m_inverseTransposeTransMat = glm::transpose(this->m_inverseTransMat);
    }

    else
    {
        Utility::throwInvalidArgumentException("Error: SPHERE input line is invalid");
    }
}


glm::mat4 Sphere::getInverseTransformationMatrix ()
{
    return glm::inverse(this->getTransformationMatrix());
}

glm::mat4 Sphere::getTransformationMatrix ()
{
    glm::mat4 scaleMat = this->getScaleMatrix();
    glm::mat4 transMat = this->getTranslationMatrix();
    return transMat * scaleMat;
}

glm::mat4 Sphere::getTranslationMatrix()
{
    glm::mat4 translationMat = glm::mat4
    (
        1, 0, 0, 0, // 1st column vector
        0, 1, 0, 0, // 2nd column vector
        0, 0, 1, 0, // 3rd column vector
        this->m_posX, this->m_posY, this->m_posZ, 1 // 4th column vector
    );
    return translationMat;
}

glm::mat4 Sphere::getScaleMatrix()
{
    glm::mat4 scaleMat = glm::mat4
    (
        this->m_scaleX, 0, 0, 0, // 1st column vector
        0, this->m_scaleY, 0, 0, // 2nd column vector
        0, 0, this->m_scaleZ, 0, // 3rd column vector
        0, 0, 0, 1 // 4th column vector
    );
    return scaleMat;
}
