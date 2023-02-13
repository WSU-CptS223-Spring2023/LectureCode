#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <class T>
class BST
{
public:
	BST();

	Node<T> *getRootPtr() const;

	void insert(Data<T> const &newData); // will complete definition 10/12
	void inorderTraversal();

private:
	Node<T> *mpRoot;

	// helper
	void insert(Node<T> *pTree, Data<T> const &newData); 
	void inorderTraversal(Node<T> *pTree);

};

template <class T>
BST<T>::BST()
{
	this->mpRoot = nullptr;
}

template <class T>
Node<T> * BST<T>::getRootPtr() const
{
	return this->mpRoot;
}

template <class T>
void BST<T>::insert(Data<T> const &newData)
{
	insert(this->mpRoot, newData);
}

template <class T>
void BST<T>::insert(Node<T> *pTree, Data<T> const &newData)
{
	if (pTree != nullptr)
	{
		// right subtree
		if (newData > pTree->getData())
		{
			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new Node<T>(newData)); // note: we're constructing a new Node object with class template need <T>
			}
			else //recursive step
			{
				insert(pTree->getRightPtr(), newData);
			}

		}
		// we should check to see if the left and/or right
		// pointers are nullptrs

		else if (newData < pTree->getData())
		{
			// check left subtree
			if (pTree->getLeftPtr() != nullptr)
			{
				// have not found place to insert yet,
				// go futher down the left subtree
				insert(pTree->getLeftPtr(), newData);
			}
			else
			{
				// found place to insert in left subtree
				pTree->setLeftPtr(new Node<T>(newData)); // note: we're constructing a new Node object with class template need <T
			}
		}
		else // duplicates
		{
			cout << "Duplicate" << endl;
		}
	}
	else // pTree == nullptr
	{
		this->mpRoot = new Node<T>(newData); // note: we're constructing a new Node object with class template need <T
	}
}

template <class T>
void BST<T>::inorderTraversal()
{
	inorderTraversal(this->getRootPtr());
}

template <class T>
void BST<T>::inorderTraversal(Node<T> *pTree)
{
	if (pTree != nullptr)
	{
		// there are nodes to visit
		// 1. go left
		inorderTraversal(pTree->getLeftPtr());
		// 2. process the node
		cout << pTree->getData().getItem() << endl;
		// 3. go right
		inorderTraversal(pTree->getRightPtr());
	}
}