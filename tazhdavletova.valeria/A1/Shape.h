#ifndef __SHAPE_H
#define __SHAPE_H
#include "base-types.h"

class Shape {
 public:
	Shape(const point_t &position);
	virtual ~Shape() = default;
	virtual double getArea() const = 0;
	virtual rectangle_t getFrameRect() const = 0;
	void move(double x, double y);
	void move(point_t &position);
	
protected:
	point_t m_position;
 };

#endif