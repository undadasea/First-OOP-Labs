#ifndef __TRIANGLE_H
#define __TRIANGLE_H
#include "base-types.h"
#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(const point_t &vertex_a, const point_t &vertex_b, const point_t &vertex_c);
	double getArea() const;
	rectangle_t getFrameRect() const;
	void scale(double coeff);
	point_t getPosition() const;

private:
	point_t m_a;
	point_t m_b;
	point_t m_c;
};


#endif