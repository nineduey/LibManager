/*
@File contents: Function defintions and variable initializations of the
TransFactory class

@Purpose: Creates and returns a new Book object. Does no work beyond creation.

@Assumptions: The Transfactory class assumes that a valid character is being
is being passed into the createTransaction() method in order to create a
new Transaction object.

@Authors: Shushmitha Radjaram Amanda Todakonzie

@How code is used: Un-initialized Transaction object declared in LibraryManager
is set equal to return value of createItem() function, intializing it as a new
Transaction object of the indicated derived class based on the character passed
in
*/
//----------------------------------------------------------------------------

#include "transfactory.h"


//----------------------------------------------------------------------------
// Default Constructor: Declares elements in 'map' HashMap and initializes them
// with keys equal to char variables of every possible transaction class
// available within the Base class of Transaction. Values equal to integers
// ranging from 0  to the number of transaction classes - 1.
// Declares elements in 'transFac' vector and initializes them to new 
// Transaction objects of every possible derived class of Transaction
// @Pre: None
// @Post: Elements of map and transFac are initialized.
TransFactory::TransFactory()
{
	transFac.push_back( new Checkout );
	transFac.push_back( new Return );
	transFac.push_back( new DisplayCatalogue );
	transFac.push_back( new PatronHistory );

	transMap.insert( { 'C', 0 } );
	transMap.insert( { 'R', 1 } );
	transMap.insert( { 'D', 2 } );
	transMap.insert( { 'H', 3 } );
}

//----------------------------------------------------------------------------
// Destructor of TransFactory class
// @Pre-conditions: None
// @Post-Conditions: Deletes the Transaction objects of 'transFac' vector from
// memory
TransFactory::~TransFactory()
{
	for (int i = 0; i < transFac.size(); i++)
	{
		delete transFac[i];
		transFac[i] = nullptr;
	}
}

//----------------------------------------------------------------------------
// createTransaction(): Instantiates transaction object to equal transaction
// object of the type associated with the char variable passed in
// @Pre: transFac contains the Transaction object of command type associated
// with the char variable passed as the function's argument AND map contains a
// key-value pair in which the key is equal passed in char variable
// @Post: An object of the specified command type of Transaction is 
// instantiated
Transaction* TransFactory::createTransaction( char transType ) const
{   // calls find to locate the transType of class that is needed to be
    // created. If not found, method will return a nullptr;
	if (transMap.find( transType ) == transMap.end())
	{
		return nullptr;
	}
	else
	{//if BinTree of the command Type associated is found, call
	 // create() method of that particular Transaction derived class obj
		int subscript = transMap.at( transType );
		return transFac[subscript]->create();
	}
}
