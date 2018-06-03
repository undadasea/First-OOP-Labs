#ifndef __TRIANGLE_H
#define __TRIANGLE_H
#include "base-types.h"
#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(const point_t &vertex_a, const point_t& vertex_b, const point_t &vertex_c);
	double getArea() const;
	rectangle_t getFrameRect() const;
	void move (double x, double y);
	void move(point_t new_position);
	void scale(double coeff);
	void rotate(double degree);
	point_t getVertexA() const;
	point_t getVertexB() const;
	point_t getVertexC() const;

private:
	point_t m_a;
	point_t m_b;
	point_t m_c;
	double m_angle;
};


#endif