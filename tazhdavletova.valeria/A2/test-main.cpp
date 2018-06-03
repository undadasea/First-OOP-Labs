#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include <cmath>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "base-types.h"

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(check_invalid_argument_circle)
{
	BOOST_CHECK_THROW(Circle(-3.0, {1.0,2.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(check_invalid_coefficient)
{
	Circle circle_(3.0, {1.0, 2.0});
	BOOST_CHECK_THROW(circle_.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(check_moving_point_t)
{
	Circle circle_(3.0, {1.0, 2.0});
    circle_.move({10.0, 10.0});
    BOOST_CHECK_EQUAL(circle_.getArea(), 3.0 * 3.0 * M_PI);
}

BOOST_AUTO_TEST_CASE(check_moving_double)
{
	Circle circle_(3.0, {1.0, 2.0});
    circle_.move(10.0, 10.0);
    BOOST_CHECK_EQUAL(circle_.getArea(), 3.0 * 3.0 * M_PI);
}

BOOST_AUTO_TEST_CASE(check_scale)
{
	Circle circle_(3.0, {1.0, 2.0});
	Circle circle_s(3.0, {1.0, 2.0});
	circle_s.scale(2.0);
	BOOST_CHECK_EQUAL(circle_s.getArea(), circle_.getArea() * 2.0 * 2.0);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(test_rectangle)

BOOST_AUTO_TEST_CASE(check_invalid_argument_rect)
{
    BOOST_CHECK_THROW(Rectangle({1.0, 1.0}, -2, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(check_moving_point_t)
{
	Rectangle rect_({1.0, 1.0}, 3.0, 2.0);
	rect_.move({10.0, 10.0});
	BOOST_CHECK_EQUAL(rect_.getArea(), 3.0 * 2.0);
}

BOOST_AUTO_TEST_CASE(check_moving_double)
{
	Rectangle rect_({1.0, 1.0}, 3.0, 2.0);
	rect_.move(10.0, 10.0);
	BOOST_CHECK_EQUAL(rect_.getArea(), 3.0 * 2.0);
}

BOOST_AUTO_TEST_CASE(check_scale)
{
	Rectangle rect_({1.0, 1.0}, 3.0, 2.0);
	Rectangle rect_s({1.0, 1.0}, 3.0, 2.0);
	rect_s.scale(2.0);
	BOOST_CHECK_EQUAL(rect_.getArea() * 2.0 * 2.0, rect_s.getArea());
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(test_triangle_)

BOOST_AUTO_TEST_CASE(test_arguments)
{
	BOOST_CHECK_THROW(Triangle({9.0, 1.0}, {9.0, 3.0}, {9.0, 4.0}), std::invalid_argument);
	BOOST_CHECK_THROW(Triangle({1.0, 9.0}, {2.0, 9.0}, {3.0, 9.0}), std::invalid_argument);
	BOOST_CHECK_THROW(Triangle({1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(check_moving_point_t)
{
	Triangle tri_({1.0, 3.0}, {3.0, 4.0}, {5.0, 6.0});
	Triangle tri_m({1.0, 3.0}, {3.0, 4.0}, {5.0, 6.0});
	tri_m.move({5.0, 5.0});
	BOOST_CHECK_EQUAL(tri_.getArea(), tri_m.getArea());
}

BOOST_AUTO_TEST_CASE(check_moving_double)
{
	Triangle tri_({1.0, 3.0}, {3.0, 4.0}, {5.0, 6.0});
	Triangle tri_m({1.0, 3.0}, {3.0, 4.0}, {5.0, 6.0});
	tri_m.move(5.0, 5.0);
	BOOST_CHECK_EQUAL(tri_.getArea(), tri_m.getArea());
}

BOOST_AUTO_TEST_SUITE_END()