/*
@File contents: BinTree.cpp function definitions
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
*/
//-----------------------------------------------------------------------------
#include "bintree.h"
#include "item.h"
#include <stack>
using namespace std;


//----------------------------------------------------------------------------
//operator<<(): Overloaded << to displays tree data using inorder traversal.
//The appropriate Book class is responsible for dispslaying its own data.
//Uses helper function - inorderHelper()
//Pre-conditions: Pass in ostream& object and BookBinTree& to be displayed.
//Post-conditions: Book objects' details are displayed inorder - defined by
//the sorting criteria of the type of Book object
//BinTree remains unchanged.
ostream& operator<<( ostream& out, const BinTree& T )
{
	T.print( out );
	return out;
}

//----------------------------------------------------------------------------
//BinTree(): Default constructor for BinTree
//Pre-conditions: None
//Post-conditions: BinTree is intialized, its root is set to NULL
BinTree::BinTree() : root( nullptr )
{

}

//----------------------------------------------------------------------------
//~BinTree(): Destructor that deletes all Nodes in BinTree
//Pre-conditions: None
//Post-conditions: Data in BookBinTree is deleted from memory
BinTree::~BinTree()
{
	makeEmpty( root );
	root = nullptr;
}


//----------------------------------------------------------------------------
//insert(): Inserts Book object into BinTree
//Pre-conditions:The function's argument must be a pointer to a book object of
//the same type of book object that the BookBinTree holds book objects of
//Post-conditions: Book object of appropriate type is inserted into the tree in
//a location that abides by the rules of a Binary Search Tree. Function returns
//true if book object was sucessfuly inserted, returns false if not
bool BinTree::insert( Item* itemPtr )
{
	//search for duplicate first
	if (find( itemPtr ))
	{
		return false;
	}
	// check to see if BinTree is empty
	if (isEmpty())
	{
		root = itemPtr;
	}
	else
	{
		Item* current = root;
		bool inserted = false;

		// if item is less than current item, insert in left subtree
		// otherwise insert in right subtree
		while (!inserted)
		{
			if (*itemPtr < *current)
			{ // virtual <
// at leaf, insert left
				if (current->left == nullptr)
				{
					current->left = itemPtr;
					inserted = true;
				}
				else	// one step left
					current = current->left;
			}
			else
			{	// at leaf, insert right
				if (current->right == nullptr)
				{
					current->right = itemPtr;
					inserted = true;
				}
				else	// one step right
					current = current->right;
			}
		}
	}
	return true;
}

//----------------------------------------------------------------------------
//find() : Conducts a search in the BinTree to find a particular Item
//Pre:
//Post:
bool BinTree::find( Item* target )
{
	Item* current = root;
	bool found = false;
	while (!found)
	{
		if (current == nullptr)
		{ // if node is nullptr,end of branch
			break;
		}
		else if (*current == *target)
		{ // compare data
			found = true;
			break;
		}
		else if (*target > *current)
		{ // step right
			current = current->right;
		}
		else if (*target < *current)
		{ // step left
			current = current->left;
		}
	}
	return found;
}

//----------------------------------------------------------------------------
//retrieve(): Retrieves a book object from the BinTree
//Pre-conditions: The function's argument must be a reference to a book object
//of the same type of book object that the BookBinTree holds book objects of
//Post-conditions: A pointer to a reference of the book object in the
// BookBinTree that has the same data as the reference of Book object passed in
// as an argument is returned
Item*& BinTree::retrieve( Item* target ) const
{
	// recursive helper to traverse tree looking for target
	Item* current = root;
	//Item* retrieverPtr = retrieveHelper( current, target );
	if (retrieveHelper( current, target ) != nullptr)
	{
		return retrieveHelper( current, target );
	}
	cout << "Error: Item not found." << endl;
	return retrieveHelper( current, target );
}

//----------------------------------------------------------------------------
//isEmpty(): Determines if BinTree is empty
//Pre-conditions: None
//Post-conditions: Returns true if BookBinTree is empty, returns false
//if BookBinTree contains data 
bool BinTree::isEmpty() const
{
	if (root == nullptr)
	{
		return true;
	}
	return false;
}

//----------------------------------------------------------------------------
//makeEmpty(): Deletes data from BinTree
//Pre-conditions: None
//Post-conditions: BookBinTree is empty/does not contain any data
void BinTree::makeEmpty( Item*& ptr )
{
	if (ptr != nullptr)
	{
		makeEmpty( ptr->left );
		makeEmpty( ptr->right );
		delete ptr;
	}
}

//----------------------------------------------------------------------------
//returnItemType():
//Pre-conditions:
//Post-conditions:
char BinTree::returnItemType() const
{
	return root->returnItemType();
}

//----------------------------------------------------------------------------
//returnItemType_Genre():
//Pre-conditions:
//Post-conditions: 
char BinTree::returnItemType_Genre() const
{
	return root->returnItemType_Genre();
}

//----------------------------------------------------------------------------
//retrieveHelper(): Private helper function of retrieve, recursively searches
// the Bintree to find target
// Pre-conditions: Pointer to an item needs to be passed in as arguement
// to keep track of root of Bintre, and another pointer referenced Item arg
// which is the target
// Post-conditions: Returns a referenced Item pointer to the Item that was found
// in the BinTree
Item*& BinTree::retrieveHelper( Item*& current, Item* target ) const
{

	if (current == nullptr)
	{
		return current;
	}
	else if (*current == *target)
	{
		return current;
	}
	else if (*current > *target)
	{
		return retrieveHelper( current->left, target );
	}
	else
	{
		return retrieveHelper( current->right, target );
	}
}

//----------------------------------------------------------------------------
//print(): Private method for ostream operator<< to call on, when called to
// print the BinTree object
//Pre-conditions:
//Post-conditions:
void BinTree::print( ostream& out ) const
{
	stack<Item*> itemStack;
	Item* current = root;
	bool done = false;
	while (!done)
	{
		if (current != nullptr)
		{
			itemStack.push( current );
			current = current->left;
		}
		else
		{
			if (!itemStack.empty())
			{
				current = itemStack.top();
				out << " " << *current;
				itemStack.pop();
				current = current->right;
			}
			else
			{
				done = true;
			}
		}
	}
	out << endl;
}