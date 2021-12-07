/*
@File contents: BinTree class function and variable declarations

@Purpose: Binary Search Tree to store and retrieve Item objects of a specific
book type

@Assumptions: The Book objects stored in the BookBinTree are properly intialized
and contain the data they need to determine where they should be store in the tree.

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: A BookBinTree object holds book objects which are all one
specfic type.Books objects are compared against other books objects in the
BookBinTree (if there are other books objects in the tree) and are stored in the
appropriate, sortedlocation. An inorder traversal of the tree displays the book
objects in sorted order.
*/
//-----------------------------------------------------------------------------

#ifndef BINTREE_H
#define BINTREE_H
#include "item.h"
#include <iostream>

//forward referencing for Item Class
class Item;

class BinTree
{
	friend class Item;
	struct Node;
	friend ostream& operator<<( ostream&, const BinTree& );

public:
	BinTree(); // Default Constructor
	~BinTree(); // Destructor
	bool isEmpty() const; // Returns boolean if BinTree is empty or not
	void makeEmpty(Node*&); // recursive delete helper
	bool insert( Item* ); // Inserts Book object into BinTree
	bool find( Item* ); //Conducts a search an item object from the BinTree
	// Retrieves an Item from the BinTree
	bool retrieve(Item* target, Item*& retrieverItem) const; 
	void printHeader();


private:

	struct Node {
		Item* itemPtr; // Pointer to Item object contained in Node
		Node* left; // Node's left child poitner
		Node* right; // Node's right child pointer
	};

	Node* root;		//root of BinTree
	Node* retrieveHelper(Node*&, Item*) const; // recursive retrive helper
	void print(ostream&) const;		 // private print method for ostream <<
};
#endif
