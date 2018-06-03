#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
using namespace std;

int main() {
	Shape *circle_ = new Circle(5.5, { 1.1, 1.1 });
	Shape *rect_ = new Rectangle({ 1.1, 1.1 }, 1.1, 1.1);
	Triangle triangle_({1.1, 1.1}, {1.1 , 2.2}, {3.3 , 3.3});
	point_t new_point = { 5.0, 5.0 };
	double new_x = 9.0;
	double new_y = 9.0;


	cout << "circle_ area: " << circle_->getArea() << '\n'
		 << "rect_ area: " << rect_->getArea() << '\n'
		 << "triangle_ area: " << triangle_.getArea() << '\n';

	circle_->move(new_point);
	rect_->move(new_point);
	triangle_.move(new_point);

	cout << "new position (circle_) = (" << circle_->getFrameRect().pos.x << ","
		<< circle_->getFrameRect().pos.y << ")" << '\n'
		<< "new position (rect_) = (" << rect_->getFrameRect().pos.x << ","
		<< rect_->getFrameRect().pos.y << ")" << '\n'
		<< "new position (triangle_) = (" << triangle_.getPosition().x << ","
		<< triangle_.getPosition().y << ")" << '\n';

	circle_->move(new_x, new_y);
	rect_->move(new_x, new_y);
	triangle_.move(new_x, new_y);

	cout << "new position (circle_) = (" << circle_->getFrameRect().pos.x << ","
		<< circle_->getFrameRect().pos.y << ")" << '\n'
		<< "new position (rect_) = (" << rect_->getFrameRect().pos.x << ","
		<< rect_->getFrameRect().pos.y << ")" << '\n'
		<< "new position (triangle_) = (" << triangle_.getPosition().x << ","
		<< triangle_.getPosition().y << ")" << '\n';

	cout << "Frame around circle_: width=" << circle_->getFrameRect().width
		<< ", length=" << circle_->getFrameRect().length << ", center: x=" << circle_->getFrameRect().pos.x
		<< ", y=" << circle_->getFrameRect().pos.y << '\n'
		<< "Frame around rect_: width=" << rect_->getFrameRect().width
		<< ", length=" << rect_->getFrameRect().length << ", center: x=" << rect_->getFrameRect().pos.x
		<< ", y=" << rect_->getFrameRect().pos.y << '\n'
		<< "Frame around triangle_: width=" << triangle_.getFrameRect().width
		<< ", length=" << triangle_.getFrameRect().length << ", center: x=" << triangle_.getFrameRect().pos.x
		<< ", y=" << triangle_.getFrameRect().pos.y << '\n';

	delete circle_;
	delete rect_;

    return 0;
};