
#include <Coord.h>
#include <triangulation.h>
#include <asserts.h>
#include <OmnetTestBase.h>
#include <Testcase.h>

/**
 * @brief Custom Assert
 *
 */
template <class T>
void assertLessThan(std::string msg, T target, T actual);

/**
 * Asserts that the passed value is less than to the passed expected
 * value. This is used for floating point variables.
 */
template <class T>
void assertLessThan(std::string msg, T target, T actual)
{
    if (target - actual > 0.0000001)
    {
        fail(msg, target, actual);
    }
    else
    {
        pass(msg);
    }
}

const double X_1 = 0.0;
const double Y_1 = 0.0;
const double Z_1 = 0.0;

const double X_2 = 8.0;
const double Y_2 = 0.0;
const double Z_2 = 0.0;

const double X_3 = 4.0;
const double Y_3 = 8.0;
const double Z_3 = 0.0;

const double X_a = 4.0;
const double Y_a = 3.0;
const double Z_a = 0.0;

Coord Center1(X_1, Y_1, Z_1);
Coord Center2(X_2, Y_2, Z_2);
Coord Center3(X_3, Y_3, Z_3);

Coord Actual(X_a, Y_a, Z_a);

struct Case1 case1;
struct Case2 case2;

Triangulation *triangulation = new Triangulation(Center1, Center2, Center3, case2.radius1, case2.radius2, case2.radius3);

/**
 * End testcase
 */

/**
 * Define test suite
 */

void testDistanceCase1()
{
    std::cout << "testDistanceCase1 starting...." << std::endl;

    Coord r1(0.0, 0.0, case1.radius1);

    Coord r2(0.0, 0.0, case1.radius2);

    Coord r3(0.0, 0.0, case1.radius3);

    assertClose("Case1: Radius Center1", Center1.distance(r1), case1.radius1);
    assertClose("Case1: Radius Center2", Center1.distance(r2), case1.radius2);
    assertClose("Case1: Radius Center3", Center1.distance(r3), case1.radius3);

    std::cout << "testDistanceCase1 successful." << std::endl
              << std::endl;
}

void testPositionCase1()
{
    std::cout << "testPositionCase1 starting...." << std::endl;

    assertClose("Case1: Actual->Center1 == Radius1", Actual.distance(Center1), case1.radius1);
    assertClose("Case1: Actual->Center2 == Radius2", Actual.distance(Center2), case1.radius2);
    assertClose("Case1: Actual->Center3 == Radius3", Actual.distance(Center3), case1.radius3);

    std::cout << "testPositionCase1 successful." << std::endl
              << std::endl;
}

void testDistanceCase2()
{
    std::cout << "testDistanceCase2 starting...." << std::endl;

    Coord r1(0.0, 0.0, case2.radius1);
    Coord r2(0.0, 0.0, case2.radius2);
    Coord r3(0.0, 0.0, case2.radius3);

    assertClose("Case2: Radius Center1", Center1.distance(r1), case2.radius1);
    assertClose("Case2: Radius Center2", Center1.distance(r2), case2.radius2);
    assertClose("Case2: Radius Center3", Center1.distance(r3), case2.radius3);

    std::cout << "testDistanceCase1 successful." << std::endl
              << std::endl;
}

void testLineCase2()
{
    std::cout << "testLineCase2 starting...." << std::endl;

    Line2D *linec1c2 = Center1.line2DThroughPoint(Center2);
    Line2D *linec2c3 = Center2.line2DThroughPoint(Center3);
    Line2D *linec3c1 = Center3.line2DThroughPoint(Center1);

    assertClose("Case2: Center1->Center2 line: y=ax+b, check \"a\"", linec1c2->a, 0.0);
    assertClose("Case2: Center1->Center2 line: y=ax+b, check \"b\"", linec1c2->b, 0.0);

    assertClose("Case2: Center2->Center3 line: y=ax+b, check \"a\"", linec2c3->a, -2.0);
    assertClose("Case2: Center2->Center3 line: y=ax+b, check \"b\"", linec2c3->b, 16.0);

    assertClose("Case2: Center3->Center1 line: y=ax+b, check \"a\"", linec3c1->a, 2.0);
    assertClose("Case2: Center3->Center1 line: y=ax+b, check \"b\"", linec3c1->b, 0.0);

    std::cout << "testLineCase2 successful." << std::endl
              << std::endl;
}

