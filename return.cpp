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
void Return::doTransaction( Storage& catalogue, HashMap& patronsMap ){

	//finding item from binary trees
	Item* foundItem;
	bool found = catalogue.retrieveItem( this->theItem, foundItem );

	// if item found, proceed to checkIn()
	if (found == true){

		//check if there are already max copies of the item in the library
		if(!(foundItem->checkIn())){
			return;
		}

		Patron* thePatron = patronsMap.getPatron( patronID );
		if (thePatron == nullptr){
			cout << "ERROR: Patron with ID " << this->patronID
				<< " not found in records, cannot process Return." << endl;
			return;
		}
	
		//if Patron did not previously checkout the book they are trying to return,
		//output error message
		if(!(thePatron->transExists(foundItem, "Checkout"))){
			cout << "ERROR: The item that the Patron with ID " << this->patronID
				<< " is trying to Return was not previously Checked Out by them. "
				<< "Cannot process Return." << endl;
			return;
		}

		//adding transaction to patron histroy vector
		thePatron->addToHistory( foundItem, "Return" );
	}
	else{
		cout << "ERROR: Item not found in Catalogue, cannot process Return." << endl;
	}

	return;
}