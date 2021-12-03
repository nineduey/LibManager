#include "patronhistory.h"

//----------------------------------------------------------------------------
//Default Constructor
PatronHistory::PatronHistory() {
	patron = nullptr;
}

//----------------------------------------------------------------------------
//Destructor
PatronHistory::PatronHistory(Patron*) {
	patron = nullptr;
}

//----------------------------------------------------------------------------
//setData() :
void PatronHistory::setData(Patron* thePatron) {
	patron = thePatron;
	return;
}

//----------------------------------------------------------------------------
// doTransaction():
void PatronHistory::doTransaction() {
	//find patron* in the patron hashmap
	patron = patrons.getPatron(patron);
	//display patron & its history
	cout << patron;
	return;
}