void testPositionCase2()
{
    std::cout << "testPositionCase2 starting...." << std::endl;

    assertClose("Case2: Center1<->Center2 position", (double)triangulation->position(Center1, Center2, case2.radius1, case2.radius2), (double)Position::CASE1);
    assertClose("Case2: Center2<->Center3 position", (double)triangulation->position(Center2, Center3, case2.radius2, case2.radius3), (double)Position::CASE1);
    assertClose("Case2: Center3<->Center1 position", (double)triangulation->position(Center3, Center1, case2.radius3, case2.radius1), (double)Position::CASE1);

    std::cout << "testPositionCase2 successful." << std::endl
              << std::endl;
}

void testMidpointCase2()
{
    std::cout << "testMidpointCase2 starting...." << std::endl;

    assertClose("Case2: Center1<->Center2 midpoint, test \"x\"", triangulation->midpoint(Center1, Center2, case2.radius1, case2.radius2)->x, 4.983125);
    assertClose("Case2: Center1<->Center2 midpoint, test \"y\"", triangulation->midpoint(Center1, Center2, case2.radius1, case2.radius2)->y, 0.0);

    assertClose("Case2: Center2<->Center3 midpoint, test \"x\"", triangulation->midpoint(Center2, Center3, case2.radius2, case2.radius3)->x, 6.14125);
    assertClose("Case2: Center2<->Center3 midpoint, test \"y\"", triangulation->midpoint(Center2, Center3, case2.radius2, case2.radius3)->y, 3.7175);

    assertClose("Case2: Center3<->Center1 midpoint, test \"x\"", triangulation->midpoint(Center3, Center1, case2.radius3, case2.radius1)->x, 2.252);
    assertClose("Case2: Center3<->Center1 midpoint, test \"y\"", triangulation->midpoint(Center3, Center1, case2.radius3, case2.radius1)->y, 4.504);

    std::cout << "testMidpointCase2 successful." << std::endl
              << std::endl;
}

void testPerpendicularLineCase2()
{
    std::cout << "testPerpendicularLineCase2 starting...." << std::endl;

    Coord *midpoint12 = triangulation->midpoint(Center1, Center2, case2.radius1, case2.radius2);
    Coord *midpoint23 = triangulation->midpoint(Center2, Center3, case2.radius2, case2.radius3);
    Coord *midpoint31 = triangulation->midpoint(Center3, Center1, case2.radius3, case2.radius1);

    Line2D *linec1c2 = Center1.line2DThroughPoint(Center2);
    Line2D *linec2c3 = Center2.line2DThroughPoint(Center3);
    Line2D *linec3c1 = Center3.line2DThroughPoint(Center1);

    assertClose("Case2: Center1<->Center2 perpendicularLine y=ax+b, test \"a\"", midpoint12->perpendicular(linec1c2)->a, (double)INFINITY);
    assertClose("Case2: Center1<->Center2 perpendicularLine y=ax+b, test \"b\"", midpoint12->perpendicular(linec1c2)->b, 4.983125);

    assertClose("Case2: Center1<->Center2 perpendicularLine y=ax+b, test \"a\"", midpoint23->perpendicular(linec2c3)->a, 0.5);
    assertClose("Case2: Center1<->Center2 perpendicularLine y=ax+b, test \"b\"", midpoint23->perpendicular(linec2c3)->b, 0.646875);

    assertClose("Case2: Center1<->Center2 perpendicularLine y=ax+b, test \"a\"", midpoint31->perpendicular(linec3c1)->a, -0.5);
    assertClose("Case2: Center1<->Center2 perpendicularLine y=ax+b, test \"b\"", midpoint31->perpendicular(linec3c1)->b, 5.63);

    std::cout << "testPerpendicularLineCase2 successful." << std::endl
              << std::endl;
}

class LocalizeTest : public SimpleTest
{
protected:
    void runTests()
    {
        std::cout << "===  Start testing... ===" << std::endl;

        /**
         * Case 1
         */

        testDistanceCase1();
        testPositionCase1();

        /**
         * Case 2
         */

        testDistanceCase2();
        testLineCase2();
        testPositionCase2();
        testMidpointCase2();
        testPerpendicularLineCase2();

        testsExecuted = true;
    }
};

Define_Module(LocalizeTest);
