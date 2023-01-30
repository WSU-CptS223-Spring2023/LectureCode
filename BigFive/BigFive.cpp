#include "BigFive.h"

// constructor with default arguments; 
// also known as a default constructor
BigFive::BigFive(const char * const newString, const unsigned int newLength)
{
	std::cout << "Inside constructor!" << std::endl;

	this->mpString = new char[newLength];
	strcpy(this->mpString, newString);

	this->mLength = newLength;
}

// destructor
BigFive::~BigFive()
{
	std::cout << "Inside destructor!" << std::endl;

	if (this->mpString != nullptr)
	{
		delete[] this->mpString;
	}
}

// copy constructor
BigFive::BigFive(const BigFive& copy)
{
	std::cout << "Inside copy constructor!" << std::endl;

	// call copy assignment
	*this = copy;
}

// move constructor - move resources from rvalue to lvalue
BigFive::BigFive(BigFive&& obj)
{
	std::cout << "Inside move constructor!" << std::endl;

	this->mpString = obj.mpString;
	this->mLength = obj.mLength;
	
	obj.mpString = nullptr;
	obj.mLength = 0;
}

// copy assignment operator
BigFive& BigFive::operator= (const BigFive& rhs)
{
	std::cout << "Inside copy assignment operator!" << std::endl;

	// check for self-assignment
	if (this != &rhs)
	{
		this->mLength = rhs.mLength;
		this->mpString = new char[mLength];
		strcpy(this->mpString, rhs.mpString);
	}

	return *this;
}

// move assignment operator - move resources from rvalue to lvalue
BigFive& BigFive::operator= (BigFive&& rhs)
{
	std::cout << "Inside move assignment operator!" << std::endl;

	// check for self-assignment
	if (this != &rhs)
	{
		if (this->mpString != nullptr)
		{
			delete[] this->mpString; // free current resources held by *this* object
			this->mLength = 0;
		}

		// get the resources from the rhs object
		this->mpString = rhs.mpString;
		this->mLength = rhs.mLength;

		// reset the rhs object
		rhs.mpString = nullptr;
		rhs.mLength = 0;
	}

	return *this;
}

// getters for to access copies of the private data members
char* BigFive::getString() const
{
	return this->mpString; // are there concerns with how this is returned?
}

unsigned int BigFive::getLength() const
{
	return this->mLength;
}