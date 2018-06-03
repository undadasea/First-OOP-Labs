#define BOOST_TEST_MAIN
#define __USE_MINGW_ANSI_STDIO 0
#include <boost/test/included/unit_test.hpp>
#include <boost/math/constants/constants.hpp>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "base-types.h"
#include "CompositeShape.h"
#include <iostream>
#include <stdexcept>

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
    BOOST_CHECK_EQUAL(circle_.getArea(), 3.0 * 3.0 * boost::math::constants::pi<double>());
}

BOOST_AUTO_TEST_CASE(check_moving_double)
{
	Circle circle_(3.0, {1.0, 2.0});
    circle_.move(10.0, 10.0);
    BOOST_CHECK_EQUAL(circle_.getArea(), 3.0 * 3.0 * boost::math::constants::pi<double>());
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
	Triangle tri_({1.0, 6.0}, {3.0, 4.0}, {5.0, 6.0});
	Triangle tri_m({1.0, 6.0}, {3.0, 4.0}, {5.0, 6.0});
	tri_m.move({5.0, 5.0});
	BOOST_CHECK_EQUAL(tri_.getArea(), tri_m.getArea());
}

BOOST_AUTO_TEST_CASE(check_moving_double)
{
	Triangle tri_({1.0, 6.0}, {3.0, 4.0}, {5.0, 6.0});
	Triangle tri_m({1.0, 6.0}, {3.0, 4.0}, {5.0, 6.0});
	tri_m.move(5.0, 5.0);
	BOOST_CHECK_EQUAL(tri_.getArea(), tri_m.getArea());
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(test_CompositeShape)

BOOST_AUTO_TEST_CASE(check_area)
{
    Triangle tri_({1.0, 6.0}, {3.0, 4.0}, {5.0, 6.0});
    Circle circle_(3.0, {2.0, 4.0});
    CompositeShape CompositeShape_(&tri_);
    CompositeShape_.addFigure(&circle_);
    const double area_tri = tri_.getArea();
    const double area_circle = circle_.getArea();
	BOOST_CHECK_EQUAL(CompositeShape_.getArea(), area_tri + area_circle);
}

BOOST_AUTO_TEST_CASE(check_invalid_argument)
{
    Circle circle_(3.0, {2.0, 4.0});
    CompositeShape CompositeShape_(&circle_);
    Shape *Figure = nullptr; 
    BOOST_CHECK_THROW(CompositeShape_.addFigure(Figure), std::invalid_argument);
    BOOST_CHECK_THROW(CompositeShape Composite_(Figure), std::invalid_argument);  
}

BOOST_AUTO_TEST_CASE(check_moving_double)
{
    Triangle tri_({1.0, 6.0}, {3.0, 4.0}, {5.0, 6.0});
    Circle circle_c(3.0, {2.0, 4.0});
    CompositeShape CompositeShape_(&tri_);
    CompositeShape_.addFigure(&circle_c);
    const double x = CompositeShape_.getFrameRect().pos.x;
    const double y = CompositeShape_.getFrameRect().pos.y;
    const double area = CompositeShape_.getArea();
    CompositeShape_.move(10,10);
    BOOST_CHECK_EQUAL(x + 10, CompositeShape_.getFrameRect().pos.x);
    BOOST_CHECK_EQUAL(y + 10, CompositeShape_.getFrameRect().pos.y);
    BOOST_CHECK_EQUAL(area, CompositeShape_.getArea());
}

BOOST_AUTO_TEST_CASE(check_scale)
{
    Triangle tri_({1.0, 6.0}, {3.0, 4.0}, {5.0, 6.0});
    Circle circle_c(3.0, {2.0, 4.0});
    CompositeShape CompositeShape_(&tri_);
    CompositeShape_.addFigure(&circle_c);
    CompositeShape_.scale(2);
    const double area_tri = tri_.getArea();
    const double area_circle = circle_c.getArea();
    BOOST_CHECK_EQUAL(area_circle + area_tri, CompositeShape_.getArea());
}

BOOST_AUTO_TEST_SUITE_END()