/*
@File contents: Function and variable declarations of the Storage class
@Purpose: Contains a map of BinTree objects, each containing Item
objects of a specific type. Has functionality to append to the map,
retrieve a BinTree object from the map,retrieve an Item object from
one of the BinTrees in the map, display the items in the map  and
and delete the objects in the map
@Assumptions: The BinTree class is defined and contains Item objects
@Authors:Shushmitha Radjaram and Amanda Todakonzie
@How code is used: A newly instantiated Item is inserted into the
Library's catalouge by calling the append() function.
A book is retrieved from the Library's catalogue by calling the
retrieveItem() function.
*/

#ifndef STORAGE_H
#define STORAGE_H
#include "bintree.h"
#include "item.h"
#include <map>
#include <iostream>
using namespace std;

class Storage
{
	friend ostream& operator<<( ostream&, const Storage& );
	//friend class BinTree;

public:

	//-------------------------------------------------------------------
	//Storage(): Initializes a Storage object
	//Pre-conditions: None
	//Postconditions: Instantiates a Storage object
	Storage();

	//-------------------------------------------------------------------
	//Storage Destructor: calls makeEmpty() function to delete values
	//(the BinTree objects) of map 'binTreeMap'
	//Pre-conditions: None
	//Postconditions: Values of binTreeMap are deleted from memory
	~Storage();

	//-------------------------------------------------------------------
	// makeEmpty(): Iteratively deletes each value in the binTreeMap
	// Pre-conditions: None
	// Postconditions: Values of binTreeMap are deleted from memory
	void makeEmpty();

	//-------------------------------------------------------------------	
	//append(): Calls retrieveMinTree() to find which which BinTree object 
	//in the binTreeMap contains Item object(s) of the same type of the Item 
	//object passed in. 
	//Once the corresponding BinTree object it found, the Item object is 
	//inserted in the tree. 
	//If a corresponding BinTree object cannot be found, a new BinTree 
	//object that holds Item objects which are 
	//the same type as the object passed in is instantiated and 
	//appended to the binTreeMap
	//Pre-conditions: None
	//Postconditions: An Item is added its corresponding BinTree
	//based on its type
	void append( Item* );

	//-------------------------------------------------------------------
	//retrieveItem(): Finds an Item object stored inside one of the 
	//BinTree objects in the binTreeMap that is a match with the Item 
	//object of the pointer passed in for the first argument. A pointer
	//to a reference of the Item object found is assigned to the 
	//second argument.
	//Pre-conditions: None
	//Postconditions: A pointer to a reference of the Item object we want 
	//to retrieve is assigned to the second argument. If the item object 
	//we want to retrieve exists, function returns true. If not, function 
	//returns false.
	bool retrieveItem( Item*, Item*& ) const;

	//-------------------------------------------------------------------
	//retrieveBinTree(): Finds an BinTree object stored in binTreeMap 
	//that is contains Item objects which are the same type as the  
	//with the Item object of the pointer passed in for the first argument. 
	//A pointer to a reference of the BinTree object 
	//found is assigned to the second argument.
	//Pre-conditions: None
	//Postconditions: A pointer to a reference of the Item object we want 
	//to retrieve is assigned to the second argument. If the item object 
	//we want to retrieve exists, function returns true. If not, function 
	//returns false.
	bool retrieveBinTree( Item*, BinTree*& ) const;

	//--------------------------------------------------------------------
	//print(): Displays the data of the Item objects held in the BinTree
	//objects of the binTreeMap by Item category.
	//Pre-conditions: None
	//Post-conditions: Data of all Items stored in the libraryare/binTreeMap
	//are displayed 
	void print( ostream& ) const; //--determine what parameter(s) this function should take

private:

	//Keys of map are 2-element char arrays. The first element indicates the 
	//type of the Items in the corresponding BinTree object and 
	//the second element indicates the subtype of the Items in the corresponding 
	//BinTree object.
	//Values are BinTree objects containing Item objects that are all have the 
	//same Item type and subtype
	map<string, BinTree*> binTreeMap;

};

#endif