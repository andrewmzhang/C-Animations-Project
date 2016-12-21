#include "circle.h"

circle::circle(double r, string c) {
	radius = r;
	color = c;
}

double circle::getRadius() const {
	return radius;
}

string circle::getColor() const {
	return color;
}

void circle::setColor(string c) {
	color = c;
}

double circle::getArea() const {
	return radius*radius*3.14159265;
}
