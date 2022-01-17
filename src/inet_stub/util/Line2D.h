#include <math.h>

#ifndef vectorEV
#define vectorEV ev << "Line2D y=ax+b: "
#endif

typedef struct Line2D
{
    double a;
    double b;

    Line2D(double _a, double _b) : a(_a), b(_b) {}

    void print()
    {
        std::stringstream os;
        os << "(a,b)=(" << a << "," << b << ")\n";
    }

} Line2D;
