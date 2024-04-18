#include "data/image.h"

Image::Image() {}

Image::Image(std::size_t width, std::size_t height, const Pixel &fill_value) : width_(width), height_(height), data(width * height, fill_value) {}

std::size_t Image::GetWidth() const {
    return width_;
}

std::size_t Image::GetHeight() const {
    return height_;
}

void Image::SetPixel(std::size_t col, std::size_t row, const Pixel &pixel) {
    data[GetRepresentationDimension(col, row)] = pixel;
}

Pixel Image::GetPixel(std::size_t col, std::size_t row) const {
    return data[GetRepresentationDimension(col, row)];
}

std::size_t Image::GetRepresentationDimension(std::size_t col, std::size_t row) const {
    return row * width_ + col;
}