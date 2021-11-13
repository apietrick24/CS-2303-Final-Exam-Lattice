/*
 * Space.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#include "Space.h"
#include "Point.h"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::vector;


Space::Space(char* filename) {
	// TODO Auto-generated constructor stub

	std::ifstream readFile(filename);

	std::string line;

	std::getline(readFile, line);

	size = std::stoi(line);

	lattice.resize(size);

	for (int i = 0; i < size; ++i) {
		lattice[i].resize(size);

		for (int j = 0; j < size; ++j)
			lattice[i][j].resize(size);
	}

	while (std::getline(readFile, line)){
		std::string parsed;

		int x = -1;
		int y = -1;
		int z = -1;

		int currentCase = 0;
		for(int i = 0; i < line.length(); i++){
			char currentChar = line[i];

			switch(currentChar){
			case ' ':
				break;

			case ',':
				switch(currentCase){
				case 0:
					x = std::stoi(parsed);
					break;
				case 1:
					y = std::stoi(parsed);
					break;
				case 2:
					z = std::stoi(parsed);
					break;
				}

				parsed = "";
				currentCase++;
				break;
				default:
					parsed += currentChar;
					break;
			}
		}

		float value = std::stof(parsed);

		lattice[x][y][z] = new Point(x, y, z, value);
	}
}


Space::~Space() {
	// TODO Auto-generated destructor stub
}

Point* Space::getPoint(int x, int y, int z){
	if (x < 0 || x >= size || y < 0 || y >= size || z < 0 || z >= size){
		return NULL;
	} else {
		return lattice[x][y][z];
	}
}

int Space::getSize(){
	return size;
}

LinkedList<Line>* Space::getAllLines(Point* pIntercept){
	LinkedList<Line>* lineList = new LinkedList<Line>;

	if (pIntercept != NULL){
		for (int dY = 0; dY <= 1; dY++){
			for (int dZ = 0; dZ <= 1; dZ++){
				lineList->enqueue(getLine(dY, dZ, pIntercept));
			}
		}
	}

	return lineList;
}

Line* Space::getLine(int pDeltaY, int pDeltaZ, Point* pIntercept){
	Line* currentLine = NULL;
	if (pIntercept != NULL){
		currentLine = new Line(pDeltaY, pDeltaZ, pIntercept);

		for (int i = -size; i < size; i++){
			Point* toAdd = getPoint(pIntercept->getX() + i, pIntercept->getY() + pDeltaY*i, pIntercept->getZ() + pDeltaZ *i);

			if (toAdd != NULL){
				currentLine->addPointToLine(toAdd);
			}
		}
	}

	return currentLine;
}

