/*
@File contents: Item.cpp function definitions
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
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
Item::Item(){
	numInLib = 0;
	//itemFormat = "";
	maxNumInLib = 5;
	itemType = 'I';
	itemFormats[0] = 'H';   //represents hardcopy item
	itemFormat = ' ';
}

//----------------------------------------------------------------------------
// Destructor: sets the left and right Item pointers to null
Item::~Item(){}


//----------------------------------------------------------------------------
// checkOut(): method to check out an Item contained in Library catalogue
// @pre:
// @post:
bool Item::checkOut(){
	
	if (numInLib > 0){
		numInLib--;
		return true;
	}

	return false;
}


//----------------------------------------------------------------------------
// checkIn(): method to check out an Item contained in Library catalogue
// @pre:
// @post:
bool Item::checkIn(){
	
	if (numInLib < maxNumInLib){
		numInLib++;
		return true;
	}
	return false;
}

