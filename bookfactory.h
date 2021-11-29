/*
@File contents: Function and variable declarations of the BookFactory class

@Purpose: Creates and returns a new Book object. Does no work beyond creation.

@Assumptions: The Base class of BookFactory, ItemFactory, is defined

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Un-initialized Book object declared in in LibraryManager is
set equal to return value of createItem() function, intializing it as a new
Book object of the indicated genre.
*/

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H
#include "itemfactory.h"
#include "item.h"
#include "book.h"
#include "periodical.h"
#include "fiction.h"
#include "children.h"
#include <map>
#include <vector>

class BookFactory : public ItemFactory 
{

public:

	//----------------------------------------------------------------------------
	//BookFactory(): Declares elements in 'map' HashMap and initializes them with 
	//keys equal to char variables of every possible book type in library and values 
	//equal to integers ranging from 0  to the number of book types - 1. 
	//Declares elements in'bookFac' vector and initializes them to new Book objects
	//of every possible book type in library
	//Pre-conditions:None
	//Post-conditions: Elements of map and bookFac are initialized.
	BookFactory();

	//----------------------------------------------------------------------------
	//~FactoryDriver(): Destructor of BookFactory class
	//Pre-conditions: None
	//Post-Conditions: Deletes the Book objects of 'bookFac' vector from memory
	~BookFactory();

	//----------------------------------------------------------------------------
	//createItem(): Instantiates book object to equal book object of the type 
	//associated with the char variable passed in 
	//Pre-conditions: bookFac contains the Book object of type associated with
	//the char variable passed as the function's argument AND map contains a 
	//key-value pair in which the key is equal passed in char variable 
	//Post-conditions: An object of the specified type of Book is instantiated
	virtual Item* createItem( char ) const;

private:

	std::map<char, int> bookMap;	//HashMap with keys equal to char variables of every 
									//possible book type and values equal to integers 
									// ranging from 0  to the number of book types - 1. 
	
	vector<Book*> bookFac;			//vector with elements that are initialized as new 
									//Book objects of every possible book type
};
#endif

