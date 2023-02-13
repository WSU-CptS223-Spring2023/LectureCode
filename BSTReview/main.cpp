#include "Node.h"
#include "BST.h"
#include "BSTTests.h"

int main(void)
{
	BSTTests test;

	test.testClassTemplateDataConstruction();
	test.testInsertOnEmptyTree();

	Data<int> d1(20), d2(10), d3(30);
	Node<int> n1(d1);
	BST<int> tree; // empty tree - the compiler will generate code that replaces all T types with int types

	tree.insert(d1); // insert into empty tree
	tree.insert(d2); // insert into left subtree
	tree.insert(d3);
	cout << "Result of inorder traversal: " << endl;
	tree.inorderTraversal();
	////if (tree.)

	//d2 = n1.getData(); // when the data is returned from getData (), which function is called here? the copy constructor for a Data object!

	return 0;
}