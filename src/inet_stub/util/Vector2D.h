#include <math.h>

#ifndef vectorEV
#define vectorEV ev << "Vector2D: "
#endif

typedef struct Vector2D
{
    double x;
    double y;

    Vector2D(double _x, double _y) : x(_x), y(_y) {}

    void print() {
        std::stringstream os;
        os << "(x,y)=(" << x << "," << y << ")\n";
    }

} Vector2D;
