/*
 * Production.h
 *
 *  Created on: Oct 9, 2021
 *      Author: apietrick20
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol

#define FILENAMELENGTHALLOWANCE 50

class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
	bool getYesNo(char* query);

private:

};

#endif /* PRODUCTION_H_ */
