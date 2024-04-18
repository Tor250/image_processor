#include "filters/blur.h"
#include <stdexcept>
#include <iostream>
#include <cmath>

Image Blur::Apply(Image& image, std::size_t arg1, std::size_t arg2) {
    if (arg2 != 0) {
        throw std::runtime_error("Blur need 1 arg");
    }
    double h = image.GetHeight();
    double w = image.GetWidth();
    double sigma = arg1;
    sigma /= 1000000000;
    Image result = image;
    sigma = sigma * sigma * 2;
    for (double i = 0; i < w; ++i) {
        for (double j = 0; j < h; ++j) {
            Pixel p = image.GetPixel(i, j);
            for (double x = 0; x < w; ++x) {
                Pixel p1 = image.GetPixel(i, j);
                double k = 1/(sigma * M_PI) * pow(M_E, -static_cast<double>((i-x)*(i-x)) / sigma);
                p.red += p1.red * k;
                p.blue += p1.blue * k;
                p.green += p1.green * k;
            }
            for (double y = 0; y < h; ++y) {
                Pixel p1 = image.GetPixel(i, j);
                double k = 1/(sigma * M_PI) * pow(M_E, -static_cast<double>((j-y)*(j-y)) / sigma);
                p.red += p1.red * k;
                p.blue += p1.blue * k;
                p.green += p1.green * k;
                }
            result.SetPixel(i, j, p);
        }
    }
    return result;
}