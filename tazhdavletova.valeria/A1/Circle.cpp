#include "Circle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

Circle::Circle(double radius, const point_t& position) :
    Shape(position),
	m_radius(radius)
{
	if (m_radius < 0) {
		std::cerr << "Data is incorrect. It will be replaced by positive value.";
		m_radius *= (-1);
	}
	if (0 == m_radius) {
		std::cerr << "Data is incorrect. It will be replaced by 1.";
		m_radius = 1;
	}
}

double Circle::getArea() const
{
	return (M_PI * m_radius * m_radius);
}

rectangle_t Circle::getFrameRect() const 
{
	rectangle_t m_framerect = { m_radius * 2, m_radius * 2, m_position };
	return m_framerect;
}

void Circle::scale(double coeff)
{
	if (coeff < 0) {
		m_radius /= -coeff;
	}

	else if (coeff > 0) {
		m_radius *= coeff;
	}
}

