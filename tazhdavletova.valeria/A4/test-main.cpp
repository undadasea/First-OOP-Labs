#define BOOST_TEST_MAIN
#define __USE_MINGW_ANSI_STDIO 0
#include <boost/test/included/unit_test.hpp>
#include <boost/math/constants/constants.hpp>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "CompositeShape.h"
#include <iostream>

BOOST_AUTO_TEST_SUITE(test_Triangle_)

Triangle tri_({2, 3}, {2,6}, {6, 3});
const double area = tri_.getArea();
const point_t pos = tri_.getPosition();

BOOST_AUTO_TEST_CASE(check_rotate_constants)
{
    tri_.rotate(90);
    BOOST_CHECK_CLOSE(area, tri_.getArea(), 0.00001);
    BOOST_CHECK_EQUAL(pos.x, tri_.getPosition().x);
    BOOST_CHECK_EQUAL(pos.y, tri_.getPosition().y);
}

BOOST_AUTO_TEST_CASE(check_rotate_vertexes)
{
    BOOST_CHECK_CLOSE(4.33333, tri_.getVertexA().x, 0.01);
    BOOST_CHECK_CLOSE(2.66666, tri_.getVertexA().y, 0.01);
    BOOST_CHECK_CLOSE(1.33333, tri_.getVertexB().x, 0.01);
    BOOST_CHECK_CLOSE(2.66666, tri_.getVertexB().y, 0.01);
    BOOST_CHECK_CLOSE(4.33333, tri_.getVertexC().x, 0.01);
    BOOST_CHECK_CLOSE(6.66666, tri_.getVertexC().y, 0.01);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(test_Rectangle_)

Rectangle rect({2,2}, 3, 4);
const double area = rect.getArea();
const double width = rect.getFrameRect().width;
const double length = rect.getFrameRect().length;
const point_t pos = rect.getPosition();

BOOST_AUTO_TEST_CASE(check_rotate_constants)
{
   rect.rotate(90);
   BOOST_CHECK_EQUAL(area, rect.getArea());
   BOOST_CHECK_EQUAL(pos.x, rect.getPosition().x);
   BOOST_CHECK_EQUAL(pos.y, rect.getPosition().y);
}

BOOST_AUTO_TEST_CASE(check_rotate_)
{
   BOOST_CHECK_EQUAL(width, rect.getFrameRect().length);
   BOOST_CHECK_EQUAL(length, rect.getFrameRect().width);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(test_Circle_)

Circle circ(3, {3,3});
const point_t pos = circ.getPosition();

BOOST_AUTO_TEST_CASE(check_rotate_constants)
{
   circ.rotate(45);
   BOOST_CHECK_EQUAL(pos.x, circ.getPosition().x);
   BOOST_CHECK_EQUAL(pos.y, circ.getPosition().y);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(test_CompositeShape_)

Rectangle rect({2,2}, 3, 4);
Circle circ(2, {3,3});
CompositeShape Composite(&circ);

BOOST_AUTO_TEST_CASE(check_rotate_constants)
{
   Composite.addFigure(&rect);
   const point_t center = Composite.getFrameRect().pos;
   const double area = Composite.getArea();
   Composite.rotate(90);
   BOOST_CHECK_EQUAL(center.x, Composite.getFrameRect().pos.x);
   BOOST_CHECK_EQUAL(center.y, Composite.getFrameRect().pos.y);
   BOOST_CHECK_EQUAL(area, Composite.getArea());
}

BOOST_AUTO_TEST_CASE(check_rotate_)
{
  BOOST_CHECK_EQUAL(3.25, rect.getPosition().x);
  BOOST_CHECK_EQUAL(1.75, rect.getPosition().y);
  BOOST_CHECK_EQUAL(2.25, circ.getPosition().x);
  BOOST_CHECK_EQUAL(2.75, circ.getPosition().y);
}

BOOST_AUTO_TEST_SUITE_END()
