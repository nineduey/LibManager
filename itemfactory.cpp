/*
@File contents: Default constructor and destructor defintions of the ItemFactory class

@Purpose: Base class for derived classes of ItemFactory.

@Assumptions: This class has derived classes that are associated with the
derived classes of the Item class

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: The FactoryDriver class contains a vector of ItemFactory objects.
The ItemFactory class's default constructor will be called to create these
objects to populate the vector.
*/

#include "itemfactory.h"

//----------------------------------------------------------------------------
//ItemFactory(): Default Constructor 
//Pre-conditions:None
//Post-conditions: An ItemFactory object is instantiated 
ItemFactory::ItemFactory() {}

//ItemFactory(): Default Constructor 
//Pre-conditions:None
//Post-conditions: ItemFactory object is deleted  
ItemFactory::~ItemFactory() {}