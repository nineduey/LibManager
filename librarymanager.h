/*
@File contents: Function and variable declarations of the 
LibraryManager class

@Purpose: To process files containing data on Library's inventory,
customers, and transactions. Calls are made to functions in 
other classes to further process data to create, manipulate, 
display, etc. the data on Items and customers of the library

@Assumptions:The files being read in and main and content + format 
being stored in the 'istream&' objects that readInventory(), 
readCustomer(), and readTransaction() take in as arguments
is correctly formatted.

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: The functions and variables declared in this file
serve as a template for the librarymanager.cpp file in which 
functions and variables will be defined and initialized. Once initialized, 
the LibraryManager represents the initial data processor data for a Library
and interacts with the user/driver code
*/

#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H
#include "factorydriver.h"
#include "storage.h"
#include "transaction.h"
#include "hashmap.h"
#include "item.h"
#include "transfactory.h"
#include <iostream>
using namespace std;

class LibraryManager
{
	//friend class Transaction;
	//friend class Checkout;
	//friend class Return;

public:

	//friend ostream& operator<<( ostream&, const LibraryManager& );

	//----------------------------------------------------------------------------
	//readInventory(): reads in Item data and builds the inventory 
	//Pre-conditions: variable of type ifstream& that contains correctly formatted 
	//.txt file must be passed in
	//Postconditions: Creates Item objects using details of Items given in passed 
	//in ifstream& object and stores intialized Items objects in sorted order in 
	//Library's catalogue
	void readInventory(istream&);

	//----------------------------------------------------------------------------
	//readCustomer(): reads in customer and builds the customer objects
	//Pre-conditions: variable of type ifstream& that contains correctly formatted 
	//.txt file must be passed in
	//Postconditions: Creates Customer objects using details of customers given in 
	//passed in ifstream& object and stores intialized Customer objects in sorted 
	//order in Library's catalogue
	void readPatrons( istream& );

	//----------------------------------------------------------------------------
	//readTransaction(): reads in transaction data and performs transactions
	//Pre-conditions: variable of type ifstream& that contains correctly formatted 
	//.txt file must be passed in
	//Post-conditions: Performs transactions on data of objects in the Library using 
	//details of transactions given in passed in .txt file
	void readTransactions( istream& );

private:

	FactoryDriver facdriver;	//Object that calls createItem() function of appropriate 
								//derived ItemFactory class to instantiate an Item object 
								//of a specific type

	HashMap patronsMap;	//calling object of method that further processes customer data 

	//TransFactory transFac;    // Object that calls createTransaction() function

	TransFactory transFac;

	Storage catalogue;	//contains map of BinTree objects that each contain Items of 
						//a specific type
	
};
#endif
