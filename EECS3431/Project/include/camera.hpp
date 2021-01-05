#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "glm-master/glm/glm.hpp"

class Camera
{
    public:
        /* Public constructors */
        Camera();

        /* Attribute members of Camera */
        glm::vec3 u;
        glm::vec3 v;
        glm::vec3 n;

        /*
        *  Description: Returns a glm::vec3 representing the position of the camera
        *  Use: From Execution class mathods
        *  Input: NA
        *  Output: Position of the camera in viewing coordinates
        *  Throws: `NA
        */
        glm::vec3 getEyeLoc();

        /*
        *  Description: Sets the position of the camera
        *  Use: From Execution class mathods
        *  Input: Coordinates of camera in raster view (pixel mode), they'll be converted to view coordinates
        *  Output: NA
        *  Throws: `NA
        */
        void setEyeLoc(int colPixel, int rowPix);

        /*
        *  Description: Adjusts the camera orientation so that it's looking directly at the given pixel coordinates
        *  Use: For precise calculation of the direction of the ray going from the eye towards each pixel
        *  Input: The pixel coordinates on the viewing plane
        *  Output: NA
        *  Throws: NA
        */
       void lookAt(int colPixel, int rowPix);  

    private:
        /* Private attributes */
        double posX;
        double posY;
        double posZ;
        const glm::vec3 up = glm::vec3(0, 1, 0);  
};

#endif
