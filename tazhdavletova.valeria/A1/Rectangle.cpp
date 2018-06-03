#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(const point_t &rec_position, double width, double length) :
	Shape(rec_position),
	m_width(width),
	m_length(length)
{
	if (m_width < 0) {
		std::cerr << "Data is incorrect. It will be replaced by positive value.";
		m_width *= (-1);
	}
	if (m_width == 0) {
		std::cerr << "Data is incorrect. It will be replaced by 1.";
		m_width = 1;
	}
	if (m_length < 0) {
		std::cerr << "Data is incorrect. It will be replaced by positive value.";
		m_length *= (-1);
	}
	if (m_length == 0) {
		std::cerr << "Data is incorrect. It will be replaced by 1.";
		m_length = 1;
	}
}

double Rectangle::getArea() const
{
	return (m_width * m_length);
}

rectangle_t Rectangle::getFrameRect() const 
{
	rectangle_t m_framerect = { m_width, m_length, m_position };
	return m_framerect;
}

void Rectangle::scale(double coeff)
{
  if (coeff < 0) {
    m_length /= -coeff;
    m_width /= -coeff;
  }

  if (coeff > 0) {
  	m_length *= coeff;
  	m_width *= coeff;
  }

  if (coeff == 0) {
  	std::cerr << "Coefficient should not be zero.";
  	coeff = 1;
  }
}


