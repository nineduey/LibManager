#ifndef STORAGE_H
#define STORAGE_H
#include "bookbintree.h"
#include "book.h"
#include "periodical.h"
#include "fiction.h"
#include "children.h"

/*File contents: Function and variable declarations of the
Storge class
Purpose: Represents a linked list of BookBinTree objects,
each containing Book objects of a specific type of book.
Has functionality to append to the linked list, retrieve
a book object from one of the BookBinTree objects in the
linked list, and empty the linked list
Assumptions: None?
Authors:Shushmitha Radjaram, Phuong K Vu, Monica King, Amanda Todakonzie,
Brennan Richards
How code is used: A newly created book is inserted into the Library's catalogue
by calling the append() function. A book is retrieved from the Library's
catalogue by calling the retrieveBook() function.
*/

class Storage
{

public:

	 //----------------------------------------------------------------------------
	 // Storage (): The head and tail of the linked list are initialized to NULL
	 // Pre-conditions: None
	 // Postconditions: New Storage object is instantiated with its data members,
	 // head and tail, intialized to NULL. BookBinTree objects can now be inserted
	 //into the list
	 Storage();

	 //----------------------------------------------------------------------------
	 // ~Storage(): calls makeEmpty() function to delete nodes of linked list
	 // Pre-conditions: None
	 // Postconditions: Linked list's nodes are deleted
	 ~Storage();

	 //----------------------------------------------------------------------------
	 // makeEmpty(): Iteratively deletes each node of the linked list
	 // Pre-conditions: None
	 // Postconditions: Linked list's nodes are deleted
	 void makeEmpty();

	 //----------------------------------------------------------------------------
	 // append(): The function finds which BookBinTree object in the 
	 // linked list contains book object(s) of the same type of the book object 
	 // passed in as an argument. Once the corresponding BookBinTree 
	 // object it found, the book object is inserted in the tree. If a corresponding
	 // BookBinTree cannot be found, a new BookBinTree object that holds pointers of 
	 // book objects that are the same type as the argument is instantiated and 
	 // appended to the linked list
	 // Pre-conditions: None
	 // Postconditions: A book is added its corresponding BookBinTree, based on its
	 //type
	 void append(Book*);

	 //----------------------------------------------------------------------------
	 // retrieveBook(): Finds and returns a pointer to a reference of the book
	 // object stored inside one of the BookBinTree objects in the linked list that
	 // is a match with the book object of the pointer passed in
	 // Pre-conditions: None
	 // Postconditions: Pointer to reference of the book object that is equal to the 
	 // book object of the pointer passed in to the function is returned
	 Book*& retrieveBook(Book*);

private:

	 struct Node
	 {
		  //Node constructor
		  Node(BookBinTree* aBookBinTree)
		  {
				bookBinTreePtr = aBookBinTree; next = NULL;
		  }

		  BookBinTree* bookBinTreePtr;	//pointer to BookBinTree data object

		  Node* next;			//pointer to next node of current node in linked list
	 };

	 Node* head;						//pointer to head node of linked list
	 Node* tail;						//pointer to tail node of linked list

};
#endif
