/*
@File contents: Function defintions and variable initializations of the
BinTree class

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
inorder traversal of the tree displays the item objects in sorted order.
*/
//-----------------------------------------------------------------------------
#include "bintree.h"
#include <stack>
using namespace std;


//----------------------------------------------------------------------------
// operator<<(): Overloaded << to displays tree data using inorder traversal.
// The appropriate Item class is responsible for dispslaying its own data.
// Uses helper function - inorderHelper()
// @Pre: Pass in ostream& object and BookBinTree& to be displayed.
// @Post: Book objects' details are displayed inorder - defined by
// the sorting criteria of the type of Item object
// BinTree remains unchanged.
ostream& operator<<( ostream& out, const BinTree& T )
{
	T.print( out );
	return out;
}

//----------------------------------------------------------------------------
// BinTree(): Default constructor for BinTree
// @Pre: None
// @Post: BinTree is intialized, its root is set to NULL
BinTree::BinTree() : root( nullptr ){}

//----------------------------------------------------------------------------
// ~BinTree(): Destructor that deletes all Nodes in BinTree
// @Pre: None
// @Post: Node containing Items in BookBinTree is deleted from memory
BinTree::~BinTree()
{
	makeEmpty( root );
	root = nullptr;
}

//----------------------------------------------------------------------------
// isEmpty(): Determines if BinTree is empty
// @Pre: None
// @Post: Returns true if BookBinTree is empty, returns false if BookBinTree
// contains data
bool BinTree::isEmpty() const
{
	if (root == nullptr)
	{
		return true;
	}
	return false;
}

//----------------------------------------------------------------------------
// makeEmpty(): Deletes Nodes containing Items from the BinTree
// @Pre: None
// @Post: BookBinTree is empty/does not contain any Nodes containing Itemsa
void BinTree::makeEmpty( Node*& ptr )
{
	if (ptr != nullptr)
	{
		makeEmpty( ptr->left );
		makeEmpty( ptr->right );
		delete ptr->itemPtr;
		ptr->itemPtr = nullptr;
		delete ptr;
		ptr = nullptr;
	}
}

//----------------------------------------------------------------------------
// insert(): Inserts Item object into BinTree
// @Pre: The function's argument must be a pointer to an item object or any of
// its derived classes
// @Post: Item object of appropriate type is inserted into the tree in
// a location that abides by the rules of a Binary Search Tree. Function returns
// true if item object was sucessfuly inserted, returns false if not
bool BinTree::insert( Item* toInsertPtr )
{
	//search for duplicate first
	if (find( toInsertPtr ))
	{
		cout << "ERROR: Insertion failed." << endl;
		toInsertPtr->printKeyInfo();
		cout << endl << "already exists." << endl;
		return false;
	}
	// check to see if BinTree is empty
	if (isEmpty())
	{
		root = new Node();
		root->itemPtr = toInsertPtr;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		Node* current = root;
		bool inserted = false;

		// if item is less than current item, insert in left subtree
		// otherwise insert in right subtree
		while (!inserted)
		{
			if (*toInsertPtr < *current->itemPtr)
			{ // virtual <  // at leaf, insert left
				if (current->left == nullptr)
				{
					Node* temp = new Node();
					temp->itemPtr = toInsertPtr;
					temp->left = nullptr;
					temp->right = nullptr;
					current->left = temp;
					inserted = true;
				}
				else	// one step left
					current = current->left;
			}
			else
			{	// at leaf, insert right
				if (current->right == nullptr)
				{
					Node* temp = new Node();
					temp->itemPtr = toInsertPtr;
					temp->left = nullptr;
					temp->right = nullptr;
					current->right = temp;
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
// find() : Conducts a search in the BinTree to find a particular Item
// @Pre: The function's arguments must be a pointer to an Item object or any of
// its derived classes
// @Post: Returns a boolean value determined by if the Item object is found that
// matches the target Item object passed in. Returns true if found, false if not
bool BinTree::find( Item* target )
{
	Node* current = root;
	bool found = false;
	while (!found)
	{
		if (current == nullptr)
		{ // if node is nullptr,end of branch
			break;
		}
		else if (*current->itemPtr == *target)
		{ // compare data
			found = true;
			break;
		}
		else if (*target > *current->itemPtr)
		{ // step right
			current = current->right;
		}
		else if (*target < *current->itemPtr)
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
bool BinTree::retrieve( Item* target, Item*& retrieverItem ) const
{
	Node* current = root;
	// if root is target, return root's itemPtr
	if (*root->itemPtr == *target)
	{
		retrieverItem = root->itemPtr;
		return true;
	}
	// call on recursive helper, returns Node*
	Node* retrieverNode = retrieveHelper( current, target );
	if (retrieverNode != nullptr)
	{
		retrieverItem = retrieverNode->itemPtr;
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// retrieveHelper(): Private helper function of retrieve(), recursively searches
// the Bintree to find target Item
// @Pre: Pointer to an Item object needs to be passed in as arguement
// to keep track of root of Bintree, and another pointer referenced Item arg
// which is the target
// @Post: Returns a Node pointer to the Item that was found
// in the BinTree
BinTree::Node* BinTree::retrieveHelper( Node*& current, Item* target ) const
{
	if (current == nullptr)
	{
		return current;
	}
	else if (*current->itemPtr == *target)
	{
		return current;
	}
	else if (*current->itemPtr > *target)
	{
		return retrieveHelper( current->left, target );
	}
	else
	{
		return retrieveHelper( current->right, target );
	}
}

//----------------------------------------------------------------------------
// printHeader(): method to call on Item's virtual printHeader() function
// @Pre: None
// @Post: Calls the printHeader() method of the Item class, displaying a Header
// for output formatting purposes
void BinTree::printHeader()
{
	root->itemPtr->printHeader();
	return;
}

//----------------------------------------------------------------------------
// print(): Private method for ostream operator<< to call on, when called to
// print the BinTree Item objects. This method uses a stack to perform an
// inorder traversal of the BinTree.
// @Pre: The functions takes a referecned ostream object
// @Post: The contents of the Node's Item pointers will be sent out to the
// ostream object, returns void.
void BinTree::print( ostream& out ) const
{
	stack<Node*> nodeStack;
	Node* current = root;
	bool done = false;
	while (!done)
	{
		if (current != nullptr)
		{
			nodeStack.push( current );
			current = current->left;
		}
		else
		{
			if (!nodeStack.empty())
			{
				current = nodeStack.top();
				out << " " << *current->itemPtr << endl;
				nodeStack.pop();
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
