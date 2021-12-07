#include "patronhistory.h"

//----------------------------------------------------------------------------
//Default Constructor
PatronHistory::PatronHistory()
{
}

//----------------------------------------------------------------------------
//Destructor
PatronHistory::PatronHistory( Patron* )
{
	patronID = -1;
}

//----------------------------------------------------------------------------
//setData() :
bool PatronHistory::setData( istream& inFile )
{
	int patID;
	inFile >> patID;
	this->patronID = patID;

	return true;
}

//----------------------------------------------------------------------------
// create(): method to create a new PatronHistory object, returns pointer to it
Transaction* PatronHistory::create() const { return new PatronHistory; }

//----------------------------------------------------------------------------
// doTransaction():
void PatronHistory::doTransaction( Storage& catalogue, HashMap& patronsMap )
{
	//find patron* in the patron hashmap
	Patron* thePatron = patronsMap.getPatron( this->patronID );

	if(thePatron == nullptr)
	{
		cout << "Error, Patron not found in records, cannot display history." << endl;
		return;
	}

	//display patron's ID and name
	cout << *thePatron << "    " << endl;;

	//display the patron's history
	thePatron->printHistory(thePatron->getHistory());
	cout << endl;

	return;
}
