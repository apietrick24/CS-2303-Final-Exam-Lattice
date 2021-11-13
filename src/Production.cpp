/*
 * Production.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#include "Production.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Space.h"
#include "Line.h"
#include "Point.h"
#include "LinkedList.h"
#include "LinkedList.cpp"

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{
	printf("Starting Production\n");
	printf("Arguments:\n");
	printf("\tprogram file - read file - x coordinate - y coordinate - z coordinate\n\n");
	bool answer = false;

	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n\n", argc-1);
		fflush(stdout);

		char gameStateReadFile[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*) malloc(sizeof(char*));
		long aL=-1L;

		int pointX = -1;
		int pointY = -1;
		int pointZ = -1;

		for(int i = 1; i < argc; i++){

			switch(i){
			case 1:
				printf("Reading Game State Reading File Name:\n");

				printf("\tThe proposed filename is %s.\n", argv[i]);
				if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
				{
					puts("\tFilename is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					strcpy(gameStateReadFile, argv[i]);
					printf("\tFilename was %s.\n", gameStateReadFile);
					fflush(stdout);
				}

				printf("\n");
				break;

			case 2:
				printf("Reading Point's X Value:\n");
				aL = strtol(argv[i], &eptr, 10);
				pointX = (int) aL;
				printf("\tPoint's X Value: %d\n\n", pointX);
				fflush(stdout);
				break;

			case 3:
				printf("Reading Point's Y Value:\n");
				aL = strtol(argv[i], &eptr, 10);
				pointY = (int) aL;
				printf("\tPoint's Y Value: %d\n\n", pointX);
				fflush(stdout);
				break;

			case 4:
				printf("Reading Point's Z Value:\n");
				aL = strtol(argv[i], &eptr, 10);
				pointZ = (int) aL;
				printf("\tPoint's Z Value: %d\n\n", pointX);
				fflush(stdout);
				break;

			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}
		}

		std::ifstream readFile(gameStateReadFile);

		std::string line;

		std::getline(readFile, line);

		int size = std::stoi(line);


		while(pointX < 0 || pointY < 0 || pointZ < 0 || size <= pointX || size <= pointY || size <= pointZ){
			if (pointX < 0 || size <= pointX){
				int num = 0;
				printf("%d is an incorrect input for Point X Value. Please give a integer greater than or to zero and less than %d:\n", pointX, size);
				fflush(stdout);
				fflush(stdin);
				scanf("%d",&num);
				printf("The program has read the integer %d\n\n", num);

				pointX = num;
			}

			if (pointY < 0 || size <= pointY){
				int num = 0;
				printf("%d is an incorrect input for Point Y Value. Please give a integer greater than or to zero and less than %d:\n", pointY, size);
				fflush(stdout);
				fflush(stdin);
				scanf("%d",&num);
				printf("The program has read the integer %d\n\n", num);

				pointY = num;
			}

			if (pointZ < 0 || size <= pointZ){
				int num = 0;
				printf("%d is an incorrect input for Point Z Value. Please give a integer greater than or to zero and less than %d:\n", pointZ, size);
				fflush(stdout);
				fflush(stdin);
				scanf("%d",&num);
				printf("The program has read the integer %d\n\n", num);

				pointZ = num;
			}
		}

		printf("Quick Summary of Passed Arguments:\n");
		printf("\tLattice is being constructed from: %s\n", gameStateReadFile);
		printf("\tDimensions of Lattice: %d x %d x %d\n", size, size, size);
		printf("\tPoint: (%d, %d, %d)\n\n", pointX, pointY, pointZ);

		printf("Starting Program\n\n");


		//TODO Actually final problem

		Space* board = new Space(gameStateReadFile);

		LinkedList<Line>* lines = board->getAllLines(board->getPoint(pointX, pointY, pointZ));
		LinkedList<Line>* maxValueLines = new LinkedList<Line>;

		double maxValue = lines->get(0)->getTotalValue();

		printf("All Possible Lines that Go Thru the Point, %s, when dX is fixed to 1\n", board->getPoint(pointX, pointY, pointZ)->toString());
		for (int i = 0; i < lines->size; i++){
			printf("\t%s\n\t\tPoints on Line: ", lines->get(i)->toString());
			LinkedList<Point>* pointsOnLine = lines->get(i)->points;

			for (int i = 0; i < pointsOnLine->size; i++){
				if (i != (pointsOnLine->size -1)){
					printf("%s, ", pointsOnLine->get(i)->toString());
				} else {
					printf("%s\n", pointsOnLine->get(i)->toString());
				}
			}

			//double lineChangeValue = (lines->get(i)->getTotalValue() - board->getPoint(pointX, pointY, pointZ)->getValue());

			double lineValue = lines->get(i)->getTotalValue();


			if (lineValue == maxValue){
				maxValueLines->enqueue(lines->get(i));
			} else if (lineValue > maxValue){
				maxValueLines = new LinkedList<Line>;
				maxValueLines->enqueue(lines->get(i));
				maxValue =lineValue;
			}

			printf("\n");
		}

		//Printing Lines

		printf("The maximum value the total can be if we could remove lines is %f\n\n", maxValue);
		printf("This maximum value is computed using the following lines:\n");

		for (int i = 0; i < maxValueLines->size; i++){
			printf("\t%s\n\t\tPoints on Line: ", maxValueLines->get(i)->toString());
			LinkedList<Point>* pointsOnLine = maxValueLines->get(i)->points;

			for (int i = 0; i < pointsOnLine->size; i++){
				if (i != (pointsOnLine->size -1)){
					printf("%s, ", pointsOnLine->get(i)->toString());
				} else {
					printf("%s\n", pointsOnLine->get(i)->toString());
				}
			}
			printf("\n");
		}
	}


	return true;

}


bool Production::getYesNo(char* query)
{
	bool answer = true; //so far
	char said = 'x';
	do
	{
		printf("%s (y/n):",query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&said);
	}while((said!= 'y')&&(said!='n'));
	if(said=='n')
	{
		answer=false;
	}


	return answer;
}

