#include "FWMath.h"
#include "Coord.h"

enum class Position
{
    CASE1,
    CASE2A,
    CASE2B,
    CASE3A,
    CASE3B,
    CASE4A,
    CASE4B,
    INVALID
};

class Triangulation
{

public:
    /** @name Center1, Center2 and Center3 coordinates of the 3 circles with corresponding radius */
    /*@{*/
    Coord Center1;
    Coord Center2;
    Coord Center3;

    double radius1;
    double radius2;
    double radius3;

    double area;
    /*@}*/

public:
    /** @name Constructor, simply includes all attr */
    Triangulation(Coord _Center1, Coord _Center2, Coord _Center3, double _radius1, double _radius2, double _radius3) : Center1(_Center1), Center2(_Center2), Center3(_Center3), radius1(_radius1), radius2(_radius2), radius3(_radius3), area{-1} {}

    /** @name Constructor, with a list (n=3) */
    Triangulation(Coord *Center, double* Radius, unsigned int size = 3){
        Center1 = Center[0];
        Center2 = Center[1];
        Center3 = Center[2];
        radius1 = Radius[0];
        radius2 = Radius[1];
        radius3 = Radius[2];
    }

    /**
     * @brief Return the relative position of 2 circle
     *
     * @param CenterA
     * @param radiusA
     * @param CenterB
     * @param radiusB
     * @return Position
     */
    Position position(const Coord &CenterA, const Coord &CenterB, double radiusA, double radiusB);

    /**
     * @brief
     * Find the midpoint in the relative position of 2 circle is a step of Triangulation method, there will be a midpoint for each position.
     * @param CenterA
     * @param radiusA
     * @param CenterB
     * @param radiusB
     * @return Coord*
     */
    Coord *midpoint(const Coord &CenterA, const Coord &CenterB, double radiusA, double radiusB);

    /**
     * @brief Find the instersection coord of 2 lines
     *
     * @param line1
     * @param line2
     * @return Coord*
     */
    Coord *intersect(Line2D *line1, Line2D *line2);

    /**
     * @brief Find the centroid of a triangle with 3 point provided
     * 
     * @param a 
     * @param b 
     * @param c 
     * @return Coord* 
     */
    Coord *centroid(Coord *a, Coord *b, Coord *c);

    Coord predict();

private:
};
