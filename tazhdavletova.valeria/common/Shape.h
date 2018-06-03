#ifndef __SHAPE_H
#define __SHAPE_H
#include "base-types.h"

class Shape {
 public:
	Shape(const point_t &position);
	virtual ~Shape() = default;
	virtual double getArea() const = 0;
	virtual rectangle_t getFrameRect() const = 0;
	virtual void move(double x, double y);
	virtual void move(const point_t &position);
	virtual void scale(double coeff) = 0;
	virtual void rotate(double degree) = 0;
	virtual point_t getPosition() const;
	
protected:
	point_t m_position;
 };

#endif