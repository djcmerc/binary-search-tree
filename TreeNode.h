#include <cstddef>

#ifndef TREENODE
#define TREENODE

class TreeNode
{
	friend class BST;
public:
	TreeNode();  // Default TreeNode constructor
	TreeNode(int i, TreeNode* L, TreeNode* R); // Explicit value constructor
	int getItem() const; // Accessor function
private:
	int item;
	TreeNode *Lchild;
	TreeNode *Rchild;
};

inline TreeNode::TreeNode() 
{
	Lchild = Rchild = NULL; // Initializes left and right pointers to NULL
}

inline TreeNode::TreeNode(int i, TreeNode* L = 0, TreeNode* R = 0) 
	: item(i), Lchild(L), Rchild(R) // Inserts value of "i" into a new node and initializes Lchild and Rchild to zero
{}

inline int TreeNode::getItem() const
{
	return item; 
}
#endif
