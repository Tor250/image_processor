#pragma once

#include "data/pixel.h"
#include <vector>

class Image {
public:
    Image();

    Image(std::size_t width, std::size_t height, const Pixel &fill_value = {});

    std::size_t GetWidth() const;
    std::size_t GetHeight() const;

    void SetPixel(std::size_t col, std::size_t row, const Pixel& pixel);
    Pixel GetPixel(std::size_t col, std::size_t row) const;

private:
    std::size_t width_;
    std::size_t height_;
    std::vector<Pixel> data;

    std::size_t GetRepresentationDimension(std::size_t col, std::size_t row) const;
};