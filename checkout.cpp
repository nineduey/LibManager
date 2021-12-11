/*
@File contents: Function defintions of the Checkout class

@Purpose: Represents a command to checkout a particular book from the
library catalogue.

@Assumptions: The the library's catalogue has been populated with items
and patrons have been registered in the library system

@Authors: Shushmitha Radjaram and Amanda Todakonzie
*/

#include"checkout.h"

//----------------------------------------------------------------------------
// Default Constructor
//@pre: None
//@post: A checkout object is instantiated. function calls by it can be used
// to sets its data and perform a checkout transaction. theItem data 
// and patronID data members are intialized
Checkout::Checkout()
{
	theItem = nullptr;
	patronID = -1;
}

//----------------------------------------------------------------------------
// Destructor
//@pre: A checkout object has been instantiated
//@post: The memory allocated for 'theItem' data member is freed
Checkout::~Checkout()
{
	delete theItem;
	theItem = nullptr;
}

//----------------------------------------------------------------------------
// setData(): sets data for item and patron involved in the checkout  
// transaction
//@pre: The file must be formatted in the same way indicated in the 
// assignment instructions. setSearchData() for derived item 
// classes properly sets the data for the item so it can be used
// to perform checkout action
//@post: If the data given for the checkout action contains 
// valid item data, data will be set for the item and function will
// return true. If it is not, function will return false
bool Checkout::setData( istream& inFile)
{
	int patID;
	char itemType_Genre;
	inFile >> patID >> itemType_Genre;

	theItem = facDriver.createItem( 'B', itemType_Genre );
	if (theItem != nullptr)	{
		if (theItem->setSearchData()( inFile )){
			patronID = patID;
			return true;
		}
	}

	string invalidLine;
	getline( inFile, invalidLine );
	return false;
}


//----------------------------------------------------------------------------
// create(): creates and returns new Checkout object
//@pre: None
//@post: A new Checkout object is returned 
Transaction* Checkout::create() const
{
	return new Checkout;
}

//----------------------------------------------------------------------------
// doTransaction() : performs checkout on book and adds checkout details to 
// patronHistory vector of patron whose ID is equal to Checkout class's private 
// variable 'patronID' 
//@pre: The data for 'this' checkout object must be set and varified to be valid.
// catalogue and patronsMap arguments must contain data on library items
// and patrons
//@post: A checkout transaction is performed and added to patron's history 
// vector. If checkout is not able to be performed, user will be notified
// the error and library catalogue and hashmap/table storing patrons will 
// not be modified
void Checkout::doTransaction( Storage& catalogue, HashMap& patronsMap ){

	//finding item from binary trees
	Item* foundItem;
	bool found = catalogue.retrieveItem( this->theItem, foundItem );
	// if item found, proceed to checkIn()
	if (found == true){
		
		//check if there are no more copies available in the library
		if(!(foundItem->checkOut())){
			cout << "ERROR: Cannot Checkout   ";
			foundItem->printKeyInfo();
			cout << endl << "There are no more copies available for Checkout." << endl;
			return;
		}

		//adding transaction to patron histroy vector
		Patron* thePatron = patronsMap.getPatron( patronID );
		
		//the patron cannot be found and is therefore not registered in the
//library system
		if (thePatron == nullptr){
			cout << "ERROR: Patron with ID " << this->patronID
				<< " not found in records. Cannot process Checkout." << endl;
			return;
		}
		else{
			//adding transaction to patron history vector
			thePatron->addToHistory( foundItem, "Checkout" );
		}
	}
	else{
		cout << "ERROR: The Item ";
		theItem->printKeyInfo();  
		cout << " is not found in Catalogue." << endl;
		cout << "Cannot process Checkout." << endl;
	}

	return;
}