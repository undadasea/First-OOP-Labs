#ifndef __RECTANGLE_H
#define __RECTANGLE_H
#include <iostream>
#include "base-types.h"
#include "Shape.h"


class Rectangle : public Shape{
public:
	Rectangle(const point_t &rec_position, double width, double length);
	double getArea() const;
	rectangle_t getFrameRect() const;
	void scale(double coeff);
	
private:
	double m_width;
	double m_length;
};

#endif

