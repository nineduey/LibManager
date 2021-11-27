/*
@File contents: LibraryManager class function and variable declarations

@Purpose: To process files containing data on Library's inventory,
customers, and transactions. Calls are made to functions in
other classes to further process data to create, manipulate,
display, etc. the data on books and customers of the library

@Assumptions:The files being read in and main and content + format
being stored in the 'ifstream&' objects that readInventory(),
readCustomer(), and readTransaction() take in as arguments
is correctly formatted.

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: The functions and variables declared in this file
serve as a template for the librarymanager.cpp file in which
functions and variables will be defined and initialized. Once 
initialized, the LibraryManager represents the initial data processor
data for a Library and interacts with the user/driver code
*/
//-----------------------------------------------------------------------------

#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H
#include "librarymanager.cpp"
#include <iostream>

//forward referencing from .cpp
class BookFactory;
class HashMap;
class Storage;

class LibraryManager
{
   friend class Transactions;

public:

//-----------------------------------------------------------------------------
//readInventory(): reads in book data and builds the inventory 
//Pre-conditions: variable of type ifstream& that contains correctly 
// //formatted .txt file must be passed in 
//Postconditions: Creates Book objects using details of books given 
//in passed in ifstream& object and stores initialized Book objects 
//in sorted order in Library's catalogue

    void readInventory(istream&);

//-----------------------------------------------------------------------------
//readCustomer(): reads in customer and builds the customers  
//Pre-conditions: variable of type ifstream& that contains correctly 
//formatted .txt file must be passed in
//Postconditions: Creates Customer objects using details of 
//customers given in passed in ifstream& object and stores 
//initialized Customer objects in sorted order in Library's catalogue

	 void readCustomer(istream&);
//-----------------------------------------------------------------------------
//readTransaction(): reads in transaction data & performs   
//transactions
//Pre-conditions: variable of type ifstream& that contains correctly 
//formatted .txt file must be passed in
//Post-conditions: Performs transactions on data of objects in the
//Library using details of transactions given in passed in .txt file

	 void readTransaction(istream&);

private:

//calling object of BookFactory method that instantiates Book object
	 BookFactory bf;

//calling object of method that further processes customer data 
	 HashMap patrons;

//array of BinTree objects each containing different kinds of Items
	 Storage catalogue;

};
#endif
