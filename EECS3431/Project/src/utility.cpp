#include "utility.hpp"

Utility::Utility()
{}

void Utility::processInputLineVector( std::vector<std::string> lineAsVector)
{
    Space* space = Space::getInstance();

    if (lineAsVector[0] == "NEAR")
    {
        if (lineAsVector.size() == space->NEAR_ARG_COUNT + 1)
        {
            try
            {
                space->m_near_plane = std::stod(lineAsVector[1]);
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: NEAR input line is invalid");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: NEAR input line is invalid");
        }
    }

    else if (lineAsVector[0] == "LEFT")
    {
        if (lineAsVector.size() == space->LEFT_ARG_COUNT + 1)
        {
            try
            {
                space->m_left = std::stod(lineAsVector[1]);
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: LEFT input line is invalid");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: LEFT input line is invalid");
        }
    }

    else if (lineAsVector[0] == "RIGHT")
    {
        if (lineAsVector.size() == space->RIGHT_ARG_COUNT + 1)
        {
            try
            {
                space->m_right = std::stod(lineAsVector[1]);
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: RIGHT input line is invalid");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: RIGHT input line is invalid");
        }
    }

    else if (lineAsVector[0] == "BOTTOM")
    {
        if (lineAsVector.size() == space->BOTTOM_ARG_COUNT + 1)
        {
            try
            {
                space->m_bottom = std::stod(lineAsVector[1]);
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: BOTTOM input line is invalid");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: BOTTOM input line is invalid");
        }
        
    }

    else if (lineAsVector[0] == "TOP")
    {
        if (lineAsVector.size() == space->TOP_ARG_COUNT + 1)
        {
            try
            {
                space->m_top = std::stod(lineAsVector[1]);
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: TOP input line is invalid");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: TOP input line is invalid");
        }       
    }

    else if (lineAsVector[0] == "RES")
    {
        if (lineAsVector.size() == space->RES_ARG_COUNT + 1)
        {
            try
            {
                space->m_image = new Image(std::stoi(lineAsVector[1]), std::stoi(lineAsVector[2]));
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: RES input line is invalid");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: RES input line is invalid");
        }         
    }  

    else if (lineAsVector[0] == "SPHERE")
    {
        if (lineAsVector.size() == space->SPHERE_ARG_COUNT + 1)
        {
            try
            {
                Sphere* sphere = new Sphere
                (
                    lineAsVector[1], 
                    std::stod(lineAsVector[2]),
                    std::stod(lineAsVector[3]),
                    std::stod(lineAsVector[4]),
                    std::stod(lineAsVector[5]),
                    std::stod(lineAsVector[6]),
                    std::stod(lineAsVector[7]),
                    std::stod(lineAsVector[8]),
                    std::stod(lineAsVector[9]),
                    std::stod(lineAsVector[10]),
                    std::stod(lineAsVector[11]),
                    std::stod(lineAsVector[12]),
                    std::stod(lineAsVector[13]),
                    std::stod(lineAsVector[14]),
                    std::stoi(lineAsVector[15])
                );
                space->m_spheres.push_back(sphere);
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: SPHERE input line is invalid");
            }
            if (space->m_spheres.size() > space->MAX_SPHERE_COUNT)
            {
                Utility::throwInvalidArgumentException("Error: Too many SPHERE input lines");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: SPHERE input line is invalid");
        }   
    }

    else if (lineAsVector[0] == "LIGHT")
    {
        if (lineAsVector.size() == space->LIGHT_ARG_COUNT + 1)
        {
            try
            {
                Light* light = new Light
                (
                    lineAsVector[1], 
                    std::stod(lineAsVector[2]),
                    std::stod(lineAsVector[3]),
                    std::stod(lineAsVector[4]),
                    std::stod(lineAsVector[5]),
                    std::stod(lineAsVector[6]),
                    std::stod(lineAsVector[7])
                );
                space->m_lights.push_back(light);
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: LIGHT input line is invalid");
            }
            if (space->m_lights.size() > space->MAX_LIGHT_COUNT)
            {
                Utility::throwInvalidArgumentException("Error: Too many LIGHT input lines");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: LIGHT input line is invalid");
        }   
    }

    else if (lineAsVector[0] == "BACK")
    {
        if (lineAsVector.size() == space->BACK_ARG_COUNT + 1)
        {
            try
            {
                space->m_background = new Background
                (
                    std::stod(lineAsVector[1]), 
                    std::stod(lineAsVector[2]),
                    std::stod(lineAsVector[3])
                );
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: BACK input line is invalid");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: BACK input line is invalid");
        }         
    } 

    else if (lineAsVector[0] == "AMBIENT")
    {
        if (lineAsVector.size() == space->AMBIENT_ARG_COUNT + 1)
        {
            try
            {
                space->m_ambient = new Ambient
                (
                    std::stod(lineAsVector[1]), 
                    std::stod(lineAsVector[2]),
                    std::stod(lineAsVector[3])
                );
            }
            catch(const std::exception& e)
            {
                Utility::throwInvalidArgumentException("Error: AMBIENT input line is invalid");
            }
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: AMBIENT input line is invalid");
        }         
    } 

    else if (lineAsVector[0] == "OUTPUT")
    {
        if (lineAsVector.size() == space->OUTPUT_ARG_COUNT + 1)
        {
            if (lineAsVector[1].size() <= 20)
            {
                space->m_output_file_name = lineAsVector[1];
            }
            else
            {
                Utility::throwInvalidArgumentException("Error: OUTPUT input has more than 20 characters");
            }
            
        }
        else
        {
            Utility::throwInvalidArgumentException("Error: OUTPUT input line is invalid (Note: output file name cannot have any spaces)");
        }         
    }

    else
    {
        Utility::throwInvalidArgumentException("Error: Unknown input keyword: " + lineAsVector[0]);
    }
    
}

std::vector<std::string> Utility::lineToVectorOfWords(std::string line)
{
    std::istringstream iss(line);
    std::vector<std::string> wordsVector;
    for(std::string str ; iss >> str ; )
    {
        wordsVector.push_back(str);
    }
    return wordsVector;
}

void Utility::throwInvalidArgumentException( std::string exceptionString)
{
    throw std::invalid_argument(exceptionString);
}

bool Utility::isBetweenZeroAndOne(double num)
{
    if ((0 <= num) && (num <= 1))
    {
        return true;
    }
    return false;
}

void Utility::collectInputs (std::string fileNmae) 
{
    std::string line;
    std::ifstream myfile (fileNmae);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            // Skip empty lines if any
            if (line.size() > 0)
            {
                std::vector<std::string> lineWords = lineToVectorOfWords(line);
                try
                {
                    processInputLineVector(lineWords);
                }
                catch(const std::invalid_argument& e)
                {
                    throw std::invalid_argument(e.what());
                }
            }            
        }
        myfile.close();
    }

    else 
    {
        std::cout << "Unable to open file" << std::endl;
    }
}

