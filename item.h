/*
@File contents: BinTree class function and variable declarations

@Purpose: This is the class will take the place of Nodes that will be stored 
@File contents: Item class function and variable declarations

@Purpose: This is the class will take the place of Nodes that will be stored
in the BinTree class. The Items that held in the BinClass will hold a NodeData
pointer which for this assignment will point to a book. This design is extensible, 
such as adding another class called Music, the NodeData objects could point to a 
Music object instead of a Book object. This allows different BinTrees
to be built, holding specific kinds of Node Data derived classes

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "bintree.h"
#include <string>

using namespace std;

//forward referencing - not needed?
//class Book;

class Item {

	 friend class BinTree;
	 friend ostream& operator<<(ostream&, const Item&);

public:

	 Item(); // default constructor
	 virtual ~Item(); // destructor
	 void checkOut();
	 void checkIn();
	 char returnItemType() const;
	 virtual Item* create() const = 0;
	 virtual void setData(ifstream&) const = 0;
	 virtual void print(ostream& os) const;

	 virtual Item& operator=(const Item&) const = 0;
	 virtual bool operator==(const Item&) const = 0;
	 virtual bool operator!=(const Item&) const = 0;
	 virtual bool operator<(const Item&) const = 0;
	 virtual bool operator>(const Item&) const = 0;

private:
	 Item* left;
	 Item* right;

protected: 
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
	 int numInLib; // number of current copies of item in library
	 int maxNumInLib; // max number of copies of item in library - QUESTION** : Should we make this a constant?
	 char itemType;	// added this data member to store the type of item the instance is
	 bool validate() const; // check whether the input content is valid
	Item();			  // default constructor
	virtual ~Item(); // destructor
	void checkOut(); // check out an Item from the BinTree
	void checkIn();  // check in an Item from the BinTree
	virtual char returnItemType() const = 0; // returns ItemType
	virtual char returnItemType_Genre() const = 0;// returns the Type
																// of ItemType
	virtual Item* create() const = 0;		  // virtual create function
	virtual void setData( istream& ) = 0;	  // virtual setData function
	virtual void print(ostream& os) const = 0;// virtual print function

	//virtual comparison operators
	virtual Item& operator=( const Item& ) = 0;
	virtual bool operator==( const Item& ) const = 0;
	virtual bool operator!=( const Item& ) const = 0;
	virtual bool operator<( const Item& ) const = 0;
	virtual bool operator>( const Item& ) const = 0;


protected:
	int numInLib; // number of current copies of item in library
	int maxNumInLib; // max number of copies of item in library
	char itemType;	 // added this data member to store the type of item the instance is
   bool validate() const;  	//check whether the input content is valid


private:
	 Item* left;
	 Item* right;

};

#endif
