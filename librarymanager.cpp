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
	char itemType_genre;

	 while (true) {

		inFile >> itemType_genre;
	 	if (inFile.eof()) {
			break;
		}

		itemType = 'B';
		item = this->facdriver.createItem( itemType, itemType_genre);
		if(item == nullptr){

			string invalidLine = "";
			getline( inFile, invalidLine );
			continue;
		}
		inFile.get();
		item->setData( inFile );
		catalogue.append( item );
	 }

	 cout << catalogue;
}

//----------------------------------------------------------------------------
//readCustomer(): reads in customer and builds the customer objects
//Pre-conditions: variable of type ifstream& that contains correctly formatted
//.txt file must be passed in
//Postconditions: Creates Customer objects using details of customers given in
//passed in ifstream& object and stores intialized Customer objects in sorted
//order in Library's catalogue
void LibraryManager::readPatrons(istream& inFile) {

}

//----------------------------------------------------------------------------
//readTransaction(): reads in transaction data and performs transactions
//Pre-conditions: variable of type ifstream& that contains correctly formatted
//.txt file must be passed in
//Post-conditions: Performs transactions on data of objects in the Library using
//details of transactions given in passed in .txt file
void LibraryManager::readTransactions(istream& inFile, Storage& catalogue, HashMap& patrons) {

	char commandType;
	int patronID;
	char itemType_genre;
	Transaction* command;

	while (true) {
		inFile >> commandType;
		if (inFile.eof()) {
			break;
		}
		// transactions factory
		// createTransaction method delivers pointer to new object based on commandType
		command = this->transFac.createTransaction(commandType);
		// error checking, if commandType invalid, nullptr is returns from createTransaction
		if (command == nullptr) {

			 string invalidLine = "";
			 getline(inFile, invalidLine);
			 continue;
		}
		inFile.get();

		if (commandType == 'D') {
			 command->doTransaction(catalogue, patronsMap);
		}
		command->setData(inFile);
		command->doTransaction(catalogue, patronsMap);
	}
}
