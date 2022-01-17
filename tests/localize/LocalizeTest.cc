
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

void testDistanceLocalizeCase1()
{
    std::cout << "testDistanceLocalizeCase1 starting...." << std::endl;

    struct Case1 case1;

    Coord Circle1(X_1, Y_1, Z_1);
    Coord r1(0.0, 0.0, case1.radius1);

    Coord Circle2(X_2, Y_2, Z_2);
    Coord r2(0.0, 0.0, case1.radius2);

    Coord Circle3(X_3, Y_3, Z_3);
    Coord r3(0.0, 0.0, case1.radius3);

    assertClose("Case1: Radius Circle1", Circle1.distance(r1), case1.radius1);
    assertClose("Case1: Radius Circle2", Circle1.distance(r2), case1.radius2);
    assertClose("Case1: Radius Circle3", Circle1.distance(r3), case1.radius3);

    std::cout << "testDistanceLocalizeCase1 successful." << std::endl
              << std::endl;
}

void testPositionLocalizeCase1()
{
    std::cout << "testPositionLocalizeCase1 starting...." << std::endl;

    struct Case1 case1;

    Coord Circle1(X_1, Y_1, Z_1);
    Coord Circle2(X_2, Y_2, Z_2);
    Coord Circle3(X_3, Y_3, Z_3);

    Coord Actual(X_a, Y_a, Z_a);

    assertClose("Case1: Actual->Circle1 == Radius1", Actual.distance(Circle1), case1.radius1);
    assertClose("Case1: Actual->Circle2 == Radius2", Actual.distance(Circle2), case1.radius2);
    assertClose("Case1: Actual->Circle3 == Radius3", Actual.distance(Circle3), case1.radius3);

    std::cout << "testPositionLocalizeCase1 successful." << std::endl
              << std::endl;
}

void testDistanceLocalizeCase2()
{
    std::cout << "testDistanceLocalizeCase2 starting...." << std::endl;

    struct Case2 case2;

    Coord Circle1(X_1, Y_1, Z_1);
    Coord r1(0.0, 0.0, case2.radius1);

    Coord Circle2(X_2, Y_2, Z_2);
    Coord r2(0.0, 0.0, case2.radius2);

    Coord Circle3(X_3, Y_3, Z_3);
    Coord r3(0.0, 0.0, case2.radius3);

    assertClose("Case2: Radius Circle1", Circle1.distance(r1), case2.radius1);
    assertClose("Case2: Radius Circle2", Circle1.distance(r2), case2.radius2);
    assertClose("Case2: Radius Circle3", Circle1.distance(r3), case2.radius3);

    std::cout << "testDistanceLocalizeCase1 successful." << std::endl
              << std::endl;
}

void testPositionLocalizeCase2()
{
    std::cout << "testPositionLocalizeCase2 starting...." << std::endl;

    struct Case1 case1;

    Coord Circle1(X_1, Y_1, Z_1);
    Coord Circle2(X_2, Y_2, Z_2);
    Coord Circle3(X_3, Y_3, Z_3);

    Coord Actual(X_a, Y_a, Z_a);

    assertLessThan("Case2: Circle1->Circle2 < Radius1 + Radius2", Circle1.distance(Circle2), case1.radius1 + case1.radius2);
    assertLessThan("Case2: Circle2->Circle3 < Radius2 + Radius3", Circle2.distance(Circle3), case1.radius2 + case1.radius3);
    assertLessThan("Case2: Circle3->Circle1 < Radius2 + Radius3", Circle3.distance(Circle1), case1.radius2 + case1.radius3);

    std::cout << "testPositionLocalizeCase2 successful." << std::endl
              << std::endl;
}

class LocalizeTest : public SimpleTest
{
protected:
    void runTests()
    {
        std::cout << "===  Start testing... ===" << std::endl;

        testDistanceLocalizeCase1();
        testPositionLocalizeCase1();

        testDistanceLocalizeCase2();
        testPositionLocalizeCase2();

        testsExecuted = true;
    }
};

Define_Module(LocalizeTest);
