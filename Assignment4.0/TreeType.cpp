#include "pch.h"
#include "TreeType.h"

struct TreeNode
{
	string info;
	int frequency;
	TreeNode* left;
	TreeNode* right;
};

bool TreeType::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
	TreeNode* location;
	try
	{
		location = new TreeNode;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

bool TreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
	return root == NULL;
}

int CountNodes(TreeNode* tree);

int TreeType::GetLength() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
	return CountNodes(root);
}


int CountNodes(TreeNode* tree)
// Post: returns the number of nodes in the tree.
{
	if (tree == NULL)
		return 0;
	else
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

TreeNode* Retrieve(TreeNode* tree,
	string& item, bool& found);

int TreeType::GetItem(string item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
	TreeNode* i = Retrieve(root, item, found);
	if (found == false)
	{
		return -1;
	}
	return i->frequency;
}


TreeNode* Retrieve(TreeNode* tree,
	string& item, bool& found)
	// Recursively searches tree for item.
	// Post: If there is an element someItem whose key matches item's,
	//       found is true and item is set to a copy of someItem; 
	//       otherwise found is false and item is unchanged.
{
	if (tree == NULL)
	{
		found = false;
		return NULL;// item is not found.
	}
	else if (item < tree->info)
	{
		return Retrieve(tree->left, item, found); // Search left subtree.
	}
	else if (item > tree->info)
	{
		return Retrieve(tree->right, item, found);// Search right subtree.
	}
	else
	{
		item = tree->info;                 // item is found.
		found = true;
		return tree;
	}
}

void Insert(TreeNode*& tree, string item);

void TreeType::PutItem(string item)
// Calls recursive function Insert to insert item into tree.
{
	Insert(root, item);
}


void TreeType::Insert(TreeNode*& tree, string item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
	if (tree == NULL)
	{// Insertion place found.
		tree = new TreeNode;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
		tree->frequency = 1;
		length++;
	}
	else if (item == tree->info)
	{
		tree->frequency++;
	}
	else if (item < tree->info)
	{
		Insert(tree->left, item);    // Insert in left subtree.
	}
	else
	{
		Insert(tree->right, item); // Insert in right subtree.
	}
}
void DeleteNode(TreeNode*& tree);

void Delete(TreeNode*& tree, string item);

void TreeType::DeleteItem(string item)
// Calls recursive function Delete to delete item from tree.
{
	Delete(root, item);
}


void Delete(TreeNode*& tree, string item)
// Deletes item from tree.
// Post:  item is not in tree.
{
	if (item < tree->info)
		Delete(tree->left, item);   // Look in left subtree.
	else if (item > tree->info)
		Delete(tree->right, item);  // Look in right subtree.
	else
		DeleteNode(tree);           // Node found; call DeleteNode.
}

void GetPredecessor(TreeNode* tree, string& data);

void DeleteNode(TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
{
	string data;
	TreeNode* tempPtr;

	tempPtr = tree;
	if (tree->left == NULL)
	{
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == NULL)
	{
		tree = tree->left;
		delete tempPtr;
	}
	else
	{
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);  // Delete predecessor node.
	}
}

void GetPredecessor(TreeNode* tree, string& data)
// Sets data to the info member of the right-most node in tree.
{
	while (tree->right != NULL)
		tree = tree->right;
	data = tree->info;
}

void PrintTree(TreeNode* tree, std::ostream& outFile)
// Prints info member of items in tree in sorted order on outFile.
{
	if (tree != NULL)
	{
		PrintTree(tree->left, outFile);// Print left subtree.
		outFile << " word is ";
		outFile << tree->info;
		outFile << tree->frequency;
		outFile << std::endl;
		PrintTree(tree->right, outFile);  // Print right subtree.
	}
}

void TreeType::Print(std::ostream& outFile) const
// Calls recursive function Print to print items in the tree.
{
	PrintTree(root, outFile);
}

TreeType::TreeType()
{
	root = NULL;
}

void Destroy(TreeNode*& tree);

TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
	Destroy(root);
}


void Destroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
	if (tree != NULL)
	{
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}

void TreeType::MakeEmpty()
{
	Destroy(root);
	root = NULL;
}


void CopyTree(TreeNode*& copy,
	const TreeNode* originalTree);

TreeType::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
//  into root.
{
	CopyTree(root, originalTree.root);
}

void TreeType::operator=
(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
// into root.
{
	{
		if (&originalTree == this)
			return;             // Ignore assigning self to self
		Destroy(root);      // Deallocate existing tree nodes
		CopyTree(root, originalTree.root);
	}

}
void CopyTree(TreeNode*& copy,
	const TreeNode* originalTree)
	// Post: copy is the root of a tree that is a duplicate 
	//       of originalTree.
{
	if (originalTree == NULL)
		copy = NULL;
	else
	{
		copy = new TreeNode;
		copy->info = originalTree->info;
		CopyTree(copy->left, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}
}
// Function prototypes for auxiliary functions.

void PreOrder(TreeNode*, QueType&);
// Enqueues tree items in preorder.


void InOrder(TreeNode*, QueType&);
// Enqueues tree items in inorder.


void PostOrder(TreeNode*, QueType&);
// Enqueues tree items in postorder.


void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
	switch (order)
	{
	case PRE_ORDER: PreOrder(root, preQue);
		break;
	case IN_ORDER: InOrder(root, inQue);
		break;
	case POST_ORDER: PostOrder(root, postQue);
		break;
	}
}


void PreOrder(TreeNode* tree,
	QueType& preQue)
	// Post: preQue contains the tree items in preorder.
{
	if (tree != NULL)
	{
		preQue.Enqueue(tree->info);
		PreOrder(tree->left, preQue);
		PreOrder(tree->right, preQue);
	}
}


void InOrder(TreeNode* tree,
	QueType& inQue)
	// Post: inQue contains the tree items in inorder.
{
	if (tree != NULL)
	{
		InOrder(tree->left, inQue);
		inQue.Enqueue(tree->info);
		InOrder(tree->right, inQue);
	}
}


void PostOrder(TreeNode* tree,
	QueType& postQue)
	// Post: postQue contains the tree items in postorder.
{
	if (tree != NULL)
	{
		PostOrder(tree->left, postQue);
		PostOrder(tree->right, postQue);
		postQue.Enqueue(tree->info);
	}
}


string TreeType::GetNextItem(OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true; 
//       otherwise finished is false.
{
	finished = false;
	string item;
	switch (order)
	{
	case PRE_ORDER: preQue.Dequeue(item);
		if (preQue.IsEmpty())
			finished = true;
		break;
	case IN_ORDER: inQue.Dequeue(item);
		if (inQue.IsEmpty())
			finished = true;
		break;
	case  POST_ORDER: postQue.Dequeue(item);
		if (postQue.IsEmpty())
			finished = true;
		break;
	}
	return item;
}



