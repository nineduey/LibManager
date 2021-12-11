/*
@File contents: Function definitions and variable initialization for Item Class

@Purpose: The Item class serves as an abstract class for its derived classes,
such as Book and Book's derived classes. Item pointers are stored inside of the
container BinTree Class's nodes.

@Assumptions: Its derived classes of Book, and Book's derived classes of
Childre, Fiction, and Periodical are defined as well as its containter BinTree

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Item objects are instantiated withint the FacDriver class to
create new empty objects of its derived classes that are defined.
*/
//-----------------------------------------------------------------------------
#include "item.h"

//-----------------------------------------------------------------------------
// ostream operator << : displays Item contentsm uses virtuak print()
// @pre: must be passed a referenced ostreeam obj and a referenced Item obj
// @post: calls on the virtual print() method, particular to its defined
// derived class
ostream& operator<<( ostream& out, const Item& anItem ){
	anItem.print( out );
	return out;
}

//-----------------------------------------------------------------------------
// Default Constrcutor: method to initialize private & protected data members
// @Pre:None
// @Post: Item's data members will be initialized to the default values below.
Item::Item(){
	numInLib = 0;
	maxNumInLib = 5;
	itemType = 'I';
	itemFormats[0] = 'H';  //represents hardcopy item
	itemFormat = ' ';
}

//----------------------------------------------------------------------------
// Destructor:
// @Pre: None
// @Post: Virtual destuctor will be called based on the derived class.
Item::~Item(){}

//----------------------------------------------------------------------------
// checkOut(): method to check out an Item contained in Library catalogue
// @pre: None
// @post: Item's data member numInLib will decrease by a value of 1 to show
// that a copy of item has been checked out of the library's catalogue
bool Item::checkOut(){

	if (numInLib > 0){
		numInLib--;
		return true;
	}

	return false;
}

//----------------------------------------------------------------------------
// checkIn(): method to check out an Item contained in Library catalogue
// @pre: None
// @post: Item's data member numInLib will increase by a value of 1 to show
// that a copy of item has been checked in to the library's catalogue
bool Item::checkIn(){

	if (numInLib < maxNumInLib){
		numInLib++;
		return true;
	}
	return false;
}
