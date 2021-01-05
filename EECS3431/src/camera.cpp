#include "camera.hpp"
#include "space.hpp"
#include "utility.hpp"

Camera::Camera()
{
    // Initial axis of camera allign with world axis
    this->u = glm::vec3(1, 0, 0);
    this->v = glm::vec3(0, 1, 0);
    this->n = glm::vec3(0, 0, 1);
}

glm::vec3 Camera::getEyeLoc()
{
    return glm::vec3(this->posX, this->posY, this->posZ);
}

void Camera::setEyeLoc(int colPixel, int rowPix)
{
    Space* space = Space::getInstance();
    this->posX = (double) colPixel/space->m_image->m_nColumns;
    this->posY = (double) rowPix/space->m_image->m_nRows;
    this->posZ = 0; 
    Utility::debugPrintVec3(glm::vec3(this->posX, this->posY, this->posZ)); std::cout << std::endl;
}

void Camera::lookAt(int colPixel, int rowPix)
{
    Space* space = Space::getInstance();
    double pixelXCoord = (double) colPixel/space->m_image->m_nColumns;
    double pixelYCoord = (double) rowPix/space->m_image->m_nRows;
    this->n = glm::vec3
    (
        this->posX - pixelXCoord,
        this->posY - pixelYCoord,
        posZ - (-1 * space->m_near_plane)
    );
    this->n = glm::normalize(this->n);
    this->u = glm::normalize(glm::cross(this->up, n));
    this->v = glm::normalize(glm::cross(n, u));

    if ((colPixel == 300) && (rowPix == 200))
    {
        std::cout << "(x,y) = (" << pixelXCoord << ", " << pixelYCoord << ")" << std::endl;
        std::cout << glm::dot(u, n); std::cout << std::endl;
        Utility::debugPrintVec3(this->u); std::cout << std::endl;
        Utility::debugPrintVec3(this->v); std::cout << std::endl;
        Utility::debugPrintVec3(this->n); std::cout << std::endl; std::cout << std::endl;
    }
    


}