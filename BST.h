#include <iostream>
#include "TreeNode.h"
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
public:
	BST(); // Default BST constructor
	TreeNode* getRoot(); // Returns myRoot
	bool search(const int &num); // Search function
	void insert(const int &num); // Insert function
	void remove(const int &num); // Remove function
	void inorder(ostream &out, TreeNode *node); // Inorder traversal function
	void postorder(ostream &out, TreeNode *node); // Postorder traversal function
	void preorder(ostream &out, TreeNode *node); // Preorder traversal function
private:
	TreeNode *myRoot; // Stores the address of the root of the BST
};
#endif
