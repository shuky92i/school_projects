#include "space.hpp"

Space* Space::m_instance = NULL;

Space::Space() 
{
    this->m_camera = new Camera();
    this->m_image = new Image();
}

Space* Space::getInstance () 
{
    if (Space::m_instance == NULL)
    {
        Space::m_instance = new Space();
    }
    return Space::m_instance;
}

void Space::debugPrintState()
{
    Space* space = Space::getInstance();

    // NEAR
    std::cout << "- NEAR" << std::endl;
    std::cout << "    " << space->m_near_plane << std::endl;

    // LEFT
    std::cout << "- LEFT" << std::endl;
    std::cout << "    " << space->m_left << std::endl;

    // RIGHT
    std::cout << "- RIGHT" << std::endl;
    std::cout << "    " << space->m_right << std::endl;

    // BOTTOM
    std::cout << "- BOTTOM" << std::endl;
    std::cout << "    " << space->m_bottom << std::endl;

    // TOP
    std::cout << "- TOP" << std::endl;
    std::cout << "    " << space->m_top << std::endl;

    // RES
    std::cout << "- RES" << std::endl;
    std::cout << "    " << space->m_image->m_nColumns << std::endl;
    std::cout << "    " << space->m_image->m_nRows << std::endl;

    // SPHERE
    std::cout << "- SPHERE" << std::endl;
    for (Sphere* sphere : space->m_spheres) {
        std::cout << "  -" << sphere->m_name << " ";
        std::cout << "    " << sphere->m_posX << " ";
        std::cout << "    " << sphere->m_posY << " ";
        std::cout << "    " << sphere->m_posZ << " ";
        std::cout << "    " << sphere->m_scaleX << " ";
        std::cout << "    " << sphere->m_scaleY << " ";
        std::cout << "    " << sphere->m_scaleZ << " ";
        std::cout << "    " << sphere->m_color_r << " ";
        std::cout << "    " << sphere->m_color_g << " ";
        std::cout << "    " << sphere->m_color_b << " ";
        std::cout << "    " << sphere->m_k_a << " ";
        std::cout << "    " << sphere->m_k_d << " ";
        std::cout << "    " << sphere->m_k_s << " ";
        std::cout << "    " << sphere->m_k_r << " ";
        std::cout << "    " << sphere->m_spec_exp << std::endl;   
    }

    // LIGHT
    std::cout << "- LIGHT" << std::endl;
    for (Light* light : space->m_lights) {
        std::cout << "  -" << light->m_name << " ";
        std::cout << "    " << light->m_posX << " ";
        std::cout << "    " << light->m_posY << " ";
        std::cout << "    " << light->m_posZ << " ";
        std::cout << "    " << light->m_i_r << " ";
        std::cout << "    " << light->m_i_g << " ";
        std::cout << "    " << light->m_i_b << std::endl;   
    }

    // BACK
    std::cout << "- BACK" << std::endl;
    std::cout << "    " << space->m_background->m_color_r << std::endl;
    std::cout << "    " << space->m_background->m_color_g << std::endl;
    std::cout << "    " << space->m_background->m_color_b << std::endl;

    // BACK
    std::cout << "- OUTPUT" << std::endl;
    std::cout << "    " << space->m_output_file_name << std::endl;
    
}