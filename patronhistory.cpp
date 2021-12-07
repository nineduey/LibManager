#include "patronhistory.h"


//----------------------------------------------------------------------------
//Default Constructor
PatronHistory::PatronHistory() {
	patronID = 0;
}

//----------------------------------------------------------------------------
//Destructor
PatronHistory::~PatronHistory() {
}

//----------------------------------------------------------------------------
//setData() :
bool PatronHistory::setData(istream& inFile){ // virtual set data method
	inFile >> patronID;
	return true;
}

//----------------------------------------------------------------------------
// create(): method to create a new PatronHistory object, returns pointer to it
Transaction* PatronHistory::create() const { return new PatronHistory; }

//----------------------------------------------------------------------------
// doTransaction():
void PatronHistory::doTransaction(Storage& catalogue, HashMap& patronsMap) {
	//find patron* in the patron hashmap
	Patron* thePatron;
	 thePatron = patronsMap.getPatron(patronID);
	//display patron & its history
	cout << thePatron;
	return;
}
