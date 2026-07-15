#include <iostream>
#include <vector>
#include <string>

#include "ascii_gen.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define WIDTH_CHAR 150 

std::vector<std::string> generate_ascii_portrait(const std::string& image_path) {
    int w, h, n;
    unsigned char *data = stbi_load(image_path.c_str(), &w, &h, &n, 1);
    if (!data) return {"[ Error ]"};

    //std::string ramp = " .:-=+*#%@";
    std::string ramp = "@%#*+=-:. ";
    
    std::vector<std::string> lines;
    int out_h = (int)(WIDTH_CHAR * 0.8f * ((float)h / w));

    for (int y = 0; y < out_h; y++) {
        std::string line = "";
        for (int x = 0; x < WIDTH_CHAR; x++) {
            int px = (int)((float)x / WIDTH_CHAR * w);
            int py = (int)((float)y / out_h * h);
            unsigned char b = data[py * w + px];
            
            line += ramp[9 - (b * 9 / 255)];
        }
        lines.push_back(line);
    }
    stbi_image_free(data);
    return lines;
}
