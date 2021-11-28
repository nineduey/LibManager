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


//----------------------------------------------------------------------------
//operator<<(): Overloaded << to displays tree data using inorder traversal. 
//The appropriate Book class is responsible for dispslaying its own data. 
//Uses helper function - inorderHelper()
//Pre-conditions: Pass in ostream& object and BookBinTree& to be displayed.
//Post-conditions: Book objects' details are displayed inorder - defined by 
//the sorting criteria of the type of Book object
//BinTree remains unchanged.
ostream& operator<<(ostream& out, const BinTree& T) {
	 T.print(out);
	 return out;
}

//----------------------------------------------------------------------------
//BinTree(): Default constructor for BinTree
//Pre-conditions: None
//Post-conditions: BinTree is intialized, its root is set to NULL
BinTree::BinTree() : root(nullptr) {

}

//----------------------------------------------------------------------------
//~BinTree(): Destructor that deletes all Nodes in BinTree
//Pre-conditions: None
//Post-conditions: Data in BookBinTree is deleted from memory
BinTree::~BinTree() {
	 makeEmpty(root);
	 root = nullptr;
}


//----------------------------------------------------------------------------
//insert(): Inserts Book object into BinTree 
//Pre-conditions:The function's argument must be a pointer to a book object of 
//the same type of book object that the BookBinTree holds book objects of
//Post-conditions: Book object of appropriate type is inserted into the tree in
//a location that abides by the rules of a Binary Search Tree. Function returns 
//true if book object was sucessfuly inserted, returns false if not
bool BinTree::insert(Item* itemPtr) {
	 //search for duplicate first
	 if (find(itemPtr)) {
		  return false;
	 }

	 // create new node -- need to change to not create an item, since an item is already being passed
	 //Item* ptr = new Item;
	 // ptr->dataPtr = input;
	 //input = nullptr;
	 // ptr->left = ptr->right = nullptr;

	// check to see if BinTree is empty
	 if (isEmpty()) {
		  root = itemPtr;
	 }
	 else {
		  Item* current = root;
		  bool inserted = false;

		  // if item is less than current item, insert in left subtree
		  // otherwise insert in right subtree
		  while (!inserted) {
				if (*itemPtr < *current) { // virtual < on Item class' derived classes
					 // at leaf, insert left
					 if (current->left == nullptr) {
						  current->left = itemPtr;
						  inserted = true;
					 }
					 else	// one step left
						  current = current->left;
				}
				else {	// at leaf, insert right
					 if (current->right == nullptr) {
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
bool BinTree::find(Item* target) {
	 Item* current = root;
	 bool found = false;
	 while (!found) {
		  if (current == nullptr) { // if node is nullptr,end of branch
				break;
		  }
		  else if (*current == *target) { // compare data
				found = true;
				break;
		  }
		  else if (*target > *current) { // step right
				current = current->right;
		  }
		  else if (*target < *current) { // step left
				current = current->left;
		  }
	 }
	 return found;
}

//----------------------------------------------------------------------------
//retrieve(): Retrieves a book object from the BinTree
//Pre-conditions: The function's argument must be a reference to a book object 
//of the same type of book object that the BookBinTree holds book objects of
//Post-conditions: A pointer to a reference of the book object in the BookBinTree
//that has the same data as the reference of Book object passed in as an argument
//is returned
Item*& BinTree::retrieve(const Item* target) const {
	 // recursive helper to traverse tree looking for target
	 Item* retrieverPtr = retrieveHelper(root, target);
	 if (retrieverPtr != nullptr) {
		  return retrieverPtr;
	 }
	 cout << "Error: Item not found." << endl;
	 return retrieverPtr;
}


//----------------------------------------------------------------------------
//makeEmpty(): Deletes data from BinTree 
//Pre-conditions: None
//Post-conditions: BookBinTree is empty/does not contain any data
void BinTree::makeEmpty(Item*& itemPtr) {
	 if (itemPtr != nullptr) {
		  makeEmpty(itemPtr->left);
		  makeEmpty(itemPtr->right);
		  delete ptr;
	 }
}

//----------------------------------------------------------------------------
//isEmpty(): Determines if BinTree is empty
//Pre-conditions: None
//Post-conditions: Returns true if BookBinTree is empty, returns false
//if BookBinTree contains data 
bool BinTree::isEmpty() const {
	 if (root == nullptr) {
		  return true;
	 }
	 return false;
}

//----------------------------------------------------------------------------
//returnDataType(): Returns the private data field objectType of the Item objects
//that BookBinTree holds
//Pre-conditions: The BinTree is not empty, it contains Item objects
//Post-conditions: Returns an uppercase character corresponding to the type of 
//objects in the BookBinTree
char BinTree::returnObjectType() const {
	 return root->returnItemType();
}

//----------------------------------------------------------------------------
//retrieveHelper(): Private helper function of retrieve, recursively searches
// the Bintree to find target
// Pre-conditions: Pointer to an item needs to be passed in as arguement
// to keep track of root of Bintre, and another pointer referenced Item arguement
// which is the target
// Post-conditions: Returns an referenced Item pointer to the Item that was found
// in the BinTree
Item*& BinTree::retrieveHelper(const Item* current, const Item* target) const { //** Question: not sure if the Item* current needs to be passed in by reference?
																				// perhaps its more efficient?
	if (current == nullptr) {
		return nullptr;
	}
	else if (*current == target) {
		return current;
	}
	else if (*current > target) {
		return retrieveHelper(current->left, target);
	}
	else {
		return retrieveHelper(current->right, target);
	}
}

void BinTree::print(ostream& out) {
    stack<Item*> itemStack;
    Item* current = T.root;
    bool done = false;
        while (!done) {
            if (current != nullptr) {
                itemStack.push(current);
		current = current->left;
            }
            else {
                if (!itemStack.empty()) {
                    current = itemStack.top();
                    out << " " << *current;
                    itemStack.pop();
                    current = current->right;
                }
                else {
                    done = true;
                }
	    }
	}
   out << endl;
}


