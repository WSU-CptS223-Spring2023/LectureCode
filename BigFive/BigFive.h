#pragma once

#include <iostream>
#include <cstring>
#include <vector>

class BigFive
{
public:
	// constructor with default arguments; 
	// also known as a default constructor
	BigFive(const char * const newString = "", const unsigned int newLength = 1);

	// destructor
	~BigFive();

	// copy constructor
	BigFive(const BigFive& copy);

	// move constructor
	explicit BigFive(BigFive&& obj);

	// copy assignment operator
	BigFive& operator= (const BigFive& rhs);

	// move assignment operator
	BigFive& operator= (BigFive&& rhs);

	// getters for to access copies of the private data members
	char* getString() const;
	unsigned int getLength() const;

private:
	char* mpString;
	unsigned int mLength;
};