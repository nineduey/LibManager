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
#include <iostream>
using namespace std;

//forward referencing for Item Class
class Item;

class BinTree
{
    friend class Item;
    // ostream<< operator
    friend ostream& operator<<(ostream&, const BinTree&);  

public:
    BinTree();        // Default Constructor
    ~BinTree();       // Destructor
    bool insert(Item*); // Inserts Book object into BinTree 
    bool find(Item*);   //Conducts a search an item object from the BinTree
    Item*& retrieve(const Item*) const; // Retrieves an Item from the BinTree
    bool isEmpty() const;               // Returns bool if BinTree is empty
    char returnItemType() const;      // Returns itemType within Item class

private:
    Item* root;		//root of BinTree
    void makeEmpty(Item*& ptr); // Deletes Items from BinTree
    //recursive helper for retrieve function
    Item*& retrieveHelper( const Item*, const Item*) const;
    void print(ostream& out);
};
#endif
