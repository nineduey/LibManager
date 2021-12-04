#include "patronhistory.h"

//----------------------------------------------------------------------------
//Default Constructor
PatronHistory::PatronHistory() {
	thePatron = nullptr;
}

//----------------------------------------------------------------------------
//Destructor
PatronHistory::PatronHistory(Patron*) {
	thePatron = nullptr;
}

//----------------------------------------------------------------------------
//setData() :
void PatronHistory::setData(Patron* aPatron) {
	thePatron = aPatron;
	return;
}

//----------------------------------------------------------------------------
// create(): method to create a new PatronHistory object, returns pointer to it
Transaction* PatronHistory::create() const { return new PatronHistory; }

//----------------------------------------------------------------------------
// doTransaction():
void PatronHistory::doTransaction(Storage& catalogue, HashMap& patronsMap) {
	//find patron* in the patron hashmap
	thePatron = patronsMap.getPatron(thePatron->getID());
	//display patron & its history
	cout << thePatron;
	return;
}
