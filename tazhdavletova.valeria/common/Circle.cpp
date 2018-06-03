#include "Circle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <stdexcept>

Circle::Circle(double radius, const point_t &position) :
    Shape(position), //center of circle
	m_radius(radius),
	m_angle(0)
	
{
	if (m_radius < 0) {
		throw std::invalid_argument ("Negative value will be replaced by positive one.");
		m_radius *= (-1);
	}
	if (0 == m_radius) {
		throw std::invalid_argument ("Value cannot be zero. It will be replaced by 1.");
		m_radius = 1;
	}
}

double Circle::getArea() const
{
	return (M_PI * m_radius * m_radius);
}

rectangle_t Circle::getFrameRect() const 
{ 
	point_t rect_position = {0,0};
	rect_position.x = m_position.x - m_radius;
	rect_position.y =  m_position.y - m_radius; 
	rectangle_t m_framerect = { m_radius * 2, m_radius * 2, rect_position };  //rect_pos - нижний левый угол
	return m_framerect;
}

void Circle::scale(double coeff)
{
	if (coeff < 0) {
		m_radius /= (-1 * coeff);
	}
	else if (coeff > 0) {
		m_radius *= coeff;
	}
	if (coeff == 0) {
		throw std::invalid_argument("Coefficient cannot be zero.");
	}
}

void Circle::rotate(double degree)
{
	m_angle = degree;
}
