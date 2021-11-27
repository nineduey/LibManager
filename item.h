#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Book;

// This is the class will take the place of Nodes that will be stores
// in the BinTree class. The Items that held in the BinClass will hold a NodeData
// pointer which for this assignment will point to a book. This design is extensible, 
// such as adding another class called Music, the NodeData objects could point to a 
// Music object instead of a Book object. This allows different BinTrees
// to be built, holding specific kinds of Node Data derived classes
class Item {

	 friend class BinTree;

protected: // not sure of the purpose of protected here?
	 bool validate() const; // check whether the input content is valid - **QUESTION: not sure how this is used? this was in book.h? should this stay in book.h?

public:

	 Item(); // default constructor
	 ~Item(); // destructor
	 void checkOut();
	 void checkIn();
	 char returnObjectType() const;
	 virtual Item* create() const = 0;
	 virtual void setData(string) const = 0; // need to change params

	 virtual Item& operator=(const Item&);
	 virtual bool operator==(const Item&) const = 0;
	 virtual bool operator!=(const Item&) const = 0;
	 virtual bool operator<(const Item&) const = 0;
	 virtual bool operator>(const Item&) const = 0;


private: 
	 Item* left;
	 Item* right;
	 int numInLib; // number of current copies of item in library
	 int maxNumInLib; // max number of copies of item in library - QUESTION** : Should we make this a constant?
	 char objectType;	 // added this data member to store the type of item the instance is
};

#endif