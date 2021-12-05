#include"checkout.h"

//----------------------------------------------------------------------------
// Default Constructor
Checkout::Checkout()
{
}

//----------------------------------------------------------------------------
// Constructor for class Checkout
Checkout::Checkout( Item*, Patron* )
{
}

//----------------------------------------------------------------------------
// Destructor
Checkout::~Checkout()
{
}

void Checkout::setData( istream& inFile)
{
	int patronID;
	char bookType;
	inFile >> patronID >> bookType;
	// thePatron = need to get patron pointer based on ID;
	inFile.get();

	//create Item* of the book needed to find
	Item* toFind;
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
	// checking out item
	foundItem->checkOut();
	//adding transaction to patron histroy vector --  need a way to access the patron's history vector?
	//Checkout copy = *this;
	thePatron->addToHistory( this );// -- from pseudo code
	return;
}
