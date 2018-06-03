#include "Triangle.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
using namespace std;

Triangle::Triangle(const point_t &vertex_a, const point_t &vertex_b, const point_t &vertex_c) :
	Shape({ (vertex_a.x + vertex_b.x + vertex_c.x)/3, (vertex_a.y + vertex_b.y + vertex_c.y)/3 }), //centroid
  m_a(vertex_a),
  m_b(vertex_b),
  m_c(vertex_c),
  m_angle(0) 
  {
  	if ((fabs(m_a.y - m_b.y))/fabs(m_a.x - m_b.x) == fabs(m_a.y - m_c.y)/fabs(m_a.x - m_c.x)) {
  		throw std::invalid_argument("Points are lying on the same line.");
  	}
  }

double Triangle::getArea() const
{
	double ab = sqrt(pow((m_a.x - m_b.x), 2.0) + pow((m_a.y - m_b.y), 2.0));
	double ac = sqrt(pow((m_a.x - m_c.x), 2.0) + pow((m_a.y - m_c.y), 2.0));
	double cb = sqrt(pow((m_c.x - m_b.x), 2.0) + pow((m_c.y - m_b.y), 2.0));

	double p = 0.5 * (ab + ac + cb);

	return (sqrt(p *(p - ab) * (p - ac) * (p - cb)));
  
}

rectangle_t Triangle::getFrameRect() const 
{
	point_t rect_position = {0,0};
	double width = 0;
	double length = 0;
	point_t corner_1, corner_2, corner_3, corner_4 = {0,0};

	if (fabs(m_a.x - m_b.x) > fabs(m_a.x - m_c.x)) {
	   if (fabs(m_a.x - m_b.x) > fabs(m_b.x - m_c.x)) {
	   	  width = fabs(m_a.x - m_b.x);
	   	  corner_1 = m_a;
	   	  corner_2 = m_b;;
	   }
	   else {
	   	  width = fabs(m_b.x - m_c.x);
	   	  corner_1 = m_b;
	   	  corner_2 = m_c;
	   }
	}
	else {
		if (fabs(m_a.x - m_c.x) > fabs(m_b.x - m_c.x)) {
	   	  width = fabs(m_a.x - m_c.x);
	   	  corner_1 = m_a;
	   	  corner_2 = m_c;
	   	}
	   	else {
	   	  width = fabs(m_b.x - m_c.x);
	   	  corner_1 = m_b;
	   	  corner_2 = m_c;
	   	}
    }
	if (fabs(m_a.y - m_b.y) > fabs(m_a.y - m_c.y)) {
	  if (fabs(m_a.y - m_b.y) > fabs(m_b.y - m_c.y)) { 
	    length = fabs(m_a.y - m_b.y);
	    corner_3 = m_a;
	    corner_4 = m_b;
	  }
	  else {
	  	length = fabs(m_b.y - m_c.y);
	  	corner_3 = m_b;
	  	corner_4 = m_c;
	  }
	}
	else {
      if (fabs(m_a.y - m_c.y) > fabs(m_b.y - m_c.y)) { 
     	length = fabs(m_a.y - m_c.y);
     	corner_3 = m_a;
     	corner_4 = m_c;
      }
   	  else {
   	  	length = fabs(m_b.y - m_c.y);
   	  	corner_3 = m_b;
   	  	corner_4 = m_c;
   	  }
   	}

  if ((corner_1.x == corner_3.x)&&(corner_1.y == corner_3.y)) {
  	rect_position = corner_1;
  }
  if ((corner_1.x == corner_4.x)&&(corner_1.y == corner_4.y)) {
  	rect_position = corner_1;
  }
  if ((corner_2.x == corner_3.x)&&(corner_2.y == corner_3.y)) {
  	rect_position = corner_2;
  }
  if ((corner_2.x == corner_4.x)&&(corner_2.y == corner_4.y)) {
  	rect_position = corner_2;
  }

  if ((rect_position.x == m_a.x) && (rect_position.y == m_a.y)) {
  	if ((rect_position.x >= m_b.x) && (rect_position.x >= m_c.x)) {     //so, m_a is right bottom or upper corner
      if ((rect_position.y >= m_b.y) && (rect_position.y >= m_c.y)) {  //so, m_a is right upper corner
       	rect_position.x -= width;
       	rect_position.y -= length;
       }
      else if ((rect_position.y <= m_b.y) && (rect_position.y <= m_c.y)) {  //m_a is right bottom corner
        rect_position.x -= width;
      }
    }
    else if ((rect_position.x <= m_b.x) && (rect_position.x <= m_c.x)) {    //then m_a is a left upper or bottom corner
      if ((rect_position.y >= m_b.y) && (rect_position.y >= m_c.y)) {       //m_a is a left upper corner
        rect_position.y -= length;
      }
    }
  }

  if ((rect_position.x == m_b.x)&&(rect_position.y == m_b.y)) {
  	if ((rect_position.x >= m_a.x) && (rect_position.x >= m_c.x)) {     //so, m_b is right bottom or upper corner
      if ((rect_position.y >= m_a.y) && (rect_position.y >= m_c.y)) {  //so, m_b is right upper corner
       	rect_position.x -= width;
       	rect_position.y -= length;
       }
      else if ((rect_position.y <= m_a.y) && (rect_position.y <= m_c.y)) {  //m_b is right bottom corner
        rect_position.x -= width;
      }
    }
    else if ((rect_position.x <= m_a.x) && (rect_position.x <= m_c.x)) {    //then m_b is a left upper or bottom corner
      if ((rect_position.y >= m_a.y) && (rect_position.y >= m_c.y)) {       //m_b is a left upper corner
        rect_position.y -= length;
      }
    }
  } 

  if ((rect_position.x == m_c.x)&&(rect_position.y == m_c.y)) {
  	if ((rect_position.x >= m_a.x) && (rect_position.x >= m_b.x)) {     //so, m_c is right bottom or upper corner
      if ((rect_position.y >= m_a.y) && (rect_position.y >= m_b.y)) {  //so, m_c is right upper corner
       	rect_position.x -= width;
       	rect_position.y -= length;
       }
      else if ((rect_position.y <= m_a.y) && (rect_position.y <= m_b.y)) {  //m_c is right bottom corner
        rect_position.x -= width;
      }
    }
    else if ((rect_position.x <= m_a.x) && (rect_position.x <= m_b.x)) {    //then m_c is a left upper or bottom corner
      if ((rect_position.y >= m_a.y) && (rect_position.y >= m_b.y)) {       //m_c is a left upper corner
        rect_position.y -= length;
      }
    }
  } 

  rectangle_t m_frameRect = {width, length, rect_position}; //rect_position is a left bottom corner

	return m_frameRect;
} 

