#include "Point.h"

Point::Point(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

double Point::getZ() const {
	return z;
}

void Point::setX(double value) {
	this->x = value;
}

void Point::setY(double value) {
	this->y = value;
}

void Point::setZ(double value) {
	this->z = value;
}

