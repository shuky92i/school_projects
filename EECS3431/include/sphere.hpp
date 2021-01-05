#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include "glm-master/glm/glm.hpp"

class Sphere
{
    public:
        /* Public constructor */
        Sphere();

        Sphere
        (
            std::string name,
            double posX,
            double posY,
            double posZ,
            double scaleX,
            double scaleY,
            double scaleZ, 
            double color_r, //between 0 and 1
            double color_g, //between 0 and 1
            double color_b, //between 0 and 1
            double k_a, //between 0 and 1
            double k_d, //between 0 and 1
            double k_s, //between 0 and 1
            double k_r, //between 0 and 1
            int spec_exp
        );

        /* Attribute members of Sphere */
        std::string m_name;
        double m_posX;
        double m_posY;
        double m_posZ;
        double m_scaleX;
        double m_scaleY;
        double m_scaleZ; 
        double m_color_r; //between 0 and 1
        double m_color_g; //between 0 and 1
        double m_color_b; //between 0 and 1
        double m_k_a; //between 0 and 1
        double m_k_d; //between 0 and 1
        double m_k_s; //between 0 and 1
        double m_k_r; //between 0 and 1
        int m_spec_exp;
        glm::mat4 m_inverseTransMat;
        glm::mat4 m_inverseTransposeTransMat;

        private:
        /*
        *  Description: Calculates the Inverse transformation Matrix to be applied on the ray
        *  Use: Used to inverse transform the ray to be intersected with the nanonical sphere
        *  Input: NA
        *  Output: A `glm::mat4` representing the Inverse transformation matrix to be applied on the ray
        *  Throws: NA
        */
        glm::mat4 getInverseTransformationMatrix ();

        /*
        *  Description: Calculates the transformation Matrix that brought the sphere into the state it is in now
        *  Use: Used to find the inverse transform matrix that shall be applied to an arbitrary ray intersecting
        *       an arbitrary sphere
        *  Input: NA
        *  Output: A `glm::mat4` representing the transformation matrix applied on this sphere
        *  Throws: NA
        */
        glm::mat4 getTransformationMatrix ();

        /*
        *  Description: Assembles the translation matrix applied this sphere
        *  Use: Used in calculation of the transformation matrix that brought the sphere from the canonical 
        *       form to where it is now
        *  Input: NA
        *  Output: A `glm::mat4` representing the translation matrix applied on this sphere
        *  Throws: NA
        */
        glm::mat4 getTranslationMatrix ();

        /*
        *  Description: Assembles the scale matrix applied on this sphere
        *  Use: Used in calculation of the transformation matrix that brought the sphere from the canonical 
        *       form to where it is now
        *  Input: NA
        *  Output: A `glm::mat4` representing the scale matrix applied on this sphere
        *  Throws: NA
        */
        glm::mat4 getScaleMatrix ();
};

#endif
