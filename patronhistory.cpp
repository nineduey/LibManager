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
// doTransaction():
void PatronHistory::doTransaction(Storage*& catalogue, HashMap*& patronsMap) {
	//find patron* in the patron hashmap
	thePatron = patronsMap.getPatron(thePatron);
	//display patron & its history
	cout << thePatron;
	return;
}
