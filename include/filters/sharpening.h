#pragma once

#include "filters/filter.h"

class Sharpening: Filter {
public:
    Image Apply(Image& image, std::size_t arg1 = 0, std::size_t arg2 = 0) override;
};