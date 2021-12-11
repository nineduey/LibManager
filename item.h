/*
@File contents: Function and variable declarations for Item Class

@Purpose: The Item class serves as an abstract class for its derived classes,
such as Book and Book's derived classes. Item pointers are stored inside of the
container BinTree Class's nodes.

@Assumptions: Its derived classes of Book, and Book's derived classes of
Childre, Fiction, and Periodical are defined as well as its containter BinTree

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Item objects are instantiated withint the FacDriver class to
create new empty objects of its derived classes that are defined.
*/
//-----------------------------------------------------------------------------
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

using namespace std;

class Item
{
	friend class BinTree;
	// ostream operators used for printing
	friend ostream& operator<<( ostream&, const Item& );

public:

	Item();		 // default constructor
	virtual ~Item(); // destructor
	bool checkOut(); // check out an Item from the BinTree
	bool checkIn();  // check in an Item from the BinTree
	
	//virtual functions
	virtual char returnItemType() const = 0; // returns ItemType
	virtual char returnItemType_Genre() const = 0;// returns genre of ItemType
	virtual Item* create() const = 0; // virtual create function
	virtual bool setData( istream& ) = 0; // virtual setData function
	virtual bool setSearchData( istream& ) = 0; // virtual setData function
	virtual void printItem( ostream& os ) const = 0;// virtual print function
	virtual void printHeader() const = 0; // virtual print header function
	virtual void printKeyInfo() const = 0;

	//virtual comparison operators
	virtual Item& operator=( const Item& ) = 0;
	virtual bool operator==( const Item& ) const = 0;
	virtual bool operator!=( const Item& ) const = 0;
	virtual bool operator<( const Item& ) const = 0;
	virtual bool operator>( const Item& ) const = 0;

protected:
	int numInLib; // number of current copies of item in library
	int maxNumInLib; // max number of copies of item in library
	char itemType;	 // stores the type of item the instance is
	char itemFormats[5]; //array of valid format types
	char itemFormat; // the format of the particular Item object instance
};

#endif
