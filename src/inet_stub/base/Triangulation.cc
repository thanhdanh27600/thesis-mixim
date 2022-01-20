#include "assert.h"
#include "Triangulation.h"

Position Triangulation::position(const Coord &CenterA, const Coord &CenterB, double radiusA, double radiusB)
{
    double dAB = CenterA.distance(CenterB);

    if (dAB < radiusA + radiusB && dAB > radiusA && dAB > radiusB)
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

    case Position::CASE2A:
    case Position::CASE2B:
    case Position::CASE3A:
    case Position::CASE3B:
    case Position::CASE4A:
    case Position::CASE4B:
        pointRelativeRatio = radiusA / (radiusA + radiusB);

        pointX = pointRelativeRatio * (CenterB.x - CenterA.x) + CenterA.x;
        pointY = pointRelativeRatio * (CenterB.y - CenterA.y) + CenterA.y;

        return new Coord(pointX, pointY);

    case Position::INVALID:
    default:
        return new Coord();
    }
}

Coord *Triangulation::intersect(Line2D *line1, Line2D *line2)
{
    if (line1->a == line2->a)
    {
        if (line1->b != line2->b)
            throw "2 Lines are parrallel";
        else
            throw "2 Lines are identical";
    }
    if (line1->a == INFINITY)
    {
        return new Coord(line1->b, line1->b * line2->a + line2->b);
    }

    if (line2->a == INFINITY)
    {
        return new Coord(line2->b, line2->b * line1->a + line1->b);
    }

    double x = (line2->b - line1->b) / (line1->a - line2->a);
    double y = line1->a * x + line1->b;
    return new Coord(x, y);
}

Coord *Triangulation::centroid(Coord *a, Coord *b, Coord *c)
{
    return new Coord(1.0 / 3.0 * (a->x + b->x + c->x), 1.0 / 3.0 * (a->y + b->y + c->y));
}
