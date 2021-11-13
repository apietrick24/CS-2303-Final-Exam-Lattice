/*
 * Line.h
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#ifndef LINE_H_
#define LINE_H_

#include "Point.h"
#include "LinkedList.h"

class Line {
public:
	Line(int pDeltaY, int pDeltaZ, Point* pIntercept);
	virtual ~Line();

	int getDeltaX();
	int getDeltaY();
	int getDeltaZ();
	Point* getIntercept();
	int getNumOfPoints();
	double getTotalValue();
	char* toString();

	bool addPointToLine(Point* pPoint);
	bool containsPoint(Point* pPoint);
	bool shouldContainPoint(Point* pPoint);

	LinkedList<Point>* points;

private:
	int deltaX = 1;
	int deltaY;
	int deltaZ;
	Point* intercept;

	int numOfPoints;
	double totalValue;
	char stringRepresentation[75];


	void updateToString();

};

#endif /* LINE_H_ */
