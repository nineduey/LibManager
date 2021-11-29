/*
@File contents: Function defintions and variable initializations
of the LibraryManager class

@Purpose: To process files containing data on Library's inventory,
customers, and transactions. Calls are made to functions in
other classes to further process data to create, manipulate,
display, etc. the data on books and customers of the library

@Assumptions:The files being read in and main and content + format
being stored in the 'istream&' objects that readInventory(),
readCustomer(), and readTransaction() take in as arguments
is correctly formatted.

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: The LibraryManager represents the initial data processor 
data for a Library and interacts with the user/driver code.
*/

#include "librarymanager.h"

//----------------------------------------------------------------------------
//readInventory(): reads in Item data and builds the inventory 
//Pre-conditions: variable of type ifstream& that contains correctly formatted 
//.txt file must be passed in
//Postconditions: Creates Item objects using details of Items given in passed 
//in ifstream& object and stores intialized Items objects in sorted order in 
//Library's catalogue
void LibraryManager::readInventory(istream& inFile){

    Item* item;
	char itemType;
	char itemType_type;
	
	 while (!inFile.eof()) {

		inFile >> itemType_type;

		itemType = 'B';
		item = this->facdriver.createItem( itemType, itemType_type );
		if(item == nullptr)
		{
			continue;
		}
		inFile.get();
		item->setData( inFile );
		//item->display();
		catalogue.append( item );
	 }
}

//----------------------------------------------------------------------------
//readCustomer(): reads in customer and builds the customer objects
//Pre-conditions: variable of type ifstream& that contains correctly formatted 
//.txt file must be passed in
//Postconditions: Creates Customer objects using details of customers given in 
//passed in ifstream& object and stores intialized Customer objects in sorted 
//order in Library's catalogue
void LibraryManager::readCustomer(istream& inFile) {

}

//----------------------------------------------------------------------------
//readTransaction(): reads in transaction data and performs transactions
//Pre-conditions: variable of type ifstream& that contains correctly formatted 
//.txt file must be passed in
//Post-conditions: Performs transactions on data of objects in the Library using 
//details of transactions given in passed in .txt file
void LibraryManager::readTransaction(istream& inFile) {

}
