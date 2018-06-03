#ifndef __BASETYPES_H
#define __BASETYPES_H

struct point_t {
	double x;
	double y;
};

struct rectangle_t {
	double width;
	double length;
	point_t pos;
};

#endif
