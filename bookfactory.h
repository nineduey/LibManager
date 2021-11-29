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

/*File contents: Function and variable declarations of the 
BookFactory class
Purpose: Creates and returns a new object. Does no work beyond creation.
Assumptions: There ex
Authors: Shushmitha Radjaram, Phuong K Vu, Monica King, Amanda Todakonzie, 
Brennan Richards
How code is used: Un-initialized book object in LibraryManager is set equal to 
return value of createBook() function, intializing it as a new book object
of the indicated genre/type. 
*/

class BookFactory : public ItemFactory 
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
	BookFactory();

	~BookFactory();

	//----------------------------------------------------------------------------
	//create(): Instantiates book object to equal book object of the type 
	//associated with the char variable passed in as the function's argument
	//Pre-conditions: bookFac contains the Book object of type associated with
	//the char variable passed as the function's argument AND map contains a 
	//key-value pair in which the key is equal passed in char variable 
	//Post-conditions: 
	virtual Item* createItem( char ) const;

private:

	//map needs to take in itemTypeMap map

	std::map<char, int> bookMap;	//HashMap with keys equal to char variables of every 
									//possible book type and values equal to integers 
									// ranging from 0  to the number of book types - 1. 
	
	vector<Book*> bookFac;			//vector with elements that are initialized as new 
									//Book objects of every possible book type
};
#endif

