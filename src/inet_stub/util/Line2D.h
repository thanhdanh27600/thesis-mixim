#include <math.h>

#ifndef lineEV
#define lineEV ev << "Line2D y=ax+b: "
#endif

#ifndef LINE2D_H
#define LINE2D_H
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

inline std::ostream &operator<<(std::ostream &os, const Line2D &line)
{
    return os << "(a,b)=(" << line.a << "," << line.b << ")\n";
}

#endif