#pragma once

#include "data/image.h"

class Filter {
public:
    Filter() = default;
    virtual ~Filter() = default;

    virtual Image Apply(Image& image, std::size_t arg1, std::size_t arg2) = 0;
};