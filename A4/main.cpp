#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "CompositeShape.h"
using namespace std;

int main()
{
	Circle circle_(2.0, {3.0, 3.0});
	Rectangle rect_({4.0, 5.0}, 4.0, 4.0);
	CompositeShape CompositeShape_(&rect_);
	CompositeShape_.addFigure(&circle_);

	cout << "Frame around CompositeShape_: width=" << CompositeShape_.getFrameRect().width
	<< ", length=" << CompositeShape_.getFrameRect().length << ", center = {" << CompositeShape_.getFrameRect().pos.x
	<< "," << CompositeShape_.getFrameRect().pos.y << "}" << '\n'
	<< "Frame around circle_: width=" << circle_.getFrameRect().width
	<< ", length=" << circle_.getFrameRect().length << ", center: x=" << circle_.getPosition().x
	<< ", y=" << circle_.getPosition().y << '\n'
	<< "Frame around rect_: width=" << rect_.getFrameRect().width
	<< ", length=" << rect_.getFrameRect().length << ", center: x=" << rect_.getPosition().x
	<< ", y=" << rect_.getPosition().y << '\n';

	CompositeShape_.rotate(90);

	cout << "Frame around CompositeShape_: width=" << CompositeShape_.getFrameRect().width
	<< ", length=" << CompositeShape_.getFrameRect().length << ", center = {" << CompositeShape_.getFrameRect().pos.x
	<< "," << CompositeShape_.getFrameRect().pos.y << "}" << '\n'
	<< "Frame around circle_: width=" << circle_.getFrameRect().width
	<< ", length=" << circle_.getFrameRect().length << ", center: x=" << circle_.getPosition().x
	<< ", y=" << circle_.getPosition().y << '\n'
	<< "Frame around rect_: width=" << rect_.getFrameRect().width
	<< ", length=" << rect_.getFrameRect().length << ", center: x=" << rect_.getPosition().x
	<< ", y=" << rect_.getPosition().y << '\n';
}