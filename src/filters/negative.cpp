#include "filters/negative.h"
#include <stdexcept>

Image Negative::Apply(Image& image, std::size_t arg1, std::size_t arg2) {
    if (arg1 != 0 || arg2 != 0) {
        throw std::runtime_error("Negative need 0 args");
    }
    Image result = image;
    for (std::size_t i = 0; i < result.GetWidth(); ++i) {
        for (std::size_t j = 0; j < result.GetHeight(); ++j) {
            Pixel p = image.GetPixel(i, j);
            p.red = 1 - p.red;
            p.green = 1 - p.green;
            p.blue = 1 - p.blue;
            result.SetPixel(i, j, p);
        }
    }
    return result;
}