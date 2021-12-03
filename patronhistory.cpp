#include "patronhistory.h"

//----------------------------------------------------------------------------
//Default Constructor
PatronHistory::PatronHistory() {
	patron = nullptr;
}

//----------------------------------------------------------------------------
//Destructor
PatronHistory::PatronHistory(Patron*) {
	delete patron;
	patron = nullptr;
}

//----------------------------------------------------------------------------
//setData() :
void PatronHistory::setData(Patron* thePatron) {
	patron = thePatron;
}

//----------------------------------------------------------------------------
// doTransaction():
void PatronHistory::doTransaction() {

}