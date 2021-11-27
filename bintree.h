
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
using namespace std;

/*File contents: Function and variable declarations of the BookBinTree class
Purpose: Binary Search Tree to store and retrieve Book objects of a specific
book type
Assumptions: The Book objects stored in the BookBinTree are properly intialized
and contain the data they need to determine where they should be store in the tree.
Authors: Shushmitha Radjaram, Phuong K Vu, Monica King, Amanda Todakonzie,
Brennan Richards
How code is used: A BookBinTree object holds book objects which are all one
specfic type.Books objects are compared against other books objects in the
BookBinTree (if there are other books objects in the tree) and are stored in the
appropriate, sortedlocation. An inorder traversal of the tree displays the book
objects in sorted order.
*/

//forward referencing for Item Class
class Item;

class BinTree
{

	 friend class Item;

	 friend ostream& operator<<(ostream&, const BinTree&); // ostream<< operator, uses inorderhelper() 

public:
	 BinTree(); // Default Constructor
	 ~BinTree(); // Destructor

	 bool insert(Item*); // Inserts Book object into BinTree 
	 bool find(Item*); //Conducts a search an item object from the BinTree
	 Item*& retrieve(const Item*) const; // Retrieves an Item from the BinTree - **QUESTION: Does this param need to be passed by reference? My code only passes in a pointer
	 void makeEmpty(Item*& ptr); // Deletes Items from BinTree
	 bool isEmpty() const; // Returns boolean if BinTree is empty or not
	 char returnObjectType() const; // Returns  bookType within Book class

private:

	 Item* root;		//root of BinTree

	 //----------------------------------------------------------------------------
	 //inorderHelper(): Private helper function of operator<<, displays tree data
	 //via recursive inorder traversal
	 //Pre-conditions: Pointer to the root of the BookBinTree or root of subtree
	 //must be passed in as function's argument
	 //Post-conditions: Book objects' details are displayed inorder - defined by 
	 //the sorting criteria of the type of Book object
	 //BookBinTree remains unchanged.
	 void inorderHelper(Item*) const;	//recursive helper for operator<<

	 //----------------------------------------------------------------------------
	 //makeEmptyHelper(): Private helper function of makeEmpty. Recursively deletes 
	 //data in the BookBinTree.
	 //Pre-conditions: Pointer to reference of 'current' node is passed in as argument
	 //to keep track of position while traversing and emptying BookBinTree
	 //Post-conditions: BookBinTree is empty/does not contain any data
	 void makeEmptyHelper(Item*&);	//helper function for makeEmptyHelper function

	 //----------------------------------------------------------------------------
	 //retrieveHelper(): Private helper function of retrieve, recursively searches
	 // the Bintree to find target
	 // Pre-conditions: Pointer to an item needs to be passed in as arguement
	 // to keep track of root of Bintre, and another pointer referenced Item arguement
	 // which is the target
	 // Post-conditions: Returns an referenced Item pointer to the Item that was found
	 // in the BinTree
	 Item*& retrieveHelper( const Item*, const Item*) const;
};
#endif
