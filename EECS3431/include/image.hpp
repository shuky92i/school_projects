#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include "color.hpp"
#include <iostream>

class Image
{
    public:
        /* Public constructors */
        Image();
        
        Image(int nRows, int nColumns);

        /* Attribute members of Image */
        int m_nColumns;
        int m_nRows;
        unsigned char* m_pixelsArray;

        void setPixel(int colIndex, int rowIndex, Color* pixelColor);

        /*
        *  Description: stores a given array of pixel colours (0-255) as a ppm image
        *  Use: Acting as a helper function to the public function `collectInputs`
        *  Input: Array of pixel colours (0-255)
        *  Output: ppm image names `fname`
        *  Throws: NA
        */
       void save_image();
};

#endif
