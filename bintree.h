/**
 * @file bintree.h
 * @brief BinTee Class Header file
 * A binary search tree structure that uses a Node class to hold a container
 * class called NodeData. Binary Tree class does not know the nature of or
 * deals with the NodeData class.
 * @author Amanda Todakonzie
 */
// -----------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "nodedata.h"
using namespace std;

class BinTree;

class Node {

public:
	Node();					//constructor
	~Node();				//destructor
	Node(NodeData* objPtr); // copy constructor
	NodeData* dataPtr;		// pointer to data object
	Node* left;				// left subtree pointer
	Node* right;			// right subtree pointer
};


// -----------------------------------------------------------------------------
class BinTree {
	friend class Node;
	// operator<<
	friend ostream& operator<<(ostream& out, const BinTree& T);

public:
	BinTree();				// constructor
	BinTree(const BinTree& toCopy); // copy constructor
	~BinTree();				// destructor, calls makeEmpty()
	bool isEmpty() const;	// true if tree is empty, otherwise false
	void makeEmpty(); // removes and deletes all tree nodes
	bool insert(NodeData* input); // inserts a Node of NodeData's input
	bool find(NodeData* target); // search for NodeData*
	bool retrieve(const NodeData&, NodeData*&) const;
	BinTree& operator=(const BinTree&); // assignment operator=
	bool operator==(const BinTree&) const;
	bool operator!=(const BinTree&) const;
	bool getSibling(const NodeData&, NodeData&) const;
	bool getParent(const NodeData&, NodeData&) const;
	void bstreeToArray(NodeData* []);
	void arrayToBSTree(NodeData* []);
	Node* createBalancedTree(NodeData* array[], int min, int max);
	void displaySideways() const; // displays the tree sideways

private:
	Node* root;		// root of the tree

	// utility functions
	Node* copyTree(const Node* treePtr) const; // copy constr & op= helper
	void destroy(Node*& nodePtr); // private destructor function
	Node* retrieveHelper(Node* root, NodeData target) const; //retrieve helper
	// equality helper function
	bool compare(Node* current, Node* compare) const;
	// recursive search helper for getSibling & getParent
	Node* preorderSearch(Node* curr, Node* prev, const NodeData& target) const;
	// recursive helper for operator<<
	void sidewaysHelper(Node* current, int level) const {
		if (current != nullptr) {
			level++;
			sidewaysHelper(current->right, level);
			// indent for readability, same number of spaces per depth level
			for (int i = level; i >= 0; i--) {
				cout << "      ";
			}
			cout << *current->dataPtr << endl; // display information of obj
			sidewaysHelper(current->left, level);
		}
	}
};
// -----------------------------------------------------------------------------

#endif
