/*
 * Line.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#include "Line.h"
#include <stdio.h>

Line::Line(int pDeltaY, int pDeltaZ, Point* pIntercept) {
	deltaY = pDeltaY;
	deltaZ = pDeltaZ;
	intercept = pIntercept;
	points = new LinkedList<Point>;
	addPointToLine(pIntercept);
}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

int Line::getDeltaX(){
	return deltaX;
}

int Line::getDeltaY(){
	return deltaY;
}

int Line::getDeltaZ(){
	return deltaZ;
}

Point* Line::getIntercept(){
	return intercept;
}

int Line::getNumOfPoints(){
	return numOfPoints;
}

double Line::getTotalValue(){
	return totalValue;
}

bool Line::containsPoint(Point* pPoint){
	if (pPoint != NULL){
		for (int i = 0; i < numOfPoints; i++){
			Point* current = points->get(i);

			if (current->getX() == pPoint->getX() && current->getY() == pPoint->getY() && current->getZ() == pPoint->getZ()){
				return true;
			}
		}
	}

	return false;
}

bool Line::shouldContainPoint(Point* pPoint){
	int steps = pPoint->getX() - intercept->getX();

	return (((intercept->getY() + (deltaY * steps)) ==  pPoint->getY()) && ((intercept->getZ() + (deltaZ * steps)) ==  pPoint->getZ()));
}

bool Line::addPointToLine(Point* pPoint){
	if (!containsPoint(pPoint) && shouldContainPoint(pPoint)){
		points->enqueue(pPoint);
		numOfPoints++;
		totalValue+=pPoint->getValue();
		updateToString();
		return true;
	}

	return false;
}

char* Line::toString(){
	return stringRepresentation;
}

void Line::updateToString(){
	snprintf(stringRepresentation, sizeof(stringRepresentation), "((%dx + %d), (%dy + %d), (%dz + %d)) | Points: %d | Value: %f", getDeltaX(), intercept->getX(), getDeltaY(), intercept->getY(), getDeltaZ(), intercept->getZ(), getNumOfPoints(), getTotalValue());
}
