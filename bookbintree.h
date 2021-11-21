
#ifndef BOOKBINTREE_H
#define BOOKBINTREE_H
#include "book.h"
#include <iostream>

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

class BookBinTree
{
	 //----------------------------------------------------------------------------
	 //operator<<(): Overloaded << to displays tree data using inorder traversal. 
	 //The appropriate Book class is responsible for dispslaying its own data. 
	 //Uses helper function - inorderHelper()
	 //Pre-conditions: Pass in ostream& object and BookBinTree& to be displayed.
	 //Post-conditions: Book objects' details are displayed inorder - defined by 
	 //the sorting criteria of the type of Book object
	 //BookBinTree remains unchanged.
	 friend ostream& operator<<(ostream&, const BookBinTree&); //uses inorderhelper() 

public:

	 //----------------------------------------------------------------------------
	 //BookBinTree(): Default constructor for BookBinTree
	 //Pre-conditions: None
	 //Post-conditions: BookBinTree is intialized, its root is set to NULL
	 BookBinTree();

	 //----------------------------------------------------------------------------
	 //~BookBinTree(): Destructor that deletes all Nodes in BookBinTree
	 //Pre-conditions: None
	 //Post-conditions: Data in BookBinTree is deleted from memory
	 ~BookBinTree();

	 //----------------------------------------------------------------------------
	 //insert(): Inserts Book object into BookBinTree 
	 //Pre-conditions:The function's argument must be a pointer to a book object of 
	 //the same type of book object that the BookBinTree holds book objects of
	 //Post-conditions: Book object of appropriate type is inserted into the tree in
	 //a location that abides by the rules of a Binary Search Tree. Function returns 
	 //true if book object was sucessfuly inserted, returns false if not
	 bool insert(Book*);

	 //----------------------------------------------------------------------------
	 //find(): Retrieves a book object from the BookBinTree
	 //Pre-conditions: The function's argument must be a reference to a book object 
	 //of the same type of book object that the BookBinTree holds book objects of
	 //Post-conditions: A pointer to a reference of the book object in the BookBinTree
	 //that has the same data as the reference of Book object passed in as an argument
	 //is returned
	 Book*& find(const Book&) const;

	 //----------------------------------------------------------------------------
	 //makeEmpty(): Deletes data from BookBinTree 
	 //Pre-conditions: None
	 //Post-conditions: BookBinTree is empty/does not contain any data
	 void makeEmpty();

	 //----------------------------------------------------------------------------
	 //isEmpty(): Determines if BookBinTree is empty
	 //Pre-conditions: None
	 //Post-conditions: Returns true if BookBinTree is empty, returns false
	 //if BookBinTree contains data 
	 bool isEmpty() const;

	 //----------------------------------------------------------------------------
	 //returnDataType(): Returns the private data field bookType of the Book objects
	 //that BookBinTree holds
	 //Pre-conditions: The BookBinTree is not empty, it contains Book objects of one
	 //of the possible Book types 
	 //Post-conditions: Returns an uppercase character corresponding to the type of 
	 //the book objects in the BookBinTree
	 char returnDataType() const;

private:

	 struct Node
	 {
		  Book* book;			//pointer to Book data object
		  Node* left;			//pointer to Node's left child node
		  Node* right;		//pointer to Node's right child node
	 };

	 Node* root;		//root of BookBinTree

	 //----------------------------------------------------------------------------
	 //inorderHelper(): Private helper function of operator<<, displays tree data
	 //via recursive inorder traversal
	 //Pre-conditions: Pointer to the root of the BookBinTree or root of subtree
	 //must be passed in as function's argument
	 //Post-conditions: Book objects' details are displayed inorder - defined by 
	 //the sorting criteria of the type of Book object
	 //BookBinTree remains unchanged.
	 void inorderHelper(Node*) const;	//recursive helper for operator<<

	 //----------------------------------------------------------------------------
	 //makeEmptyHelper(): Private helper function of makeEmpty. Recursively deletes 
	 //data in the BookBinTree.
	 //Pre-conditions: Pointer to reference of 'current' node is passed in as argument
	 //to keep track of position while traversing and emptying BookBinTree
	 //Post-conditions: BookBinTree is empty/does not contain any data
	 void makeEmptyHelper(Node*&);	//helper function for makeEmptyHelper function
};
#endif
