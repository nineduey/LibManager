/*File contents: Function and variable declarations of the
BookFactory class
Purpose: Creates and returns a new object. Does no work beyond creation.
Assumptions: There ex
Authors: Shushmitha Radjaram, Phuong K Vu, Monica King, Amanda Todakonzie, Brennan Richards
How code is used: Un-initialized book object in LibraryManager is set equal to return value of createBook() function, initializing it as a new book object of the indicated genre/type.
*/

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H
#include "book.h"
#include "periodical.h"
#include "fiction.h"
#include "children.h"
#include <map>
#include <vector>

class Book;

class BookFactory
{

public:

//-------------------------------------------------------------------
//Default Constructor: Declares elements in 'map' HashMap and 
//initializes them with keys equal to char variables of every 
//possible book type and values equal to integers ranging from 0 to 
//the number of book types - 1. Declares elements in'bookFac' vector 
//and initializes them to new Book objects of every possible book 
//type
//Pre-conditions:None
//Post-conditions: Elements of map and bookFac are initialized.
	 BookFactory();

//-------------------------------------------------------------------
//BookFactory Destructor: Iteratively deletes the the contents data 
//of the bookFac vector
//Pre-conditions: None
//Post-conditions: The data in the bookFac vector is deleted from 
//memory
	 ~BookFactory();

//-------------------------------------------------------------------
 //createBook(): Instantiates book object to equal book object of the //type associated with the char variable passed in as the function's //argument
 //Pre-conditions: bookFac contains the Book object of type //associated with the char variable passed as the function's argument //AND map contains a key-value pair in which the key is equal passed //in char variable 
 //Post-conditions: Returns a Book pointers that is empty
	 Book* createBook(char);

private:

//HashMap with keys equal to char variables of every possible    //book type and values equal to  integers ranging from 0  to the //number of book types - 1. 
	 std::map<std::char, int> map;

//vector with pointers to newly initialized Book objects 
//of every possible book type available in the library
	 vector<Book*> bookFac;
};

#endif
