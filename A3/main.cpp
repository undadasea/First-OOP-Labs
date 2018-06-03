#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "CompositeShape.h"
using namespace std;

int main() {
	Shape *circle_ = new Circle(5.0, { 3.0, 1.0 });
	Shape *rect_ = new Rectangle({ 1.0, 1.0 }, 1.0, 1.0);
	Triangle triangle_({2.0, 1.0}, {1.0 , 5.0}, {4.0 , 1.0});
	Circle circle_c(3.0, {2.0, 4.0});
	Rectangle rect_r({1.0, 5.0}, 4.0, 4.0);
	CompositeShape CompositeShape_(&triangle_);
	CompositeShape_.addFigure(&circle_c);
	CompositeShape_.addFigure(&rect_r);
	point_t new_point = { 5.0, 5.0 };
	double new_x = 9.0;
	double new_y = 9.0;


	cout << "circle_ area: " << circle_->getArea() << '\n'
		 << "rect_ area: " << rect_->getArea() << '\n'
		 << "triangle_ area: " << triangle_.getArea() << '\n'

		 << "circle_c area: " << circle_c.getArea() << '\n'
		 << "rect_r area: " << rect_r.getArea() << '\n'

		 << "FrameRect rect_r: width=" << rect_r.getFrameRect().width
		 << "pos x:" << rect_r.getFrameRect().pos.x << " pos y:" << rect_r.getFrameRect().pos.y << '\n'

	     << "CompositeShape_ area: " << CompositeShape_.getArea() << '\n';

	cout << "Frame around circle_: width=" << circle_->getFrameRect().width
		<< ", length=" << circle_->getFrameRect().length << ", left bottom corner: x=" << circle_->getFrameRect().pos.x
		<< ", y=" << circle_->getFrameRect().pos.y << '\n'
		<< "Frame around rect_: width=" << rect_->getFrameRect().width
		<< ", length=" << rect_->getFrameRect().length << ", left bottom corner: x=" << rect_->getFrameRect().pos.x
		<< ", y=" << rect_->getFrameRect().pos.y << '\n'
		<< "Frame around triangle_: width=" << triangle_.getFrameRect().width
		<< ", length=" << triangle_.getFrameRect().length << ", left bottom corner: x=" << triangle_.getFrameRect().pos.x
		<< ", y=" << triangle_.getFrameRect().pos.y << '\n'
		<< "Frame around CompositeShape_: width=" << CompositeShape_.getFrameRect().width
		<< ", length=" << CompositeShape_.getFrameRect().length << ", center = {" << CompositeShape_.getFrameRect().pos.x
		<< "," << CompositeShape_.getFrameRect().pos.y << "}" << '\n';

	circle_->move(new_point);
	rect_->move(new_point);
	triangle_.move(new_point);
	CompositeShape_.move(new_point);

	cout << "After move(new_point = " << new_point.x << "," << new_point.y << ")" << '\n'
	    << "new position (circle_) = (" << circle_->getFrameRect().pos.x << ","
		<< circle_->getFrameRect().pos.y << ")" << '\n'
		<< "new position (rect_) = (" << rect_->getFrameRect().pos.x << ","
		<< rect_->getFrameRect().pos.y << ")" << '\n'
		<< "new position (triangle_) = (" << triangle_.getFrameRect().pos.x << ","
		<< triangle_.getFrameRect().pos.y << ")" << '\n'
		<< "Vertex A: x=" << triangle_.getVertexA().x << ", y=" << triangle_.getVertexA().y << '\n'
	    << "Vertex B: x=" << triangle_.getVertexB().x << ", y=" << triangle_.getVertexB().y << '\n'
	    << "Vertex C: x=" << triangle_.getVertexC().x << ", y=" << triangle_.getVertexC().y << '\n'
	    << "new position (CompositeShape_) = (" << CompositeShape_.getFrameRect().pos.x << ","
	    << CompositeShape_.getFrameRect().pos.y << ")" << '\n';

	circle_->move(new_x, new_y);
	rect_->move(new_x, new_y);
	triangle_.move(new_x, new_y);
	CompositeShape_.move(new_x, new_y);

	cout << "After move(new_x = " << new_x << ", new_y = " << new_y << ")" << '\n'
	    << "new position (circle_) = (" << circle_->getFrameRect().pos.x << ","
		<< circle_->getFrameRect().pos.y << ")" << '\n'
		<< "new position (rect_) = (" << rect_->getFrameRect().pos.x << ","
		<< rect_->getFrameRect().pos.y << ")" << '\n'
		<< "new position (triangle_) = (" << triangle_.getFrameRect().pos.x << ","
		<< triangle_.getFrameRect().pos.y << ")" << '\n'
		<< "Vertex A: x=" << triangle_.getVertexA().x << ", y=" << triangle_.getVertexA().y << '\n'
	    << "Vertex B: x=" << triangle_.getVertexB().x << ", y=" << triangle_.getVertexB().y << '\n'
	    << "Vertex C: x=" << triangle_.getVertexC().x << ", y=" << triangle_.getVertexC().y << '\n'
	    << "new position (CompositeShape_) = (" << CompositeShape_.getFrameRect().pos.x << ","
	    << CompositeShape_.getFrameRect().pos.y << ")" << '\n';

	cout << "Frame around circle_: width=" << circle_->getFrameRect().width
		<< ", length=" << circle_->getFrameRect().length << ", left bottom corner: x=" << circle_->getFrameRect().pos.x
		<< ", y=" << circle_->getFrameRect().pos.y << '\n'
		<< "Frame around rect_: width=" << rect_->getFrameRect().width
		<< ", length=" << rect_->getFrameRect().length << ", left bottom corner: x=" << rect_->getFrameRect().pos.x
		<< ", y=" << rect_->getFrameRect().pos.y << '\n'
		<< "Frame around triangle_: width=" << triangle_.getFrameRect().width
		<< ", length=" << triangle_.getFrameRect().length << ", left bottom corner: x=" << triangle_.getFrameRect().pos.x
		<< ", y=" << triangle_.getFrameRect().pos.y << '\n'
		<< "Frame around CompositeShape_: width=" << CompositeShape_.getFrameRect().width
		<< ", length=" << CompositeShape_.getFrameRect().length << ", center = {" << CompositeShape_.getFrameRect().pos.x
		<< "," << CompositeShape_.getFrameRect().pos.y << "}" << '\n';

    cout << "Vertex A: x=" << triangle_.getVertexA().x << ", y=" << triangle_.getVertexA().y << '\n'
	   << "Vertex B: x=" << triangle_.getVertexB().x << ", y=" << triangle_.getVertexB().y << '\n'
	   << "Vertex C: x=" << triangle_.getVertexC().x << ", y=" << triangle_.getVertexC().y << '\n';

	circle_->scale(3.0);
	rect_->scale(3.0);
	triangle_.scale(3.0);
	CompositeShape_.scale(2.0);

	cout << "Vertex A: x=" << triangle_.getVertexA().x << ", y=" << triangle_.getVertexA().y << '\n'
	<< "Vertex B: x=" << triangle_.getVertexB().x << ", y=" << triangle_.getVertexB().y << '\n'
	<< "Vertex C: x=" << triangle_.getVertexC().x << ", y=" << triangle_.getVertexC().y << '\n';

	cout << "Frame around circle_: width=" << circle_->getFrameRect().width
		<< ", length=" << circle_->getFrameRect().length << ", left bottom corner: x=" << circle_->getFrameRect().pos.x
		<< ", y=" << circle_->getFrameRect().pos.y << '\n'
		<< "Frame around rect_: width=" << rect_->getFrameRect().width
		<< ", length=" << rect_->getFrameRect().length << ", left bottom corner: x=" << rect_->getFrameRect().pos.x
		<< ", y=" << rect_->getFrameRect().pos.y << '\n'
		<< "Frame around triangle_: width=" << triangle_.getFrameRect().width
		<< ", length=" << triangle_.getFrameRect().length << ", center of gravity: x=" << triangle_.getFrameRect().pos.x
		<< ", y=" << triangle_.getFrameRect().pos.y << '\n'
		<< "Frame around CompositeShape_: width=" << CompositeShape_.getFrameRect().width
		<< ", length=" << CompositeShape_.getFrameRect().length << ", center = {" << CompositeShape_.getFrameRect().pos.x
		<< "," << CompositeShape_.getFrameRect().pos.y << "}" << '\n';

	delete circle_;
	delete rect_;

    return 0;
};