#include <iostream>
#include "glm-master/glm/glm.hpp"
#include <glm-master/glm/gtc/type_ptr.hpp>
#include "utility.hpp"
#include "execution.hpp"


int main(int argc, char* argv[]) 
{
    // argv[0] is program name, argv[1] is input file name
    if (argc == 2) 
    {
        try
        {
            Utility::collectInputs(argv[1]);
            Execution::runEngine();
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }   
    } 

    else if (argc < 2) {
        std::cout << "Too few arguments provided!" << std::endl;
    }

    else {
        std::cout << "Too many arguments provided!" << std::endl;
    }
    
    return 0;
}
