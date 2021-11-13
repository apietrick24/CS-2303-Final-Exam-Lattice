/*
 * Tests.h
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Production.h"
#include <stdio.h>
#include "Point.h"


class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();

private:

	//Point
	bool testPointStructure();
	bool testPointToString();

	//Linked List
	bool testLinkedListInit();
	bool testLinkedListEnqueue();
	bool testLinkedListGet();

	//Line
	bool testLineInit();
	bool testLineAddPointToLine();
	bool testLineContainsPoint();
	bool testLineShouldContainPoint();
	bool testLineToString();

	//Space
	bool testSpaceInit();
	bool testSpaceGetLine();
	bool testSpaceGetAllLine();

	//Test helper
	bool getYesNo(char* query);
};

#endif /* TESTS_H_ */
