#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "item.h"
#include <map>
#include <vector>
#include <string>
using namespace std;


/*File contents: Function and variable declarations of the
BookFactory class
Purpose: Creates and returns a new object. Does no work beyond creation.
Assumptions: 
Authors: Shushmitha Radjaram, Phuong K Vu, Monica King, Amanda Todakonzie,
Brennan Richards
How code is used: Un-initialized book object in LibraryManager is set equal to
return value of createBook() function, intializing it as a new book object
of the indicated genre/type.
*/

class ItemFactory
{

public:

	//----------------------------------------------------------------------------
	//BookFactory(): Declares elements in 'map' HashMap and initializes them with 
	//keys equal to char variables of every possible book type and values equal 
	//to integers ranging from 0  to the number of book types - 1. 
	//Declares elements in'bookFac' vector and initializes them to new Book objects
	//of every possible book type
	//Pre-conditions:None
	//Post-conditions: Elements of map and bookFac are initialized.
	ItemFactory();

	//----------------------------------------------------------------------------
	//create(): Instantiates book object to equal book object of the type 
	//associated with the char variable passed in as the function's argument
	//Pre-conditions: bookFac contains the Book object of type associated with
	//the char variable passed as the function's argument AND map contains a 
	//key-value pair in which the key is equal passed in char variable 
	//Post-conditions: 
	virtual Item* createItem( char ) const = 0;

};
#endif



