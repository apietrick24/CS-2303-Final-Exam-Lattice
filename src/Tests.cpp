/*
 * Tests.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#include "Tests.h"
#include <stdbool.h>
#include "Point.h"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Line.h"
#include "Space.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests(){
	printf("Starting Tests\n\n");
	bool answer = true;

	//Point Tests
	bool test1 = testPointStructure();
	bool test2 = testPointToString();

	bool pointTests = test1 && test2;

	//LinkedList Test
	bool test3 = testLinkedListInit();
	bool test4 =  testLinkedListEnqueue();
	bool test5 = testLinkedListGet();

	bool linkedListTests = test3 && test4 && test5;

	//Line Tests
	bool test6 = testLineInit();
	bool test7 = testLineShouldContainPoint();
	bool test8 = testLineContainsPoint();
	bool test9 = testLineAddPointToLine();
	bool test10 = testLineToString();

	bool lineTests = test6 && test7 && test8 && test9 && test10;

	//Space Tests

	bool test11 = testSpaceInit();
	bool test12 = testSpaceGetLine();
	bool test13 = testSpaceGetAllLine();

	bool spaceTests = test11 && test12 && test13;

	answer = pointTests && linkedListTests && lineTests && spaceTests;

	if (answer){
		printf("All Tests Passed: program is ready to be run\n\n");
	} else {
		printf("At least one test didn't pass: program will not be run\n\n");
	}
	return answer;
}

bool Tests::testPointStructure(){
	printf("Starting testPointStructure (testing Pointer's init and Getters)\n");
	bool testPasses = true;
	Point* testPoint1 = new Point(1, 2, 3, 4.5);


	if (testPoint1->getX() != 1 || testPoint1->getY() != 2 || testPoint1->getZ() != 3 || testPoint1->getValue() != 4.5){
		testPasses = false;
		printf("\tfailed testPointStructureInit1 subtest\n");
	} else {
		printf("\tpassed testPointStructureInit1 subtest\n");
	}

	Point* testPoint2 = new Point(4, 3, 1, 4.9905);

	if (testPoint2->getX() != 4 || testPoint2->getY() != 3 || testPoint2->getZ() != 1 || testPoint2->getValue() != 4.9905){
		testPasses = false;
		printf("\tfailed testPointStructureInit2 subtest\n");
	} else {
		printf("\tpassed testPointStructureInit2 subtest\n");
	}

	Point* testPoint3 = new Point(0, 0, 0, 0.0);


	if (testPoint3->getX() != 0 || testPoint3->getY() != 0 || testPoint3->getZ() != 0 || testPoint3->getValue() != 0.0){
		testPasses = false;
		printf("\tfailed testPointStructureInit3 subtest\n");
	} else {
		printf("\tpassed testPointStructureInit3 subtest\n");
	}

	if (testPasses){
		printf("testPointStructure Passed: successful passed all subtests\n");
	} else {
		printf("testPointStructure Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}
bool Tests::testPointToString(){
	printf("Starting testPointToString (testing Pointer's init and Getters)\n");
	bool testPasses = true;

	Point* testPoint1 = new Point(1, 2, 3, 4.5);
	Point* testPoint2 = new Point(4, 3, 1, 4.9905);
	Point* testPoint3 = new Point(0, 0, 0, 0.0);

	char outbuf[300];
	snprintf(outbuf, sizeof(outbuf), "Given the Point: x = %d, y = %d, z = %d and value = %f\n\tIs the string, %s, a good representation of the point?\n", testPoint1->getX(), testPoint1->getY(), testPoint1->getZ(), testPoint1->getValue(), testPoint1->toString());

	if (!getYesNo(outbuf)){
		testPasses = false;
		printf("\tfailed testPointToStringPoint1 subtest\n");
	} else {
		printf("\tpassed testPointToStringPoint1 subtest\n");
	}

	printf("\n");

	snprintf(outbuf, sizeof(outbuf), "Given the Point: x = %d, y = %d, z = %d and value = %f\n\tIs the string, %s, a good representation of the point?\n", testPoint2->getX(), testPoint2->getY(), testPoint2->getZ(), testPoint2->getValue(), testPoint2->toString());

	if (!getYesNo(outbuf)){
		testPasses = false;
		printf("\tfailed testPointToStringPoint2 subtest\n");
	} else {
		printf("\tpassed testPointToStringPoint2 subtest\n");
	}

	printf("\n");

	snprintf(outbuf, sizeof(outbuf), "Given the Point: x = %d, y = %d, z = %d and value = %f\n\tIs the string, %s, a good representation of the point?\n", testPoint3->getX(), testPoint3->getY(), testPoint3->getZ(), testPoint3->getValue(), testPoint3->toString());

	if (!getYesNo(outbuf)){
		testPasses = false;
		printf("\tfailed testPointToStringPoint3 subtest\n");
	} else {
		printf("\tpassed testPointToStringPoint3 subtest\n");
	}


	if (testPasses){
		printf("testPointToString Passed: successful passed all subtests\n");
	} else {
		printf("testPointToString Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::testLinkedListInit(){
	printf("Starting testLinkedListInit\n");
	bool testPasses = true;

	LinkedList<Point>* linkedListPointer = new LinkedList<Point>();

	if(linkedListPointer->size != 0){
		testPasses = false;
		printf("\tfailed testLinkedListInitSize subtest\n");
	} else {
		printf("\tpassed testLinkedListInitSize subtest\n");
	}

	if(linkedListPointer->head != NULL){
		testPasses = false;
		printf("\tfailed testLinkedListInitNullHead subtest\n");
	} else {
		printf("\tpassed testLinkedListInitNullHead subtest\n");
	}

	if(linkedListPointer->tail != NULL){
		testPasses = false;
		printf("\tfailed testLinkedListInitNullTail subtest\n");
	} else {
		printf("\tpassed testLinkedListInitNullTail subtest\n");
	}

	if (testPasses){
		printf("testLinkedListInit Passed: successful passed all subtests\n");
	} else {
		printf("testLinkedListInit Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}
bool Tests::testLinkedListEnqueue(){
	printf("Starting testLinkedListEnqueue\n");
	bool testPasses = true;

	LinkedList<Point>* linkedListPointer = new LinkedList<Point>();

	Point* testPoint1 = new Point(1, 2, 3, 4.5);
	Point* testPoint2 = new Point(4, 3, 1, 4.9905);
	Point* testPoint3 = new Point(0, 0, 0, 0.0);

	linkedListPointer->enqueue(testPoint1);

	//printf("head: %s | tail %s\n", linkedListPointer->head->data->toString(), linkedListPointer->tail->data->toString());

	if(linkedListPointer->size != 1){
		testPasses = false;
		printf("\tfailed testEnqueueSizeIncrease1 subtest\n");
	} else {
		printf("\tpassed testEnqueueSizeIncrease1 subtest\n");
	}

	linkedListPointer->enqueue(testPoint2);

	if(linkedListPointer->size != 2){
		testPasses = false;
		printf("\tfailed testEnqueueSizeIncrease2 subtest\n");
	} else {
		printf("\tpassed testEnqueueSizeIncrease2 subtest\n");
	}

	linkedListPointer->enqueue(testPoint3);

	Point* firstPointPointer = linkedListPointer->head->data;
	Point* secondPointPointer = linkedListPointer->head->next->data;
	Point* thirdPointPointer = linkedListPointer->tail->data;

	if(firstPointPointer != testPoint1){
		testPasses = false;
		printf("\tfailed testEnqueueCorrectDataPointer1 subtest\n");
	} else {
		printf("\tpassed testEnqueueCorrectDataPointer1 subtest\n");
	}

	if(secondPointPointer != testPoint2){
		testPasses = false;
		printf("\tfailed testEnqueueCorrectDataPointer2 subtest\n");
	} else {
		printf("\tpassed testEnqueueCorrectDataPointer2 subtest\n");
	}

	if(thirdPointPointer != testPoint3){
		testPasses = false;
		printf("\tfailed testEnqueueCorrectDataPointer3 subtest\n");
	} else {
		printf("\tpassed testEnqueueCorrectDataPointer3 subtest\n");
	}

	if(linkedListPointer->tail->next != NULL){
		testPasses = false;
		printf("\tfailed testEnqueueTailNextNull subtest\n");
	} else {
		printf("\tpassed testEnqueueTailNextNull subtest\n");
	}

	if (testPasses){
		printf("testLinkedListEnqueue Passed: successful passed all subtests\n");
	} else {
		printf("testLinkedListEnqueue Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}
bool Tests::testLinkedListGet(){
	printf("Starting testLinkedListGet\n");
	bool testPasses = true;

	LinkedList<Point>* linkedListPointer = new LinkedList<Point>();

	Point* testPoint1 = new Point(1, 2, 3, 4.5);
	Point* testPoint2 = new Point(4, 3, 1, 4.9905);
	Point* testPoint3 = new Point(0, 0, 0, 0.0);

	if(linkedListPointer->get(0) != NULL){
		testPasses = false;
		printf("\tfailed testLinkedListGetNone subtest\n");
	} else {
		printf("\tpassed testLinkedListGetNone subtest\n");
	}

	linkedListPointer->enqueue(testPoint1);
	linkedListPointer->enqueue(testPoint2);
	linkedListPointer->enqueue(testPoint3);

	if(linkedListPointer->get(0) != testPoint1){
		testPasses = false;
		printf("\tfailed testLinkedListGet1 subtest\n");
	} else {
		printf("\tpassed testLinkedListGet1 subtest\n");
	}

	if(linkedListPointer->get(1) != testPoint2){
		testPasses = false;
		printf("\tfailed testLinkedListGet2 subtest\n");
	} else {
		printf("\tpassed testLinkedListGet subtest\n");
	}

	if(linkedListPointer->get(2) != testPoint3){
		testPasses = false;
		printf("\tfailed testLinkedListGet3 subtest\n");
	} else {
		printf("\tpassed testLinkedListGet3 subtest\n");
	}

	if(linkedListPointer->get(-1) != testPoint3){
		testPasses = false;
		printf("\tfailed testLinkedListGetTail subtest\n");
	} else {
		printf("\tpassed testLinkedListGetTail subtest\n");
	}

	if(linkedListPointer->get(3) != NULL){
		testPasses = false;
		printf("\tfailed testLinkedListGetOutOfBounds subtest\n");
	} else {
		printf("\tpassed testLinkedListGetOutOfBounds subtest\n");
	}

	if (testPasses){
		printf("testLinkedListGet Passed: successful passed all subtests\n");
	} else {
		printf("testLinkedListGet Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::testLineInit(){
	printf("Starting testLineInit (testing Line's init and Getters)\n");
	bool testPasses = true;

	Point* intercept1 = new Point(1, 2, 3, 4.5);
	Line* line1 = new Line(1, 1, intercept1);

	if (line1->getDeltaX() != 1 || line1->getDeltaY() != 1 || line1->getDeltaZ() != 1 || line1->getIntercept() != intercept1){
		testPasses = false;
		printf("\tfailed testLineInit1 subtest\n");
	} else {
		printf("\tpassed testLineInit1 subtest\n");
	}

	Point* intercept2 = new Point(3, 2, 4, 1.333);
	Line* line2 = new Line(0, 1, intercept2);

	if (line2->getDeltaX() != 1 || line2->getDeltaY() != 0 || line2->getDeltaZ() != 1 || line2->getIntercept() != intercept2){
		testPasses = false;
		printf("\tfailed testLineInit2 subtest\n");
	} else {
		printf("\tpassed testLineInit2 subtest\n");
	}

	Point* intercept3 = new Point(3, 2, 4, 1.333);
	Line* line3 = new Line(3, 9, intercept3);

	if (line3->getDeltaX() != 1 || line3->getDeltaY() != 3 || line3->getDeltaZ() != 9 || line3->getIntercept() != intercept3){
		testPasses = false;
		printf("\tfailed testLineInit3 subtest\n");
	} else {
		printf("\tpassed testLineInit3 subtest\n");
	}

	if (testPasses){
		printf("testLineInit Passed: successful passed all subtests\n");
	} else {
		printf("testLineInit Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::testLineShouldContainPoint(){
	printf("Starting testLineShouldContainPoint\n");
	bool testPasses = true;

	Point* intercept1 = new Point(0, 0, 0, 4.5);
	Line* line1 = new Line(1, 1, intercept1);

	if (!line1->shouldContainPoint(intercept1)){
		testPasses = false;
		printf("\tfailed testLineShouldContainPointIntercept subtest\n");
	} else {
		printf("\tpassed testLineShouldContainPointIntercept subtest\n");
	}


	Point* testPoint1 = new Point(3, 3, 3, 0.0);

	if (!line1->shouldContainPoint(testPoint1)){
		testPasses = false;
		printf("\tfailed testLineShouldContainPointPositive subtest\n");
	} else {
		printf("\tpassed testLineShouldContainPointPositive subtest\n");
	}

	Point* testPoint2 = new Point(-1, -1, -1, 0.0);

	if (!line1->shouldContainPoint(testPoint2)){
		testPasses = false;
		printf("\tfailed testLineShouldContainPointNegative subtest\n");
	} else {
		printf("\tpassed testLineShouldContainPointNegative subtest\n");
	}

	Point* testPoint3 = new Point(0, -1, -1, 0.0);

	if (line1->shouldContainPoint(testPoint3)){
		testPasses = false;
		printf("\tfailed testLineShouldContainPointNot subtest\n");
	} else {
		printf("\tpassed testLineShouldContainPointNot subtest\n");
	}

	if (testPasses){
		printf("testLineShouldContainPoint Passed: successful passed all subtests\n");
	} else {
		printf("testLineShouldContainPoint Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::testLineContainsPoint(){
	printf("Starting testLineContainsPoint\n");
	bool testPasses = true;

	Point* intercept1 = new Point(0, 0, 0, 4.5);
	Line* line1 = new Line(1, 1, intercept1);

	Point* testPoint1 = new Point(3, 3, 3, 0.0);
	Point* testPoint2 = new Point(-1, -1, -1, 0.0);
	Point* testPoint3 = new Point(0, -1, -1, 0.0);

	if (!line1->containsPoint(intercept1)){
		testPasses = false;
		printf("\tfailed testLineContainsPointIntercept subtest\n");
	} else {
		printf("\tpassed testLineContainsPointIntercept subtest\n");
	}

	if (line1->containsPoint(testPoint1)){
		testPasses = false;
		printf("\tfailed testLineContainsPoint1No subtest\n");
	} else {
		printf("\tpassed testLineContainsPoint1No subtest\n");
	}

	line1->addPointToLine(testPoint1);
	line1->addPointToLine(testPoint2);

	if (!line1->containsPoint(testPoint1)){
		testPasses = false;
		printf("\tfailed testLineContainsPoint1Yes subtest\n");
	} else {
		printf("\tpassed testLineContainsPoint1Yes subtest\n");
	}

	if (!line1->containsPoint(testPoint2)){
		testPasses = false;
		printf("\tfailed testLineContainsPoint2Yes subtest\n");
	} else {
		printf("\tpassed testLineContainsPoint2Yes subtest\n");
	}

	if (line1->containsPoint(testPoint3)){
		testPasses = false;
		printf("\tfailed testLineContainsPoint3No subtest\n");
	} else {
		printf("\tpassed testLineContainsPoint3No subtest\n");
	}

	if (testPasses){
		printf("testLineContainsPoint Passed: successful passed all subtests\n");
	} else {
		printf("testLineContainsPoint Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::testLineAddPointToLine(){
	printf("Starting testLineAddPointToLine\n");
	bool testPasses = true;

	Point* intercept1 = new Point(0, 0, 0, 4.5);
	Line* line1 = new Line(1, 1, intercept1);

	Point* testPoint1 = new Point(3, 3, 3, 0.0);
	Point* testPoint2 = new Point(-1, -1, -1, 0.0);
	Point* testPoint3 = new Point(0, -1, -1, 0.0);

	if (line1->addPointToLine(intercept1)){
		testPasses = false;
		printf("\tfailed testLineAddPointToLineIntercept subtest\n");
	} else {
		printf("\tpassed testLineAddPointToLineIntercept subtest\n");
	}

	if (!line1->addPointToLine(testPoint1)){
		testPasses = false;
		printf("\tfailed testLineAddPointToLinePoint1 subtest\n");
	} else {
		printf("\tpassed testLineAddPointToLinePoint1 subtest\n");
	}

	if (!line1->addPointToLine(testPoint2)){
		testPasses = false;
		printf("\tfailed testLineAddPointToLinePoint2 subtest\n");
	} else {
		printf("\tpassed testLineAddPointToLinePoint2 subtest\n");
	}

	if (line1->addPointToLine(testPoint3)){
		testPasses = false;
		printf("\tfailed testLineAddPointToLinePoint3 subtest\n");
	} else {
		printf("\tpassed testLineAddPointToLinePoint3 subtest\n");
	}

	if (testPasses){
		printf("testLineAddPointToLine Passed: successful passed all subtests\n");
	} else {
		printf("testLineAddPointToLine Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::testLineToString(){
	printf("Starting testLineToString\n");
	bool testPasses = true;

	Point* intercept1 = new Point(0, 0, 0, 4.5);
	Point* intercept2 = new Point(2, 1, 1, 3.10);
	Line* line1 = new Line(1, 1, intercept1);
	Line* line2 = new Line(2, 3, intercept2);

	Point* testPoint1 = new Point(3, 3, 3, 2.7);
	Point* testPoint2 = new Point(-1, -1, -1, -29.1);

	char outbuf[300];
	snprintf(outbuf, sizeof(outbuf), "Given this line: Point = %s, dX = %d, dY = %d, dZ = %d, number of points = %d and total value = %f\n\tIs the string, %s, a good representation of the point?\n", line2->getIntercept()->toString(), line2->getDeltaX(), line2->getDeltaY(), line2->getDeltaZ(), line2->getNumOfPoints(), line2->getTotalValue(), line2->toString());

	if (!getYesNo(outbuf)){
		testPasses = false;
		printf("\tfailed testLineToStringLine2 subtest\n");
	} else {
		printf("\tpassed testLineToStringLine2 subtest\n");
	}

	printf("\n");

	snprintf(outbuf, sizeof(outbuf), "Given this line: Point = %s, dX = %d, dY = %d, dZ = %d, number of points = %d and total value = %f\n\tIs the string, %s, a good representation of the point?\n", line1->getIntercept()->toString(), line1->getDeltaX(), line1->getDeltaY(), line1->getDeltaZ(), line1->getNumOfPoints(), line1->getTotalValue(), line1->toString());

	if (!getYesNo(outbuf)){
		testPasses = false;
		printf("\tfailed testLineToStringLine1Point subtest\n");
	} else {
		printf("\tpassed testLineToStringLine1Point subtest\n");
	}

	printf("\n");

	line1->addPointToLine(testPoint1);

	snprintf(outbuf, sizeof(outbuf), "Given this line: Point = %s, dX = %d, dY = %d, dZ = %d, number of points = %d and total value = %f\n\tIs the string, %s, a good representation of the point?\n", line1->getIntercept()->toString(), line1->getDeltaX(), line1->getDeltaY(), line1->getDeltaZ(), line1->getNumOfPoints(), line1->getTotalValue(), line1->toString());

	if (!getYesNo(outbuf)){
		testPasses = false;
		printf("\tfailed testPointToStringPoint3 subtest\n");
	} else {
		printf("\tpassed testPointToStringPoint3 subtest\n");
	}

	line1->addPointToLine(testPoint2);

	snprintf(outbuf, sizeof(outbuf), "Given this line: Point = %s, dX = %d, dY = %d, dZ = %d, number of points = %d and total value = %f\n\tIs the string, %s, a good representation of the point?\n", line1->getIntercept()->toString(), line1->getDeltaX(), line1->getDeltaY(), line1->getDeltaZ(), line1->getNumOfPoints(), line1->getTotalValue(), line1->toString());

	if (testPasses){
		printf("testLineToString Passed: successful passed all subtests\n");
	} else {
		printf("testLineToString Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::testSpaceInit(){
	printf("Starting testSpaceInit (testing Space's init and Getters)\n");
	bool testPasses = true;

	Space* board = new Space("finalSampleInput.txt");

	Point* testPoint1 = board->getPoint(0, 0, 0);
	Point* testPoint2 = board->getPoint(-1, 2, 0);
	Point* testPoint3 = board->getPoint(4, 1, 2);
	Point* testPoint4 = board->getPoint(2, 1, 0);

	if (board->getSize() != 3){
		testPasses = false;
		printf("\tfailed testSpaceInitSize subtest\n");
	} else {
		printf("\tpassed testSpaceInitSize subtest\n");
	}

	if (testPoint1 == NULL || testPoint1->getX() != 0 || testPoint1->getY() != 0 || testPoint1->getZ() != 0){
		testPasses = false;
		printf("\tfailed testSpaceInitValid1 subtest\n");
	} else {
		printf("\tpassed testSpaceInitValid1 subtest\n");
	}

	if (testPoint4 == NULL || testPoint4->getX() != 2 || testPoint4->getY() != 1 || testPoint4->getZ() != 0){
		testPasses = false;
		printf("\tfailed testSpaceInitValid2 subtest\n");
	} else {
		printf("\tpassed testSpaceInitValid2 subtest\n");
	}

	if (testPoint2 != NULL){
		testPasses = false;
		printf("\tfailed testSpaceInitNotValid1 subtest\n");
	} else {
		printf("\tpassed testSpaceInitNotValid1 subtest\n");
	}

	if (testPoint3 != NULL){
		testPasses = false;
		printf("\tfailed testSpaceInitNotValid2 subtest\n");
	} else {
		printf("\tpassed testSpaceInitNotValid2 subtest\n");
	}

	if (testPasses){
		printf("testSpaceInit Passed: successful passed all subtests\n");
	} else {
		printf("testSpaceInit Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::testSpaceGetLine(){
	printf("Starting testSpaceGetLine\n");
	bool testPasses = true;

	Space* board = new Space("finalSampleInput.txt");

	Line* testLine1 = board->getLine(1, 1, board->getPoint(0, 0, 0));
	Line* testLine2 = board->getLine(1, 1, board->getPoint(-1, 5, 0));

	if (testLine2 != NULL){
		testPasses = false;
		printf("\tfailed testSpaceGetLineNull subtest\n");
	} else {
		printf("\tpassed testSpaceGetLineNull subtest\n");
	}

	if (testLine1 == NULL || testLine1->getDeltaX() != 1 || testLine1->getDeltaY() != 1 || testLine1->getDeltaZ() != 1){
		testPasses = false;
		printf("\tfailed testSpaceGetLineDeltas subtest\n");
	} else {
		printf("\tpassed testSpaceGetLineDeltas subtest\n");
	}

	if (testLine1 == NULL || testLine1->getIntercept() != board->getPoint(0, 0, 0)){
		testPasses = false;
		printf("\tfailed testSpaceGetLineIntercept subtest\n");
	} else {
		printf("\tpassed testSpaceGetLineIntercept subtest\n");
	}

	if (testLine1 == NULL || !testLine1->containsPoint(board->getPoint(1, 1, 1)) || !testLine1->containsPoint(board->getPoint(2, 2, 2))){
		testPasses = false;
		printf("\tfailed testSpaceGetLineCotains subtest\n");
	} else {
		printf("\tpassed testSpaceGetLineCotains subtest\n");
	}

	if (testLine1 == NULL || testLine1->containsPoint(board->getPoint(1, 3, 1)) || testLine1->containsPoint(board->getPoint(2, 2, -1))){
		testPasses = false;
		printf("\tfailed testSpaceGetLineNotCotains subtest\n");
	} else {
		printf("\tpassed testSpaceGetLineNotCotains subtest\n");
	}

	if (testLine1 == NULL || testLine1->getNumOfPoints() != 3){
		testPasses = false;
		printf("\tfailed testSpaceGetLineLength subtest\n");
	} else {
		printf("\tpassed testSpaceGetLineLength subtest\n");
	}

	if (testLine1 == NULL || testLine1->getTotalValue() != (board->getPoint(0, 0, 0)->getValue() + board->getPoint(1, 1, 1)->getValue() + board->getPoint(2, 2, 2)->getValue())){
		testPasses = false;
		printf("\tfailed testSpaceGetLineValue subtest\n");
	} else {
		printf("\tpassed testSpaceGetLineValue subtest\n");
	}

	if (testPasses){
		printf("testSpaceGetLine Passed: successful passed all subtests\n");
	} else {
		printf("testSpaceGetLine Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::testSpaceGetAllLine(){
	printf("Starting testSpaceGetAllLine\n");
	bool testPasses = true;

	Space* board = new Space("finalSampleInput.txt");

	LinkedList<Line>* lineLists1 = board->getAllLines(board->getPoint(0, 0, 0));
	LinkedList<Line>* lineLists2 = board->getAllLines(board->getPoint(0, -3, 5));

	if (lineLists2->size != 0){
		testPasses = false;
		printf("\tfailed testSpaceGetAllLineNull subtest\n");
	} else {
		printf("\tpassed testSpaceGetAllLineNull subtest\n");
	}

	if (lineLists1->size != 4){
		testPasses = false;
		printf("\tfailed testSpaceGetAllLineLength subtest\n");
	} else {
		printf("\tpassed testSpaceGetAllLineLength subtest\n");
	}

	if (lineLists1->size != 4 || lineLists1->get(0)->points->size != 3 || lineLists1->get(1)->points->size != 3 || lineLists1->get(2)->points->size != 3 || lineLists1->get(3)->points->size != 3){
		testPasses = false;
		printf("\tfailed testSpaceGetAllLineSubLineLengths subtest\n");
	} else {
		printf("\tpassed testSpaceGetAllLineSubLineLengths subtest\n");
	}

	if (lineLists1->size != 4 || lineLists1->get(0) == lineLists1->get(1) || lineLists1->get(0) == lineLists1->get(2) || lineLists1->get(0) == lineLists1->get(3)){
		testPasses = false;
		printf("\tfailed testSpaceGetAllLineUnique subtest\n");
	} else {
		printf("\tpassed testSpaceGetAllLineUnique subtest\n");
	}

	if (testPasses){
		printf("testSpaceGetAllLine Passed: successful passed all subtests\n");
	} else {
		printf("testSpaceGetAllLine Failed: not all subtests passed\n");
	}

	printf("\n");

	return testPasses;
}

bool Tests::getYesNo(char* query)
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
