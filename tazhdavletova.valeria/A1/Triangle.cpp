#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(const point_t &vertex_a, const point_t &vertex_b, const point_t &vertex_c) :
	Shape({ (vertex_a.x + vertex_b.x + vertex_c.x)/3, (vertex_a.y + vertex_b.y + vertex_c.y)/3 }),
  m_a(vertex_a),
  m_b(vertex_b),
  m_c(vertex_c) {
  	if ((fabs(m_a.y - m_b.y))/fabs(m_a.x - m_b.x) == fabs(m_a.y - m_c.y)/fabs(m_a.x - m_c.x)) {
      std::cerr << "Points are lying on the same line";
  }
}

double Triangle::getArea() const
{
	double ab = sqrt(pow((m_a.x - m_b.x), 2.0) + pow((m_a.y - m_b.y), 2.0));
	double ac = sqrt(pow((m_a.x - m_c.x), 2.0) + pow((m_a.y - m_c.y), 2.0));
	double cb = sqrt(pow((m_c.x - m_b.x), 2.0) + pow((m_c.y - m_b.y), 2.0));

	double p = 0.5 * (ab + ac + cb);

	return (sqrt(p *(p - ab) * (p - ac) * (p - cb)));
  
}

rectangle_t Triangle::getFrameRect() const 
{
	point_t circle_center = {(-1)*((m_a.y - m_b.y)*(m_c.x * m_c.x + m_c.y * m_c.y) + (m_b.y - m_c.y)*(m_a.x * m_a.x + m_a.y * m_a.y)
	 + (m_c.y - m_a.y)*(m_b.x * m_b.x + m_b.y * m_b.y))/(2 * (m_a.x - m_b.x)*(m_c.y - m_a.y) - (m_a.y - m_b.y)*(m_c.x - m_a.x)) ,
	 ((m_a.x - m_b.x)*(m_c.x * m_c.x + m_c.y * m_c.y) + (m_b.x - m_c.x)*(m_a.x * m_a.x + m_a.y * m_a.y) + (m_c.x - m_a.x)*(m_b.x * m_b.x + m_b.y*m_b.y)/
	 (2* (m_a.x - m_b.x)*(m_c.y - m_a.y) - (m_a.y - m_b.y)*(m_c.x - m_a.x))) };

	 double radius_circle = sqrt(pow(circle_center.x - m_a.x, 2) + pow(circle_center.y - m_a.y, 2));

	rectangle_t m_frameRect = {2*radius_circle , 2*radius_circle, circle_center};

	return m_frameRect;
} 

point_t Triangle::getPosition() const
{
	return {(m_a.x + m_b.x + m_c.x)/3, (m_a.y + m_b.y + m_c.y)/3};
}