void Triangle::scale(double coeff)
{
	if (coeff == 0) {
		throw std::invalid_argument("Coefficient cannot be zero.");
		coeff = 1;
	}
	m_position.x > m_a.x ? m_a.x -= fabs(m_a.x - m_position.x)*coeff :  m_a.x += fabs(m_a.x - m_position.x)*coeff;
	m_position.y > m_a.y ? m_a.y -= fabs(m_a.y - m_position.y)*coeff :  m_a.y += fabs(m_a.y - m_position.y)*coeff;

	m_position.x > m_b.x ? m_b.x -= fabs(m_b.x - m_position.x)*coeff :  m_b.x += fabs(m_b.x - m_position.x)*coeff;
	m_position.y > m_b.y ? m_b.y -= fabs(m_b.y - m_position.y)*coeff :  m_b.y += fabs(m_b.y - m_position.y)*coeff;

	m_position.x > m_c.x ? m_c.x -= fabs(m_c.x - m_position.x)*coeff :  m_c.x += fabs(m_c.x - m_position.x)*coeff;
	m_position.y > m_c.y ? m_c.y -= fabs(m_c.y - m_position.y)*coeff :  m_c.y += fabs(m_c.y - m_position.y)*coeff;
}

void Triangle::move(double x, double y)
{
	m_position.x += x;
	m_position.y += y;

	m_a.x += x;
	m_b.x += x;
	m_c.x += x;

	m_a.y += y;
	m_b.y += y;
	m_c.y += y;
}

void Triangle::move(point_t new_position)
{
	m_a.x += new_position.x - m_position.x;
	m_b.x += new_position.x - m_position.x;
	m_c.x += new_position.x - m_position.x;

	m_a.y += new_position.y - m_position.y;
	m_b.y += new_position.y - m_position.y;
	m_c.y += new_position.y - m_position.y;

	m_position = new_position;
}

void Triangle::rotate(double degree)
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

  m_a = {((m_a.x - m_position.x) * cos((m_angle * M_PI)/180)) - ((m_a.y - m_position.y)* sin((m_angle * M_PI)/180)) + m_position.x,
        ((m_a.x - m_position.x) * sin((m_angle * M_PI)/180)) + ((m_a.y - m_position.y)* cos((m_angle * M_PI)/180)) + m_position.y};

  m_b = {((m_b.x - m_position.x) * cos((m_angle * M_PI)/180)) - ((m_b.y - m_position.y)* sin((m_angle * M_PI)/180)) + m_position.x,
        ((m_b.x - m_position.x) * sin((m_angle * M_PI)/180)) + ((m_b.y - m_position.y)* cos((m_angle * M_PI)/180)) + m_position.y};

  m_c = {((m_c.x - m_position.x) * cos((m_angle * M_PI)/180)) - ((m_c.y - m_position.y)* sin((m_angle * M_PI)/180)) + m_position.x,
        ((m_c.x - m_position.x) * sin((m_angle * M_PI)/180)) + ((m_c.y - m_position.y)* cos((m_angle * M_PI)/180)) + m_position.y};
}

point_t Triangle::getVertexA() const
{
	return m_a;
}

point_t Triangle::getVertexB() const
{
	return m_b;
}

point_t Triangle::getVertexC() const
{
	return m_c;
}

