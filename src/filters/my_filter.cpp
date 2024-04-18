#include "filters/my_filter.h"
#include <algorithm>
#include <stdexcept>

Image MyFilter::Apply(Image& image, std::size_t arg1, std::size_t arg2) {
    if (arg1 != 0 || arg2 != 0) {
        throw std::runtime_error("This filter need 0 args");
    }
    int h = image.GetHeight();
    int w = image.GetWidth();
    float null = 0;
    float one = 1;
    Image result = image;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            Pixel p = image.GetPixel(i, j);
            p = p * 5;
            p = p + image.GetPixel(i, std::max(j - 1, 0)) * (-1);
            p = p + image.GetPixel(std::max(i - 1, 0), j) * (-1);
            p = p + image.GetPixel(std::min(i + 1, w - 1), j) * (-1);
            p = p + image.GetPixel(i, std::min(j + 1, h - 1)) * (-1);
            p = p * 24;
            p = p + image.GetPixel(i, std::max(j - 1, 0)) * (-7);
            p = p + image.GetPixel(std::max(i - 1, 0), j) * (-8);
            p = p + image.GetPixel(std::min(i + 1, w - 1), j) * (-2);
            p = p + image.GetPixel(i, std::min(j + 1, h - 1)) * (-7);
            p.red = p.red / (p.red + 1);
            p.blue = p.blue / (p.blue + 1);
            p.green = p.green / (p.green + 1);
            result.SetPixel(i, j, p);
            p.red = std::min(one, std::max(null, p.red));
            p.green = std::min(one, std::max(null, p.green));
            p.blue = std::min(one, std::max(null, p.blue));
        }
    }
    return result;
}