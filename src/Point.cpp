/*
 * Point.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#include "Point.h"
#include <stdio.h>

Point::Point(int pX, int pY, int pZ, double pValue) {
	x = pX;
	y = pY;
	z = pZ;
	value = pValue;

	snprintf(stringRepresentation, sizeof(stringRepresentation), "(%d, %d, %d): %f", getX(), getY(), getZ(), getValue());
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

int Point::getX(){
	return x;
}

int Point::getY(){
	return y;
}

int Point::getZ(){
	return z;
}

double Point::getValue(){
	return value;
}

char* Point::toString(){
	return stringRepresentation;
}
