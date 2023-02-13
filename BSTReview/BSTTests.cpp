#include "BSTTests.h"

void BSTTests::testInsertOnEmptyTree()
{
	Data<int> d1(20);
	// tree is empty
	this->tree.insert(d1);

	if (d1.getItem() == tree.getRootPtr()->getData().getItem())
	{
		cout << "Inserted data correctly!" << endl;
	}
	else
	{
		cout << "Warning: inserted data incorrectly!" << endl;

	}
}

void BSTTests::testClassTemplateDataConstruction()
{
	Data<int> d1(20);
	cout << d1.getItem() << endl;

	Data<string> d2("test");
	cout << d2.getItem() << endl;
//	std::vector<int> v1;
}