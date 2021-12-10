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

//----------------------------------------------------------------------------
// setData(): 
//@pre:
//@post:
bool Checkout::setData( istream& inFile)
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
// create(): 
//@pre:
//@post:
Transaction* Checkout::create() const
{
	return new Checkout;
}

//----------------------------------------------------------------------------
// doTransaction() : method that performs the checkout on the Book
// in its designated BinTree, will add this Checkout object to the
// Patron's history vector of Transaction objects
void Checkout::doTransaction( Storage& catalogue, HashMap& patronsMap ){

	//finding item from binary trees
	Item* foundItem;
	bool found = catalogue.retrieveItem( this->theItem, foundItem );
	// if item found, proceed to checkIn()
	if (found == true){
		
		//check if there are no more copies available in the library
		if(!(foundItem->checkOut())){
			return;
		}

		//adding transaction to patron histroy vector
		Patron* thePatron = patronsMap.getPatron( patronID );
		
		if (thePatron == nullptr){
			cout << "ERROR: Patron with ID " << this->patronID
				<< " not found in records, cannot process Checkout." << endl;
			return;
		}
		else{
			thePatron->addToHistory( foundItem, "Checkout" );
		}
	}
	else{
		cout << "ERROR: Item not found in Catalogue, cannot process Checkout." << endl;
		cout << endl;
	}

	return;
}