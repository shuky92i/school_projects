#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include "image.hpp"
#include "sphere.hpp"
#include "light.hpp"
#include "background.hpp"
#include "ambient.hpp"
#include "camera.hpp"

class Space
{
    private:
        /* Private constructor to prevent creating new instances */
        Space();

        /* Stored Space instance (singleton) */
        static Space* m_instance;

    public:
        /* Application constant specification */
        const static int MAX_SPHERE_COUNT = 15;
        const static int MAX_LIGHT_COUNT = 10;
        const static int NEAR_ARG_COUNT = 1;
        const static int LEFT_ARG_COUNT = 1;
        const static int RIGHT_ARG_COUNT = 1;
        const static int BOTTOM_ARG_COUNT = 1;
        const static int TOP_ARG_COUNT = 1;
        const static int RES_ARG_COUNT = 2;
        const static int SPHERE_ARG_COUNT = 15;
        const static int LIGHT_ARG_COUNT = 7;
        const static int BACK_ARG_COUNT = 3;
        const static int AMBIENT_ARG_COUNT = 3;
        const static int OUTPUT_ARG_COUNT = 1;

         /* Attribute members of the Space singleton */
        double m_near_plane;
        double m_left;
        double m_right;
        double m_top;
        double m_bottom;
        Image* m_image;
        std::vector<Sphere*> m_spheres;
        std::vector<Light*> m_lights;
        Background* m_background;
        Ambient* m_ambient;
        std::string m_output_file_name; // limited to 20 characters with no spaces

        Camera* m_camera;

        /* Static access method */
        static Space* getInstance();

        static void debugPrintState();
};

#endif
