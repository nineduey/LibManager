#include"return.h"

//----------------------------------------------------------------------------
// Default Constructor
Return::Return()
{
	theItem = nullptr;
	patronID = -1;
}

//----------------------------------------------------------------------------
// Destructor
Return::~Return()
{
	delete theItem;
	theItem = nullptr;
}

///----------------------------------------------------------------------------
// setData(): virtual method that akes an istream object and sets the data within
// to the private data members of Return
bool Return::setData( istream& inFile )
{
	int patID;
	char itemType_Genre;
	inFile >> patID >> itemType_Genre;

	theItem = facDriver.createItem( 'B', itemType_Genre );
	if (theItem != nullptr)	{
		theItem->setDataInput( inFile );
		patronID = patID;
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
Transaction* Return::create() const
{
	return new Return;
}

//----------------------------------------------------------------------------
// doTransaction() : method that performs the checkout on the Book
// in its designated BinTree, will add this Checkout object to the
// Patron's history vector of Transaction objects
void Return::doTransaction( Storage& catalogue, HashMap& patronsMap )
{
	//finding item from binary trees
	Item* foundItem;
	bool found = catalogue.retrieveItem( this->theItem, foundItem );
	// if item found, proceed to checkIn()
	if (found == true)
	{
		foundItem->checkIn();
		//adding transaction to patron histroy vector
		Patron* thePatron = patronsMap.getPatron( patronID );
		if (thePatron == nullptr)
		{
			cout << "ERROR: Patron with ID " << this->patronID
				<< " not found in records, cannot process Return." << endl;
			return;
		}
		else
		{
			thePatron->addToHistory( foundItem, "Return" );
		}
	}
	else
	{
		cout << "ERROR: Item not found in Catalogue, cannot process Return." << endl;
	}

	return;
}