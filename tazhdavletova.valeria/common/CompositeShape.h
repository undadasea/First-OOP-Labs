#ifndef _COMPOSITE_SHAPE_H_
#define _COMPOSITE_SHAPE_H_
#include "base-types.h"
#include "Shape.h"
#include <memory>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class CompositeShape {
  public:
  	CompositeShape(Shape *); 
    void addFigure(Shape *);
    double getArea() const;
    rectangle_t getFrameRect();
    void move(double dx, double dy);
    void move(point_t new_position);
    void scale(double coeff);
    void rotate(double degree);
  protected:
  	unique_ptr<Shape*[]> m_shapes;
  	size_t m_size;
  	double m_x, m_y;
    double m_angle;
};

#endif