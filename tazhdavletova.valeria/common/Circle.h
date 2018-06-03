#ifndef __CIRCLE_H
#define __CIRCLE_H
#include "base-types.h"
#include "Shape.h"

class Circle : public Shape 
{
public:
	Circle(double radius, const point_t &position);
	double getArea() const;
	rectangle_t getFrameRect() const;
	void scale(double coeff);
	void rotate(double degree);
	
	
private:
	double m_radius;
	double m_angle;
};


#endif
