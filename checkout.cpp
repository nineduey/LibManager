#include"checkout.h"

//----------------------------------------------------------------------------
// Default Constructor
Checkout::Checkout() {
}

//----------------------------------------------------------------------------
// Constructor for class Checkout
Checkout::Checkout(Item* theItem, int patID) {
}

//----------------------------------------------------------------------------
// Destructor
Checkout::~Checkout() {
    theItem = nullptr;
}

//----------------------------------------------------------------------------
// doTransaction() : method that performs the checkout on the Book
// in its designated BinTree, will add this Checkout object to the
// Patron's history vector of Transaction objects
void Checkout::doTransaction(Storage&, HashMap&){

}