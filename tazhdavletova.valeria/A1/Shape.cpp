#include "Shape.h"
#include <iostream>

Shape::Shape(const point_t &position) :
	m_position(position) {}


void Shape::move(double x, double y) 
{
	m_position.x += x;
	m_position.y += y;
}

void Shape::move(point_t &position) 
{
	m_position= position;
}


