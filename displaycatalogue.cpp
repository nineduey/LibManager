/*
@File contents: Function defintions and variable initializations
of the DisplayCatalogue class

@Purpose:

@Assumptions

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
#include "displaycatalogue.h"

//----------------------------------------------------------------------------
// Default Constructor
DisplayCatalogue::DisplayCatalogue() {
}

//----------------------------------------------------------------------------
// Destructor
DisplayCatalogue::~DisplayCatalogue() {
}

//----------------------------------------------------------------------------
// create(): method to create a new DisplayCatalogiue object, returns a pointer
// to the new object
Transaction* DisplayCatalogue::create() const { return new DisplayCatalogue; }

//----------------------------------------------------------------------------
// doTransaction(): method to call on BinTree to display the contents of
// library and its checkin/checkout status
// @pre:
// @post:
void DisplayCatalogue::doTransaction(Storage& catalogue, HashMap& patronsMap) {
	cout << catalogue;
	return;
}
