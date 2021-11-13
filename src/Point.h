/*
 * Point.h
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#ifndef POINT_H_
#define POINT_H_
#include <stdio.h>

class Point {
public:
	Point(int pX, int pY, int pZ, double pValue);
	virtual ~Point();
	//Getters
	int getX();
	int getY();
	int getZ();
	double getValue();
	char* toString();

private:
	int x;
	int y;
	int z;
	double value;
	char stringRepresentation[50];

};

#endif /* POINT_H_ */
