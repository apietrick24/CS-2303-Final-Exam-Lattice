/*
 * Space.h
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#ifndef SPACE_H_
#define SPACE_H_
#include "Point.h"
#include "Line.h"
#include "LinkedList.h"
#include <vector>
using std::vector;

class Space {
public:
	Space(char* filename);
	virtual ~Space();

	int getSize();
	Point* getPoint(int x, int y, int z);

	LinkedList<Line>* getAllLines(Point* pIntercept);

	Line* getLine(int pDeltaY, int pDeltaZ, Point* pIntercept);

private:

	int size;
	vector<vector<vector<Point* > > > lattice;
};

#endif /* SPACE_H_ */
