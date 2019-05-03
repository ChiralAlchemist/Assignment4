#pragma once
#include <string>
#include <fstream>
struct TreeNode;
#include "QueType.h"
using namespace std;
enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };
class TreeType
{
public:
	TreeType();                     // constructor
	~TreeType();                    // destructor
	TreeType(const TreeType& originalTree);
	void operator=(const TreeType& originalTree);
	// copy constructor
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int GetLength() const;
	int GetItem(string item, bool& found);
	void PutItem(string item);
	void Insert(TreeNode *& tree, string item);
	void DeleteItem(string item);
	void ResetTree(OrderType order);
	string GetNextItem(OrderType order, bool& finished);
	void Print(std::ostream& outFile) const;
private:
	TreeNode* root;
	int length; 
	QueType preQue;
	QueType inQue;
	QueType postQue;
};

