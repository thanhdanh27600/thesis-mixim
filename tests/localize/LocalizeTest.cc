
#include <Coord.h>
#include <asserts.h>
#include <OmnetTestBase.h>

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

/**
 * @brief
 * testcase
 */

struct Case1
{
    const double radius1 = 5.0;
    const double radius2 = 5.0;
    const double radius3 = 5.0;

    const double X_p = 4.0;
    const double Y_p = 3.0;
    const double Z_p = 0.0;
};

struct Case2
{
    const double radius1 = 6.7;
    const double radius2 = 5.9;
    const double radius3 = 5.4;

    double X_p = 5.0;
    double Y_p = 3.1;
    double Z_p = 0.0;
};

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

void testPositionCase2()
{
    std::cout << "testPositionCase2 starting...." << std::endl;

    assertLessThan("Case2: Center1->Center2 < Radius1 + Radius2", Center1.distance(Center2), case1.radius1 + case1.radius2);
    assertLessThan("Case2: Center2->Center3 < Radius2 + Radius3", Center2.distance(Center3), case1.radius2 + case1.radius3);
    assertLessThan("Case2: Center3->Center1 < Radius2 + Radius3", Center3.distance(Center1), case1.radius2 + case1.radius3);

    std::cout << "testPositionCase2 successful." << std::endl
              << std::endl;
}

void testLineCase2()
{
    std::cout << "testLineCase2 starting...." << std::endl;

    Line2D *linec1c2 = Center1.line2DthroughPoint(Center2);
    Line2D *linec2c3 = Center2.line2DthroughPoint(Center3);
    Line2D *linec3c1 = Center3.line2DthroughPoint(Center1);

    assertEqual("Case2: Center1->Center2 line: y=ax+b, check \"a\"", linec1c2->a, 0.0);
    assertEqual("Case2: Center1->Center2 line: y=ax+b, check \"b\"", linec1c2->b, 0.0);

    assertEqual("Case2: Center2->Center3 line: y=ax+b, check \"a\"", linec2c3->a, -2.0);
    assertEqual("Case2: Center2->Center3 line: y=ax+b, check \"b\"", linec2c3->b, 16.0);

    assertEqual("Case2: Center3->Center1 line: y=ax+b, check \"a\"", linec3c1->a, 2.0);
    assertEqual("Case2: Center3->Center1 line: y=ax+b, check \"b\"", linec3c1->b, 0.0);

    std::cout << "testLineCase2 successful." << std::endl
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
        testPositionCase2();
        testLineCase2();

        testsExecuted = true;
    }
};

Define_Module(LocalizeTest);
