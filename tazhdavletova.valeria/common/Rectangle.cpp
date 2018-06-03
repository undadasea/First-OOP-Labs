#include <iostream>
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>
#include "Rectangle.h"

Rectangle::Rectangle(const point_t &rec_position, double width, double length) :
	Shape(rec_position),   //center
	m_width(width),
	m_length(length),
  m_angle(0)
{
	if (m_width < 0) {
		throw std::invalid_argument("Data is incorrect. It will be replaced by positive value.");
		m_width *= (-1);
	}
	if (m_width == 0) {
		throw std::invalid_argument("Data is incorrect. It will be replaced by 1.");
		m_width = 1;
	}
	if (m_length < 0) {
		throw std::invalid_argument("Data is incorrect. It will be replaced by positive value.");
		m_length *= (-1);
	}
	if (m_length == 0) {
		throw std::invalid_argument("Data is incorrect. It will be replaced by 1.");
		m_length = 1;
	}
}

double Rectangle::getArea() const
{
	return (m_width * m_length);
}

rectangle_t Rectangle::getFrameRect() const 
{
	if (m_angle == 0) {
	  rectangle_t m_framerect = { m_width, m_length, {m_position.x - m_width/2, m_position.y - m_length/2}}; //pos of FrameRect is left bottom
	  return m_framerect;
    }
    else {
      const point_t left_upper = {m_position.x - m_width/2, m_position.y + m_length/2};  
      const point_t left_bottom = {m_position.x - m_width/2, m_position.y - m_length/2};
      const point_t right_upper = {m_position.x + m_width/2, m_position.y + m_length/2};
      const point_t right_bottom = {m_position.x + m_width/2, m_position.y - m_length/2};

      const point_t new_left_upper = {((left_upper.x - m_position.x) * cos((m_angle * M_PI)/180)) - ((left_upper.y - m_position.y)* sin((m_angle * M_PI)/180)) + m_position.x,
        ((left_upper.x - m_position.x) * sin((m_angle * M_PI)/180)) + ((left_upper.y - m_position.y)* cos((m_angle * M_PI)/180)) + m_position.y};
      
      const point_t new_left_bottom = {((left_bottom.x - m_position.x) * cos((m_angle * M_PI)/180)) - ((left_bottom.y - m_position.y)* sin((m_angle * M_PI)/180)) + m_position.x, 
        ((left_bottom.x - m_position.x) * sin((m_angle * M_PI)/180)) + ((left_bottom.y - m_position.y)* cos((m_angle * M_PI)/180)) + m_position.y};
      
      const point_t new_right_upper = {((right_upper.x - m_position.x) * cos((m_angle * M_PI)/180)) - ((right_upper.y - m_position.y)* sin((m_angle * M_PI)/180)) + m_position.x, 
        ((right_upper.x - m_position.x) * sin((m_angle * M_PI)/180)) + ((right_upper.y - m_position.y)* cos((m_angle * M_PI)/180)) + m_position.y};

      const point_t new_right_bottom = {(right_bottom.x - m_position.x) * cos((m_angle * M_PI)/180) - (right_bottom.y - m_position.y)* sin((m_angle * M_PI)/180) + m_position.x, 
        (right_bottom.x - m_position.x) * sin((m_angle * M_PI)/180) + (right_bottom.y - m_position.y)* cos((m_angle * M_PI)/180) + m_position.y};

       double maxx = std::max(new_left_upper.x, std::max(new_left_bottom.x, std::max(new_right_upper.x, new_right_bottom.x)));
       double maxy = std::max(new_left_upper.y, std::max(new_left_bottom.y, std::max(new_right_upper.y, new_right_bottom.y)));
       double minx = std::min(new_left_upper.x, std::min(new_left_bottom.x, std::min(new_right_upper.x, new_right_bottom.x)));
       double miny = std::min(new_left_upper.y, std::min(new_left_bottom.y, std::min(new_right_upper.y, new_right_bottom.y)));

      rectangle_t FrameRect = {fabs(maxx - minx), fabs(maxy - miny), {m_position.x - fabs(maxx - minx)/2, m_position.y - fabs(maxy - miny)/2}};

      return FrameRect;
    }
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
  	throw std::invalid_argument("Coefficient should not be zero.");
  }
}

void Rectangle::rotate(double degree)
{   
  if (m_angle == 0) {
    m_angle = degree;
  }
  else {
    m_angle += degree;
  }
  while (m_angle >= 360) {
    m_angle -= 360;
  }
  while (m_angle < 0) {
    m_angle += 360;
  }
}


