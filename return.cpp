/*
@File contents: Function defintions of the Return class

@Purpose: Represents a command to return a previously checked out 
book to the library catalogue.

@Assumptions: The the library's catalogue has been populated with items
and patrons have been registered in the library system

@Authors: Shushmitha Radjaram and Amanda Todakonzie
*/
#include"return.h"

//----------------------------------------------------------------------------
// Default Constructor
//@pre: None
//@post: A return object is instantiated. Function calls by it can be used
// to sets its data and perform a return transaction theItem data 
// and patronID data members are intialized
Return::Return()
{
	theItem = nullptr;
	patronID = -1;
}

//----------------------------------------------------------------------------
// Destructor
//@pre: A return object has been instantiated
//@post: The memory allocated for 'theItem' data member is freed
Return::~Return()
{
	delete theItem;
	theItem = nullptr;
}

//----------------------------------------------------------------------------
// setData(): sets data for item and patron involved in the return  
// action
//@pre: The file must be formatted in the same way indicated in the 
// assignment instructions. setSearchData() for derived item 
// classes properly sets the data for the item so it can be used
// to perform return action
//@post: If the data given for the return action contains 
// valid item data, data will be set for the item and function will
// return true. If it is not, function will return false
bool Return::setData( istream& inFile )
{
	int patID;
	char itemType_Genre;
	inFile >> patID >> itemType_Genre;

	theItem = facDriver.createItem( 'B', itemType_Genre );
	if (theItem != nullptr){
		if (theItem->setSearchData(inFile )){
			patronID = patID;
			return true;
		}
	}

	string invalidLine;
	getline( inFile, invalidLine );
	return false;
}

//----------------------------------------------------------------------------
// create(): creates and returns new Return object
//@pre: None
//@post: A pointer to new Return object is returned 
Transaction* Return::create() const
{
	return new Return;
}

//----------------------------------------------------------------------------
// doTransaction(): performs return on book and adds return details to 
// patronHistory vector of patron whose ID is equal to Return class's private 
// variable 'patronID' 
//@pre: The data for 'this' return object must be set and varified to be valid.
// catalogue and patronsMap arguments must contain data on library items
// and patrons. The item being returned must have already been checked out by 
// the patron.
//@post: A return transaction is performed and added to patron's history 
// vector. If return is not able to be performed, user will be notified
// the error and library catalogue and hashmap/table storing patrons will 
// not be modified
void Return::doTransaction( Storage& catalogue, HashMap& patronsMap ){

	//finding item from binary trees
	Item* foundItem;
	bool found = catalogue.retrieveItem( this->theItem, foundItem );

	// if item found, proceed to checkIn()
	if (found == true){

		//check if there are already max copies of the item in the library
		if(!(foundItem->checkIn())){
			cout << "ERROR: Cannot Check In   ";
			foundItem->printKeyInfo();
			cout << endl << "The library holds the maximum number of copies " 
				<< "of this Item." << endl;
			return;
		}

		//the patron cannot be found and is therefore not registered in the
		//library system
		Patron* thePatron = patronsMap.getPatron( patronID );
		if (thePatron == nullptr){
			cout << "ERROR: Patron with ID " << this->patronID
				<< " not found in records. Cannot process Return." << endl;
			return;
		}
	
		//if Patron did not previously checkout the book they are trying to return,
		//output error message
		if(!(thePatron->transExists(foundItem, "Checkout"))){
			cout << "ERROR: Patron with ID " << this->patronID
				<< " is trying to Return " << endl;
			foundItem->printKeyInfo();
			cout << endl << "which was not previously Checked Out by them. "
				<< "Cannot process Return." << endl;
			return;
		}

		//adding transaction to patron history vector
		thePatron->addToHistory( foundItem, "Return" );
	}
	else{
		cout << "ERROR: The Item ";
		theItem->printKeyInfo();
		cout << " is not found in Catalogue. " << endl;
		cout << "Cannot process Return." << endl;
	}

	return;
}