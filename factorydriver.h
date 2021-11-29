/*
@File contents: Function and variable declarations of the FactoryDriver class

@Purpose: Calls createItem() function of appropriate derived ItemFactory
class to instantiate an Item object of a specific type

@Assumptions: The ItemFactory class has derived classes that are associated with 
the derived classes of the Item class. The derived classes of ItemFactory are defined. 

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Determines which derived class of ItemFactory should be used to 
instiate an object, based on the indicated type of the object that needs to be 
created. Calls createItem() function of the appropriate derived ItemFactory 
class to create an Item of the specified type
*/

#ifndef FACTORYDRIVER_H
#define FACTORYDRIVER_H
#include "itemfactory.h"
#include "bookfactory.h"
#include "item.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

class FactoryDriver
{

public:

	//----------------------------------------------------------------------------
	//FactoryDriver(): Default constructor for FactoryDriver class. 
	//The 'factoryTypeMap' map and 'factories' vector are populated. 
	//Pre-conditions:None
	//Post-conditions: 'factoryTypeMap' map and 'factories' vector are populated.
	FactoryDriver();

	//----------------------------------------------------------------------------
	//~FactoryDriver(): Destructor of FactoryDriver class
	//Pre-conditions: None
	//Post-Conditions: Deletes the ItemFactory objects of 'factories' vector from 
	//memory
	~FactoryDriver();

	//----------------------------------------------------------------------------
	//createItem(): Instantiates book object to equal Item object of the type 
	//associated with the first char variable passed in and the type of this 
	//type of Item object, which is associated with the second char variable passed
	//in. (For a fiction book, parameters would equal 'B' for Item type Book and 
	//'F' for Book type Fiction 
	//Pre-conditions: 'factories' vector contains the ItemFactory object that creates 
	//Items of the type associated with the first argument. The map 
	//contains a key-value pair in which the key is equal to the first argument. 
	//Post-conditions: An Item object of the specified type is instantiated. 
	Item* createItem( char, char ) const;

private:

	std::map<char, int> factoryTypeMap;		//keys are chars indicating the type of Item, 
											//values are ints indicating which index in 
											//the factories vector an ItemFactory object
											//contains a ItemFactory object of type specified
											//by the key

	vector<ItemFactory*> factories;			//contains objects of derived classes of ItemFactory 
};
#endif

