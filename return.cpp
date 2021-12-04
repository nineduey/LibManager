#include"return.h"
#include "storage.h"
#include "hashmap.h"


//----------------------------------------------------------------------------
// Default Constructor
Return::Return() {
	 theItem = nullptr;
	 thePatron = nullptr;
}

//----------------------------------------------------------------------------
// Constructor for class Checkout
Return::Return(Item* anItem, Patron* aPatron) {
	 theItem = anItem;
	 thePatron = aPatron;
}

//----------------------------------------------------------------------------
// Destructor
Return::~Return() {
	 theItem = nullptr;
	 thePatron = nullptr;

}

//----------------------------------------------------------------------------
// setData(): virtual method that akes an istream object and sets the data within
// to the private data members of Return
void Return::setData(istream& inFile) {
	 int patronID;
	 char bookType;
	 inFile >> patronID >> bookType;
	// thePatron = need to get patron pointer based on ID;
	 inFile.get();
	
	//create Item* of the book needed to find
	Item* toFind;
}
//----------------------------------------------------------------------------
Transaction* Return::create() const {
	 return new Return;
}

//----------------------------------------------------------------------------
// doTransaction() : method that performs the checkout on the Book
// in its designated BinTree, will add this Checkout object to the
// Patron's history vector of Transaction objects
void Return::doTransaction(Storage& catalogue, HashMap& patronsMap) {

	 //finding item from binary trees
	 Item* foundItem;
    bool found =  catalogue.retrieveItem(this->theBook, foundItem);
	 // checking out item
	 foundItem->checkOut();
	 //adding transaction to patron histroy vector --  need a way to access the patron's history vector?
	 Return copy = *this;
	 thePatron->addToHistory(copy);// -- from pseudo code
	 return;
}
