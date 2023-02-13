#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <class T>
class Node
{
public:
	Node(Data<T> const &newData);

	Data<T> getData() const;
	Node<T> * getLeftPtr() const;
	Node<T> * getRightPtr() const;

	void setData(Data<T> const &newData);
	void setLeftPtr(Node<T> * const &newLeftPtr);
	void setRightPtr (Node<T> * const &newRightPtr);

private:
	Data<T> mData;//Data<int> mData;
	Node<T> *mpLeft;
	Node<T> *mpRight;
};

template <class T>
Node<T>::Node(Data<T> const &newData)
{
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
	this->mData = newData; // using overloaded assignment operator for Data? did we define it?
}

template<class T>
Data<T> Node<T>::getData() const
{
	return this->mData; // what happens here with the mData object? the copy constructor for a Data object is invoked to return it!
}

template<class T>
Node<T> * Node<T>::getLeftPtr() const
{
	return this->mpLeft;
}

template<class T>
Node<T> * Node<T>::getRightPtr() const
{
	return this->mpRight;
}

template<class T>
void Node<T>::setData(Data<T> const &newData)
{
	this->mData = newData; // using overloaded assignment operator for Data? did we define it?
}

template<class T>
void Node<T>::setLeftPtr(Node<T> * const &newLeftPtr)
{
	this->mpLeft = newLeftPtr;
}

template<class T>
void Node<T>::setRightPtr(Node<T> * const &newRightPtr)
{
	this->mpRight = newRightPtr;
}