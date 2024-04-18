#include "filters/grayscale.h"
#include <stdexcept>

Image GrayScale::Apply(Image& image, std::size_t arg1, std::size_t arg2)
{
    if (arg1 != 0 || arg2 != 0) {
        throw std::runtime_error("Grayscale need 0 args");
    }
    Image result = image;
    for (std::size_t i = 0; i < image.GetWidth(); ++i) {
        for (std::size_t j = 0; j < image.GetHeight(); ++j) {
            Pixel p = image.GetPixel(i, j);
            p.red = p.red * 0.114 + p.green * 0.587 + p.blue * 0.299;
            p.green = p.red;
            p.blue = p.red;
            result.SetPixel(i, j, p);
        }
    }
    return result;
}