#include "filters/edge_detection.h"
#include <stdexcept>
#include <iostream>

Image EdgeDetection::Apply(Image& image, std::size_t arg1, std::size_t arg2) {
    int h = image.GetHeight();
    int w = image.GetWidth();
    float one = 1;
    float null = 0;
    float threshold = arg1;
    threshold /= 1000000000;
    threshold -= arg2;
    Image result = image;
    for(int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            Pixel p = image.GetPixel(i, j);
            p = p * 4;
            p = p + image.GetPixel(i, std::max(j - 1, 0)) * (-1);
            p = p + image.GetPixel(std::max(i - 1, 0), j) * (-1);
            p = p + image.GetPixel(std::min(i + 1, w - 1), j) * (-1);
            p = p + image.GetPixel(i, std::min(j + 1, h - 1)) * (-1);
            p.red = std::min(one, std::max(null, p.red));
            p.green = std::min(one, std::max(null, p.green));
            p.blue = std::min(one, std::max(null, p.blue));
            if (p.red > threshold) {
                p.red = 1;
                p.blue = 1;
                p.green = 1;
            } else {
                p.red = 0;
                p.blue = 0;
                p.green = 0;
            }
            result.SetPixel(i, j, p);
        }
    }
    return result;
}