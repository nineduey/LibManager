#include"return.h"

//----------------------------------------------------------------------------
// Default Constructor
Return::Return()
{
	theItem = nullptr;
	patronID = -1;
}


//----------------------------------------------------------------------------
// Constructor for class Checkout
Return::Return( Item* anItem, int patID )
{
	theItem = anItem;
	patronID = patID;
}

//----------------------------------------------------------------------------
// Destructor
Return::~Return()
{
	theItem = nullptr;
}

///----------------------------------------------------------------------------
// setData(): virtual method that akes an istream object and sets the data within
// to the private data members of Return
void Return::setData( istream& inFile )
{
	int patID;
	char itemType_Genre;
	char itemType_Format;
	string title;
	string author;
	int month;
	int year;

	inFile >> patID >> itemType_Genre >> itemType_Format;
	// if BookType is periodical
	if (itemType_Genre == 'P')
	{
		inFile >> year >> month;
		inFile.get();
		getline( inFile, title, ',' );
		// data variable not used
		author = "";
	}
	else
	{
		inFile.get();
		getline( inFile, author, ',' );
		inFile.get();
		getline( inFile, title, ',' );
		// data variables not used
		month = 0;
		year = 0;
	}

	theItem = facDriver.createItem( 'B', itemType_Genre );
	theItem->setData( author, title, month, year );
	patronID = patID;
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
		Return* copy = this;
		thePatron->addToHistory( copy );
	}
	else
	{
		cout << "Error, Item not found in Catalogue, cannot process return." << endl;
	}

	return;
}

void Return::clear()
{
	theItem = nullptr;
}
