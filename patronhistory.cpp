/*
@File contents: Function definitions of the PatronHistory class

@Purpose: Represents a command to display a patron's transaction
history consisting of library item checkouts and returns

@Assumptions: The the library's catalogue has been populated with items
and patrons have been registered in the library system.

@Authors: Shushmitha Radjaram and Amanda Todakonzie
*/
#include "patronhistory.h"

//----------------------------------------------------------------------------
//Default Constructor
//@pre: None
//@post: A PatronHistory object is instantiated. function calls by it can be 
// used to sets its data display a patron;'s transaction history. patronID data 
// member is initialized
PatronHistory::PatronHistory(){
	patronID = -1;
}

//----------------------------------------------------------------------------
// Destructor
//@pre: A return object has been instantiated
//@post: The memory allocated 
PatronHistory::~PatronHistory() {}

//----------------------------------------------------------------------------
//setData(): sets data for item and patron involved in the return 
//@pre:The file must be formatted in the same way indicated in the 
// assignment instructions.
//@post: The data member patronID is set to the ID given in the current line
//of the file 
bool PatronHistory::setData( istream& inFile )
{
	int patID;
	inFile >> patID;
	this->patronID = patID;

	return true;
}

//----------------------------------------------------------------------------
// create(): method to create a new PatronHistory object, returns pointer to 
// it
//@pre: None
//@pre: Pointer to new PatronHistory object is returned 
Transaction* PatronHistory::create() const { return new PatronHistory; }

//----------------------------------------------------------------------------
// doTransaction(): displays transaction history of patron with ID
//equal to the data member patronID
//@pre: The data for 'this' PatronHistory object must be set and varified to 
// be valid.
// catalogue and patronsMap arguments must contain data on library items
// and patrons. 
//@post: The details of the transactions of a Patron's transaction history is 
// displayed. If the patron with ID equal to the patronID data member of this 
// class cannot be found in the patronsMap, history will not be printed and 
// error message will be displayed to user
void PatronHistory::doTransaction( Storage& catalogue, HashMap& patronsMap )
{
	//find patron* in the patron hashmap
	Patron* thePatron = patronsMap.getPatron( this->patronID );

	if(thePatron == nullptr){
		cout << "ERROR: Patron with ID " << this->patronID 
			<< " not found in records, cannot display Patron's History." << endl;
		return;
	}
	else{
		//display patron's ID and name
		cout << *thePatron << endl;

		//display the patron's history 
		thePatron->printHistory( thePatron->getHistory() );
		cout << endl;
	}

	return;
}
