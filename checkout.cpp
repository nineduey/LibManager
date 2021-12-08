#include"checkout.h"

//----------------------------------------------------------------------------
// Default Constructor
Checkout::Checkout()
{
	theItem = nullptr;
	patronID = -1;
	//thePatron = nullptr;
}

//----------------------------------------------------------------------------
// Destructor
Checkout::~Checkout()
{
	delete theItem;
	theItem = nullptr;
}

bool Checkout::setData( istream& inFile)
{
	int patID;
	char itemType_Genre;
	char itemFormat;

	inFile >> patID >> itemType_Genre >> itemFormat;
	// if BookType is periodical
	if (itemType_Genre == 'P')
	{
		string title;
		int month;
		int year;
		inFile >> year >> month;
		inFile.get();
		getline( inFile, title, ',' );
		theItem = facDriver.createItem( 'B', itemType_Genre );
		if(theItem != nullptr)
		{
			theItem->setData( title, month, year, itemFormat );
			patronID = patID;
			return true;
		}
	}
	else if (itemType_Genre == 'F') // if BookType is Fiction
	{
		string author;
		string title;
		inFile.get();
		getline( inFile, author, ',' );
		inFile.get();
		getline( inFile, title, ',' );
		theItem = facDriver.createItem( 'B', itemType_Genre );
		if (theItem != nullptr)
		{
			theItem->setData( author, title, itemFormat );
			patronID = patID;
			return true;
		}
	}
	else // if BookType is Children
	{
		string author;
		string title;
		inFile.get();
		getline( inFile, title, ',' );
		inFile.get();
		getline( inFile, author, ',' );
		theItem = facDriver.createItem( 'B', itemType_Genre );
		if (theItem != nullptr)
		{
			theItem->setData( author, title, itemFormat );
			patronID = patID;
			return true;
		}
	}

	return false;
}

Transaction* Checkout::create() const
{
	return new Checkout;
}

//----------------------------------------------------------------------------
// doTransaction() : method that performs the checkout on the Book
// in its designated BinTree, will add this Checkout object to the
// Patron's history vector of Transaction objects
void Checkout::doTransaction( Storage& catalogue, HashMap& patronsMap )
{
	//finding item from binary trees
	Item* foundItem;
	bool found = catalogue.retrieveItem( this->theItem, foundItem );
	// if item found, proceed to checkIn()
	if (found == true)
	{
		foundItem->checkOut();
		//adding transaction to patron histroy vector
		Patron* thePatron = patronsMap.getPatron( patronID );
		if(thePatron == nullptr)
		{
			cout << "ERROR: Patron with ID " << this->patronID
				<< " not found in records, cannot process Checkout." << endl;
			return;
		}
		else
		{
			thePatron->addToHistory( foundItem, 'C' );
		}
	}
	else
	{
		cout << "ERROR: Item not found in Catalogue, cannot process Checkout." << endl;
		cout << endl;
	}

	return;
}
