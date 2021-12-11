/*
@File contents: BinTree class function and variable declarations

@Purpose: The BinTree class is a Binary Search Tree structure used to store and
retrieve Item objects of a specific type. Item is the Base class for an
assortment of different types and genres of items held in the library. For our
design, Book is a derived class of Item, thus the BinTree will hold Book objects
and any type of derived classes of Book. The BinTree acts as a container for
Item, BinTree does not know or share information about Item.

@Assumptions: The Item objects stored in the BinTree are properly
intialized and contain the data they need to determine where they should
be store in the tree.

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: A BinTree object holds Nodes that contain Item objects. In
our design, Item class is an abstract class that holds minimal information about
a certain item stored in the library's catalogue of items. Item objects are
compared against other item objects in the BinTree (if there are other item
objects in the tree) and are stored in the appropriate, sortedlocation. An
inorder traversal of the tree displays the item objects in sorted ord
*/
//-----------------------------------------------------------------------------

#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "item.h"

class BinTree
{
	struct Node;
	friend ostream& operator<<( ostream&, const BinTree& );

public:
	BinTree(); // Default Constructor
	~BinTree(); // Destructor
	bool isEmpty() const; // Returns boolean if BinTree is empty or not
	void makeEmpty( Node*& ); // Recursive delete helper
	bool insert( Item* ); // Inserts Book object into BinTree
	bool find( Item* ); // Finds an item object from the BinTree
	// Retrieves an Item from the BinTree
	bool retrieve( Item* target, Item*& retrieverItem ) const;
	void printHeader(); // print method to print the specialized 
	//header for a particular type of Item being stored in the BinTree


private:

	struct Node
	{
		Item* itemPtr; // Pointer to Item object contained in Node
		Node* left; // Node's left child poitner
		Node* right; // Node's right child pointer
	};

	Node* root;		//root of BinTree
	Node* retrieveHelper( Node*&, Item* ) const; // recursive retrive helper
	void print( ostream& ) const;		 // private print method for ostream <<
};

#endif
