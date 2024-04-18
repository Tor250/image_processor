#include <algorithm>
#include <cmath>
#include <iostream>
#include "io/image_format.h"
#include "io/bmp.h"
#include "filters/grayscale.h"
#include "filters/crop.h"
#include "filters/negative.h"
#include "filters/sharpening.h"
#include "filters/edge_detection.h"
#include "filters/blur.h"
#include "filters/my_filter.h"
#include <stdexcept>
#include <string>
#include <sstream>

int main(int argc, const char *argv[]) {
    try {
        if (argc < 3) {
            throw std::runtime_error("I need more args! I need input path and output path.");
        }
        std::string str = argv[2];
        if (str.size() < 5 || str.substr(str.size() - 4, 4) != ".bmp") {
            throw std::runtime_error("Sorry, only .bmp output file.");
        }
        BMP image_format;
        std::string filename = argv[1];
        std::string save_filename = argv[2];
        Image image = image_format.Load(filename);
        Image newImage = image;
        for (int i = 3; i < argc; ++i) {
            str = argv[i];
            if (str == "-gs") {
                GrayScale filter;
                newImage = filter.Apply(newImage);
            } else if (str == "-crop") {
                if (argc - i < 3) {
                    throw std::runtime_error("I need width and height");
                }
                Crop filter;
                std::stringstream ss;
                str = argv[i + 1];
                ss << str;
                int arg1;
                ss >> arg1;
                ss.clear();
                str = argv[i + 2];
                ss << str;
                int arg2;
                ss >> arg2;
                ss.clear();
                if (arg1 <= 0 || arg2 <= 0) {
                    throw std::runtime_error("Incorredt width or height");
                }
                newImage = filter.Apply(newImage, arg1, arg2);
                i+=2;
            } else if (str == "-neg") {
                Negative filter;
                newImage = filter.Apply(newImage);
            } else if (str == "-sharp") {
                Sharpening filter;
                newImage = filter.Apply(newImage);
            } else if (str == "-edge") {
                if (argc - i < 2) {
                    throw std::runtime_error("I need threshold"); 
                }
                GrayScale filter;
                newImage = filter.Apply(newImage);
                double threshold;
                EdgeDetection filt;
                std::stringstream ss;
                str = argv[i + 1];
                ss << str;
                ss >> threshold;
                ss.clear();
                if (threshold < 0) {
                    newImage = filt.Apply(newImage, 0, 1);
                } else if (threshold > 1) {
                    newImage = filt.Apply(newImage, 1000000000, 0);
                } else {
                    newImage = filt.Apply(newImage, threshold * 1000000000, 0);
                }
                ++i;
            /*} Долго работает
            else if (str == "-blur") {
                if (argc - i < 2) {
                    throw std::runtime_error("I need sigma"); 
                }
                Blur filter;
                long double sigma;
                std::stringstream ss;
                str = argv[i + 1];
                ss << str;
                ss >> sigma;
                ss.clear();
                newImage = filter.Apply(newImage, sigma * 1000000000);
                ++i;*/
            } else if (str == "-fil") {
                MyFilter filter;
                newImage = filter.Apply(newImage);
            } else {
                throw std::runtime_error("Incorrect filter!");
            }
        }
        image_format.Save(newImage, save_filename);
    } catch (std::runtime_error r) {
        std::cout << r.what() << '\n';
    }
    return 0;
}