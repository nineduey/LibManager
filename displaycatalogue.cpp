/*
@File contents: Function and variable declarations of the DisplayCatalogue

@Purpose: The DisplayCatalogue represents a command to display the catalogue
that is held within the LibraryManager class.

@Assumptions: The Base Class of Transaction is defined and

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: When the command to create a DisplayCatalogue object is
read in, the TransFactory will create an a new DisplayCatalogue object, which
the virtual doTransaction method is called upon it. This class holds the
definition of the doTransaction() which will display the entire library's
catalogue contents
*/
#include "displaycatalogue.h"

//----------------------------------------------------------------------------
// Default Constructor
// @Pre: None
// @Post: Initializes and creates a new DisplayCatalogue object

DisplayCatalogue::DisplayCatalogue() {}

//----------------------------------------------------------------------------
// Destructor
// @Pre: None
// @Post: Virtual destuctor will be called based on the derived class.
DisplayCatalogue::~DisplayCatalogue() {}

//----------------------------------------------------------------------------
// create(): method to create a new DisplayCatalogiue object, returns a pointer
// to the new object
//@Pre: None
//@Post: Returns a pointer to the new DisplayCatalogue object created
Transaction* DisplayCatalogue::create() const { return new DisplayCatalogue; }


//----------------------------------------------------------------------------
// setData(): virtual method does not do anything in particular, only defined
// ensure setData methods are use appropriately for the other Transactions 
// derived classes
// @Pre: Function takes a referenced istream object
// @Post: Returns a boolean value, always true
bool DisplayCatalogue::setData( istream& inFile )
{
	return true;
}

//----------------------------------------------------------------------------
// doTransaction(): method to call on BinTree to display the contents of
// library and its checkin/checkout status
// @pre: Function takes two arguments, a referenced Storage object and a 
// referenced HashMap object
// @post: The catalogue (Storage object) is sent to cout << to be displayed
// to the user, function returns void
void DisplayCatalogue::doTransaction( Storage& catalogue, HashMap& patronsMap )
{
	cout << endl;
	cout << "LIBRARY CATALOGUE:" << endl;
	cout << endl;
	cout << catalogue;
	return;
}
