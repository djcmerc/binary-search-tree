#include "BST.h"

BST::BST() // Initializes the pointer to the root to zero
	: myRoot(0)
{}

TreeNode* BST::getRoot() // Returns myRoot
{
	return myRoot;
}

bool BST::search(const int &num) // Searches the BST for a user inputted number
{
	TreeNode *searchPtr = myRoot;

	while (searchPtr != 0) // Traverses the tree
	{
		if (num < searchPtr->item) // Traverses left
			searchPtr = searchPtr->Lchild;
		else if (num > searchPtr->item) // Traverses right
			searchPtr = searchPtr->Rchild;
		else // Value has been found
			return true;
	}
	return false; // Value was not found
}

void BST::insert(const int &num) // Inserts a user inputted number into the BST
{
	TreeNode *newPtr = new TreeNode(num), *insertPtr = myRoot, *prevPtr = myRoot;

	if (myRoot == 0) // First insert into BST
		myRoot = newPtr;
	else // Already number in the BST
	{
		while (insertPtr != 0) // Traverses the BST
		{
			prevPtr = insertPtr;
			if (num < insertPtr->item) // Traverses left
				insertPtr = insertPtr->Lchild;
			else if (num > insertPtr->item) // Traverses right
				insertPtr = insertPtr->Rchild;
			else // Number already exists in the BST
			{
				cout << "This number is already in the tree." << endl;
				return;
			}
		}
		if (prevPtr->item < num) // Inserts the number to the right of the previous node
			prevPtr->Rchild = newPtr;
		else if (prevPtr->item > num) // Inserts the number to the left of the previous node
			prevPtr->Lchild = newPtr;
	}
}

void BST::remove(const int &num) // Removes a user inputted number from the BST
{
	TreeNode *removePtr = myRoot, *prevPtr = 0, *lastPtr = 0;

	if (myRoot == 0) // Case where BST is empty
	{
		cout << "There are no elements in the tree." << endl;
	}
	else if (removePtr->Lchild == 0 && removePtr->Rchild == 0) // Case where one node left in BST
	{
		if (num != removePtr->item) // Case where number to be remove is not the last node
		{
			cout << "The number does not exist in the BST" << endl;
		}
		else
			myRoot = 0;
	}
	else // BST contains elements
	{
		while (removePtr != 0) // Traverses the BST
		{
			if (num < removePtr->item) // Traverses left
			{
				prevPtr = removePtr;
				removePtr = removePtr->Lchild;
			}
			else if (num > removePtr->item) // Traverses right
			{
				prevPtr = removePtr;
				removePtr = removePtr->Rchild;
			}
			else // Number is found
			{
				if (removePtr->Lchild != 0) // Node exists to the left of the number being removed
				{
					prevPtr = removePtr;
					lastPtr = removePtr;
					removePtr = removePtr->Lchild; // Traverses left once
					while (removePtr->Rchild != 0) // Traverses right
					{
						lastPtr = removePtr;
						removePtr = removePtr->Rchild;
					}
					prevPtr->item = removePtr->item;
					if (lastPtr != prevPtr) // Case where there is a value to the left once and a value to the right
						lastPtr->Rchild = 0;
					if (lastPtr == prevPtr) // Case where there is a value to the left once and no values on the right
						lastPtr->Lchild = 0;
					// Case where multiple values to left and none on the right
					if (removePtr->Lchild != 0 && removePtr->Rchild == 0 && lastPtr == prevPtr) 
						lastPtr->Lchild = removePtr->Lchild;
					// Case where there is a value to the left once, values to the right, and a value to the left once again
					if (removePtr->Lchild != 0 && removePtr->Rchild == 0 && lastPtr != prevPtr) 
						lastPtr->Rchild = removePtr->Lchild;
				}
				else if (removePtr->Rchild != 0) // Node exists to the right of the number being removed
				{
					prevPtr = removePtr;
					lastPtr = removePtr;
					removePtr = removePtr->Rchild; // Traverses right once
					while (removePtr->Lchild != 0) // Traverses left
					{
						lastPtr = removePtr;
						removePtr = removePtr->Lchild;
					}
					prevPtr->item = removePtr->item;
					if (lastPtr != prevPtr) // Case where there is a value to the right once and a value to the left
						lastPtr->Lchild = 0;
					if (lastPtr == prevPtr) // Case where there is a value to the right once and no values on the left
						lastPtr->Rchild = 0;
					// Case where multiple values to the right and none on the left
					if (removePtr->Rchild != 0 && removePtr->Lchild == 0 && lastPtr == prevPtr)
						lastPtr->Rchild = removePtr->Rchild;
					// Case where there is a value to the right once, values to the left, and a value to the right once again
					if (removePtr->Rchild != 0 && removePtr->Lchild == 0 && lastPtr != prevPtr)
						lastPtr->Lchild = removePtr->Rchild;
				}
				else // Node has no children
				{
					if (prevPtr->Lchild == removePtr) // Removes left leaf from BST
						prevPtr->Lchild = 0;
					else if (prevPtr->Rchild == removePtr) // Removes right leaf from BST
						prevPtr->Rchild = 0;
				}
				delete removePtr;
				return;
			}
		}
		cout << "The number does not exist in the BST" << endl;
	}
}

void BST::inorder(ostream &out, TreeNode *node) // Inorder traversal and display
{
	if (node != 0) // If node is not empty
	{
		inorder(out, node->Lchild);
		out << node->item << " ";
		inorder(out, node->Rchild);
	}
}

void BST::postorder(ostream &out, TreeNode *node) // Postorder traversal and display
{
	if (node != 0) // If node is not empty
	{
		postorder(out, node->Lchild);
		postorder(out, node->Rchild);
		out << node->item << " ";
	}
}

void BST::preorder(ostream &out, TreeNode *node) // Preorder traversal and display
{
	if (node != 0) // If node is not empty
	{
		out << node->item << " ";
		preorder(out, node->Lchild);
		preorder(out, node->Rchild);
	}
}
