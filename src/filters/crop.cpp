#include "filters/crop.h"
#include <algorithm>

Image Crop::Apply(Image& image, std::size_t arg1, std::size_t arg2) {
    std::size_t h = std::min(image.GetWidth(), arg1);
    std::size_t w = std::min(image.GetHeight(), arg2);
    Image result(h, w);
    for (std::size_t i = 0; i < h; ++i) {
        for (std::size_t j=0; j < w; ++j) {
            result.SetPixel(i, j, image.GetPixel(i, j + image.GetHeight() - w));
        }
    }
    return result;
}