/*
@File contents: Function and variable declarations of the ItemFactory class

@Purpose: Base class for derived classes of ItemFactory.

@Assumptions: This class has derived classes that are associated with the 
derived classes of the Item class. The derived classes are defined. 

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: The FactoryDriver class contains a vector of ItemFactory objects.
Depending on the type of Item object that needs to be created, the createItem()
function of the appropriate derived class of ItemFactory will be called on to
create an Item object. createItem() is a virtual function 
in ItemFactory class and will be defined by a derived class to instantiate 
an Item object of the indicated type. 
*/

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "item.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

class ItemFactory
{

public:

	//----------------------------------------------------------------------------
	//ItemFactory(): Default Constructor 
	//Pre-conditions:None
	//Post-conditions: An ItemFactory object is instantiated 
	ItemFactory();

	//*Question: do we need this destructor ? , does it actually need a function body ? ?
	//---------------------------------------------------------------------------- 
	//ItemFactory(): Default Constructor 
	//Pre-conditions:None
	//Post-conditions: ItemFactory object is deleted  
	~ItemFactory();

	//----------------------------------------------------------------------------
	//createItem(): Pure virtual function that will be used by derived classes
	//to instantiate Items of a specific type.
	//Pre-conditions: A char variable indicating type of the specific type of item
	//(i.e. a Fiction Book has type F).
	//Post-conditions: An object of the specified type of Item is instantiated
	virtual Item* createItem( char ) const = 0;

};
#endif



