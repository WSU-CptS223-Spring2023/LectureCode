#include "TestBigFive.h"

/*
	Test ID: Move Assignment Operator - MAO
	Unit: BigFive::operator= (BigFive&&)

	Description: test to determine if BigFive::operator= (BigFive&&)
				 correctly moves resources

	Test steps:
		1. Construct one BigFive object called bf1
		2. Assign an rvalue type BigFive object to bf1
		3. Conditionally evaluate the state of both objects

	Test data: rvalue string = "test string", length = 11 + 1 (the extra + 1 for the null character)

	Precondition: None
	Postcondition: None

	Expected result: the pointer from the rvalue is moved to bf1; the length from rvalue moved to bf1
	Actual result: the pointer from the rvalue is moved to bf1; the length from rvalue moved to bf1
	Status: passed
*/

void testBigFiveMoveAssignment(void)
{
	BigFive bf1{}; // {} may be used in C++ 11 and above

	const char* testString = "test string";
	bf1 = BigFive{testString, strlen(testString) + 1}; // rhs is a rvalue type

	if ((strcmp(bf1.getString(), testString)) == 0 && (bf1.getLength () == strlen(testString) + 1))
	{
		std::cout << "string and lengths match - test passed" << std::endl;
	}
	else
	{
		std::cout << "string or length doesn't match - test failed" << std::endl;
	}
	
	// could also use asserts - if the expression is true, no problem
	// if expression is false - test will abort
	assert((strcmp(bf1.getString(), testString)) == 0 && (bf1.getLength() == strlen(testString) + 1));
}