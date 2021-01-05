#include "image.hpp"
#include "space.hpp"

Image::Image()
{
    this->m_nRows = 0;
    this->m_nColumns = 0;
    this->m_pixelsArray = new unsigned char [3 * m_nColumns * m_nRows];
}

Image::Image(int nColumns, int nRows) 
{
    this->m_nColumns = nColumns;
    this->m_nRows = nRows;
    this->m_pixelsArray = new unsigned char [3 * m_nColumns * m_nRows];

    // Initialize the image as a white screen (design choice to assist with debugging)
    for (int i = 0; i < 3 * m_nColumns * m_nRows; i++)
    {
        this->m_pixelsArray[i] = 255;
    }
    
}

void Image::setPixel(int colIndex, int rowIndex, Color* pixelColor)
{
    this->m_pixelsArray[rowIndex*this->m_nColumns*3 + colIndex*3] = pixelColor->m_r;
    this->m_pixelsArray[rowIndex*this->m_nColumns*3 + colIndex*3+1] = pixelColor->m_g;
    this->m_pixelsArray[rowIndex*this->m_nColumns*3 + colIndex*3+2] = pixelColor->m_b;
}

void Image::save_image() {
    Space* space = Space::getInstance();

    FILE *fp;
    const int maxVal=255; 

    printf("Saving image %s: %d x %d\n", space->m_output_file_name.c_str() , this->m_nColumns, this->m_nRows);
    fp = fopen(space->m_output_file_name.c_str(), "wb");
    if (!fp) {
        printf("Unable to open file '%s'\n", space->m_output_file_name.c_str());
        return;
    }
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", this->m_nColumns, this->m_nRows);
    fprintf(fp, "%d\n", maxVal);

    for(int j = 0; j < this->m_nRows; j++) {
            fwrite(&this->m_pixelsArray[j*this->m_nColumns*3], 3, this->m_nColumns,fp);
    }

    fclose(fp);
}