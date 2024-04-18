#include "data/pixel.h"

Pixel operator/(const Pixel &p, float a) {
    return Pixel{
        p.red / a,
        p.green / a,
        p.blue / a,
    };
}

Pixel operator*(const Pixel &p, float a) {
    return Pixel{
        p.red * a,
        p.green * a,
        p.blue * a,
    };
}

Pixel operator*(const Pixel &p, Pixel a) {
    return Pixel{
        p.red * a.red,
        p.green * a.green,
        p.blue * a.blue
    };
}

Pixel operator+(const Pixel &p, Pixel a) {
    return Pixel{
        p.red + a.red,
        p.green + a.green,
        p.blue + a.blue
    };
}