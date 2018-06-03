#include "base-types.h"
#include "Shape.h"
#include "CompositeShape.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <string>
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>

CompositeShape::CompositeShape (Shape *figure) : 
  m_shapes(new Shape*[1]),
  m_size(1),
  m_x(0),
  m_y(0),
  m_angle(0) 
  {
  	if (figure == nullptr) {
  	  throw std::invalid_argument("There is no figure.");
  	}
  	m_shapes[0] = figure;
    m_x = m_shapes[0] -> getPosition().x;
    m_y = m_shapes[0] -> getPosition().y;
  }

void CompositeShape::addFigure(Shape *figure)
{
   if (figure == nullptr) {
     throw std::invalid_argument("There is no figure.");
   }

   std::unique_ptr<Shape * []> m_array(new Shape * [m_size + 1]);
   for (size_t i = 0; i < m_size; i++) {
   	m_array[i] = m_shapes[i];
   }
   m_array[m_size++] = figure;

   m_shapes.swap(m_array);

   m_x = getFrameRect().pos.x;
   m_y = getFrameRect().pos.y;
}

double CompositeShape::getArea() const
{
	double CompositeArea = 0;
	for (size_t i = 0; i<m_size; i++) {
		CompositeArea += m_shapes[i]->getArea();
	}
	return CompositeArea;
}

rectangle_t CompositeShape::getFrameRect()
{
	double min_x, min_y, max_x, max_y = 0;
  min_x = m_shapes[0]->getFrameRect().pos.x;
  min_y = m_shapes[0]->getFrameRect().pos.y;
  max_x = m_shapes[0]->getFrameRect().pos.x + m_shapes[0]->getFrameRect().width;
  max_y = m_shapes[0]->getFrameRect().pos.y + m_shapes[0]->getFrameRect().length;
	for (size_t i = 1; i<m_size; i++) {
    if (min_x > m_shapes[i]->getFrameRect().pos.x) {
      min_x = m_shapes[i]->getFrameRect().pos.x;
    }
    if (min_y > m_shapes[i]->getFrameRect().pos.y) {
      min_y = m_shapes[i]->getFrameRect().pos.y;
    }
  }
  for (size_t i = 1; i<m_size; i++) {
    if (max_x < (m_shapes[i]->getFrameRect().pos.x + m_shapes[i]->getFrameRect().width)) {
      max_x = m_shapes[i]->getFrameRect().pos.x + m_shapes[i]->getFrameRect().width;
    }
    if (max_y < (m_shapes[i]->getFrameRect().pos.y + m_shapes[i]->getFrameRect().length)) {
      max_y = (m_shapes[i]->getFrameRect().pos.y + m_shapes[i]->getFrameRect().length);
    }
	}
  
  m_x = min_x + fabs(min_x - max_x) /2;
  m_y = min_y + fabs(min_y - max_y) /2;
  rectangle_t FrameRect = {fabs(min_x - max_x), fabs(min_y - max_y), {m_x, m_y}}; //FrameRect.pos is a center
  return FrameRect;
}

void CompositeShape::move(double dx, double dy)
{
  for(size_t i = 0; i < m_size; i++) {
    m_shapes[i]->move(dx, dy);
  }
}

void CompositeShape::move(point_t new_position)
{
   for(size_t i = 0; i < m_size; i++) {
      m_shapes[i]->move(new_position.x - m_x, new_position.y - m_y);
   } 
}

void CompositeShape::scale(double coeff)
{
  if(coeff == 0) {
  	throw std::invalid_argument("Coefficient cannot ba zero.");
  }	
  for(size_t i=0; i<m_size; i++) {
    m_shapes[i]->scale(coeff);
  }
}

void CompositeShape::rotate(double degree)
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

  for(size_t i=0; i<m_size; i++) {
    point_t centerShape = m_shapes[i]->getPosition();
    double x = centerShape.x - m_x;
    double y = centerShape.y - m_y;
    m_shapes[i]->move({(x * cos((m_angle * M_PI)/180)) - (y* sin((m_angle * M_PI)/180)) + m_x,
        (x * sin((m_angle * M_PI)/180)) + (y* cos((m_angle * M_PI)/180)) + m_y});
    m_shapes[i]->rotate(degree);
  }
}