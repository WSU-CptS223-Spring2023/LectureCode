#pragma once

#include <cassert>
#include "BigFive.h"

/*       
	Test ID: Move Assignment Operator - MAO
	Unit: BigFive::operator= (BigFive&&)

	Description: test to determine if BigFive::operator= (BigFive&&) 
				 correctly moves resources

	Test steps:
		1. Construct one BigFive object called bf1
		2. Assign an rvalue type BigFive object to bf1
		3. Conditionally evaluate the state of both objects

	Test data: bf1 string = "test string", length = 11 + 1 (the extra + 1 for the null character)

	Precondition: None
	Postcondition: None

	Expected result: the pointer from the rvalue is moved to bf1; the length from rvalue moved to bf1
	Actual result: the pointer from the rvalue is moved to bf1; the length from rvalue moved to bf1
	Status: passed
*/

void testBigFiveMoveAssignment(void);