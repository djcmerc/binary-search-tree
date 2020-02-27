#include <iostream>
#include "BST.h"
#include "TreeNode.h"
using namespace std;

bool menu(BST &bst);

int main()
{
	BST bst;

	cout << "Binary Search Tree" << endl << endl;
	while (menu(bst));

	return 0;
}

// Menu
bool menu(BST &bst)
{
	int choice, value;

	cout << "What would you like to do?" << endl;
	cout << "1) Insert a number into the BST" << endl;
	cout << "2) Delete a number from the BST" << endl;
	cout << "3) Search for an element in the BST" << endl;
	cout << "4) Print the contents of the tree in a preorder fashion" << endl;
	cout << "5) Print the contents of the tree in an inorder fashion" << endl;
	cout << "6) Print the contents of the tree in a postorder fashion" << endl;
	cout << "7) End the program" << endl;
	do // Checks for invalid user input
	{
		cout << "Enter your choice (1-7): ";
		cin >> choice;
		if (choice < 1 || choice > 7)
			cout << "Please enter a valid choice from the given menu." << endl;
	} while (choice < 1 || choice > 7);

	switch (choice) // Runs corresponding function based on user input
	{
	case 1: // Insert
		cout << "Enter a value to insert into the BST: ";
		cin >> value;
		bst.insert(value);
		cout << endl;
		break;
	case 2: // Delete
		cout << "Enter a value to delete from the BST: ";
		cin >> value;
		bst.remove(value);
		cout << endl;
		break;
	case 3: // Search
		cout << "Enter a value to search for: ";
		cin >> value;
		if (bst.search(value))
			cout << "The number exists in the BST" << endl << endl;
		else
			cout << "The number does not exist in the BST" << endl << endl;
		break;
	case 4: // Preorder traversal and display
		bst.preorder(cout, bst.getRoot());
		cout << endl << endl;
		break;
	case 5: // Inorder traversal and display
		bst.inorder(cout, bst.getRoot());
		cout << endl << endl;
		break;
	case 6: // Postorder traversal and display
		bst.postorder(cout, bst.getRoot());
		cout << endl << endl;
		break;
	case 7: // Exit
		return false;
	}
	return true;
}
