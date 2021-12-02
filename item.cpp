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
	left = nullptr;
	right = nullptr;
	numInLib = 0;
	maxNumInLib = 5;
	itemType = 'I';
}

//----------------------------------------------------------------------------
// Destructor: sets the left and right Item pointers to null
Item::~Item(){
	left = nullptr;
	right = nullptr;
}


//----------------------------------------------------------------------------
// checkOut(): method to check out an Item contained in Library catalogue
// @pre:
// @post:
void Item::checkOut(){
	
	if (numInLib > 0){
		numInLib--;
		return;
	}
	cout << "Error: Cannot check out, no more copies available." << endl;
}


//----------------------------------------------------------------------------
// checkIn(): method to check out an Item contained in Library catalogue
// @pre:
// @post:
void Item::checkIn(){
	
	if (numInLib < maxNumInLib){
		numInLib++;
		return;
	}
	cout << "Error: Cannot check in, no room in Library." << endl;
}

//----------------------------------------------------------------------------
// validate(): method to validate contained within object is valid
// @pre:
// @post:
bool Item::validate() const{
	
	if (numInLib >= 0 && numInLib <= maxNumInLib){
		return true;
	}
	return false;
}

