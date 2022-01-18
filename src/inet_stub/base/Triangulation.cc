#include "assert.h"
#include "Triangulation.h"

Position Triangulation::position(const Coord &CenterA, const Coord &CenterB, double radiusA, double radiusB)
{
    double dAB = CenterA.distance(CenterB);

    if (dAB < radiusA + radiusB)
    {
        return Position::CASE1;
    }

    if (dAB > radiusA + radiusB)
    {
        return radiusA > radiusB ? Position::CASE2A : Position::CASE2B;
    }

    if (dAB < radiusA)
    {
        return dAB + radiusB > radiusA ? Position::CASE3A : Position::CASE4A;
    }

    if (dAB < radiusB)
    {
        return dAB + radiusA > radiusB ? Position::CASE3B : Position::CASE4B;
    }

    return Position::INVALID;
}

Coord *Triangulation::midpoint(const Coord &CenterA, const Coord &CenterB, double radiusA, double radiusB)
{
    Position pos = position(CenterA, CenterB, radiusA, radiusB);
    double dAB = CenterA.distance(CenterB);
    double pointRelativeRatio, pointX, pointY;

    switch (pos)
    {
    case Position::CASE1:
        pointRelativeRatio = 1.0 / 2.0 * (radiusA * radiusA - radiusB * radiusB + dAB * dAB) / (dAB * dAB);

        pointX = (1 - pointRelativeRatio) * CenterA.x + pointRelativeRatio * CenterB.x;
        pointY = (1 - pointRelativeRatio) * CenterA.y + pointRelativeRatio * CenterB.y;

        return new Coord(pointX, pointY);

    default:
        return new Coord();
    }
}

Coord *Triangulation::intersect(const Line2D &line1, const Line2D &line2)
{
    if (line1.a == line2.a)
    {
        if (line1.b != line2.b)
            throw "2 Lines are parrallel";
        else
            throw "2 Lines are identical";
    }
    double x = (line2.b - line1.b) / (line1.a - line2.a);
    double y = line1.a * x + line1.b;
    return new Coord(x, y);
}