glm::vec3 Utility::findEyeToPixelDirectionVector (int colPoxel, int rowPixel)
{
    Space* space = Space::getInstance();
    int W = space->m_right;
    int H = space->m_top;
    double cOverNcols = (double) colPoxel/space->m_image->m_nColumns;
    double rOverNrows = (double) rowPixel/space->m_image->m_nRows;

    glm::vec3 directionVec = 
        glm::vec1(-1 * space->m_near_plane) * space->m_camera->n +
        glm::vec1(W * (2 * cOverNcols - 1)) * space->m_camera->u + 
        glm::vec1(H * (2 * rOverNrows - 1)) * space->m_camera->v;

    return directionVec;
}

double Utility::getMax3 (double n1, double n2, double n3)
{
    if (n1 > n2)
    {
        if (n1 > n3)
        {
            return n1;
        }
        return n3;
    }
    else
    {
        if (n2 > n3)
        {
            return n2;
        }
        return n3;
    }
}

double Utility::getMin2 (double n1, double n2)
{
    if (n1 < n2)
    {
        return n1;
    }
    return n2;
}

double Utility::getMax2 (double n1, double n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    return n2;
}

/*
    Debug print functions
*/
void Utility::debugPrintMat4 (glm::mat4 mat4)
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            std::cout << mat4[c][r] << " ";
        }
        std::cout << std::endl;
    }
}

void Utility::debugPrintVec4 (glm::vec4 vec4) 
{
     for (int r = 0; r < 4; r++)
    {
        std::cout << vec4[r];
        if (r < 3)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void Utility::debugPrintVec3 (glm::vec3 vec3) 
{
     for (int r = 0; r < 3; r++)
    {
        std::cout << vec3[r];
        if (r < 2)
        {
            std::cout << ", ";
        }   
    }
}