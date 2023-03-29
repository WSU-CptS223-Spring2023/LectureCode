#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};

// Traverse the tree in a preorder fashion and store nodes in a map
// corresponding to their level
void preorder(Node* root, int level, auto &map)
{
	// base case: empty tree
	if (root == nullptr) {
		return;
	}

	// insert the current node and its level into the map
	map[level].push_back(root->key);

	// recur for the left and right subtree by increasing the level by 1
	preorder(root->left, level + 1, map);
	preorder(root->right, level + 1, map);
}

// Recursive function to print level order traversal of a given binary tree
void levelOrderTraversal(Node* root)
{
	// create an empty map to store nodes between given levels
	unordered_map<int, vector<int>> map;

	// traverse the tree and insert its nodes into the map
	// corresponding to their level
	preorder(root, 1, map);

	// iterate through the map and print all nodes between given levels
	for (int i = 1; map[i].size() > 0; i++)
	{
		cout << "Level " << i << ": ";
		for (int j: map[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
}

int main()
{
	Node* root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);
	root->right->right->right = new Node(30);

	levelOrderTraversal(root);

	return 0;
}