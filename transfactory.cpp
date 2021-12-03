/*
@File contents: Function defintions and variable initializations of the
TransFactory class

@Purpose: Creates and returns a new Book object. Does no work beyond creation.

@Assumptions: The Base class of TransFactory, ItemFactory, is defined

@Authors: Shushmitha Radjaram Amanda Todakonzie

@How code is used: Un-initialized Book object declared in in LibraryManager is
set equal to return value of createItem() function, intializing it as a new
Book object of the indicated genre.
*/

#include "transfactory.h"


//----------------------------------------------------------------------------
//TransFactory(): Declares elements in 'map' HashMap and initializes them with 
//keys equal to char variables of every possible book type in library and values 
//equal to integers ranging from 0  to the number of book types - 1. 
//Declares elements in'bookFac' vector and initializes them to new Book objects
//of every possible book type in library
//Pre-conditions:None
//Post-conditions: Elements of map and bookFac are initialized.
TransFactory::TransFactory() {

	transFac.push_back(new Checkout);
	transFac.push_back(new Return);
	transFac.push_back(new DisplayCatalogue);
	transFac.push_back(new PatronHistory);

	transMap.insert({ 'C', 0 });
	transMap.insert({ 'R', 1 });
	transMap.insert({ 'D', 2 });
	transMap.insert({ 'H', 3 });
}

//----------------------------------------------------------------------------
//~TransFactory(): Destructor of TransFactory class
//Pre-conditions: None
//Post-Conditions: Deletes the Transaction objects of 'transFac' vector from memory
TransFactory::~TransFactory() {

	for (int i = 0; i < transFac.size(); i++) {
		delete transFac[i];
		transFac[i] = nullptr;
	}
}

//----------------------------------------------------------------------------
//createTransaction(): Instantiates transaction object to equal transaction 
//object of the type associated with the char variable passed in 
//Pre-conditions: bookFac contains the Book object of type associated with
//the char variable passed as the function's argument AND map contains a 
//key-value pair in which the key is equal passed in char variable 
//Post-conditions: An object of the specified type of Book is instantiated
Transaction* TransFactory::createTransaction(char transType) const {

	if (transMap.find(transType) == transMap.end())
	{
		return nullptr;
	}
	else
	{
		int subscript = transMap.at(transType);
		return transFac[subscript]->create();
	}
}

