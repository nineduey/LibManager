/*
@File contents: Item.cpp function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------
#include "item.h"

<<<<<<< Updated upstream
//Default Constrcutor
Item::Item() {
	 left = nullptr;
   right = nullptr;
=======


//-----------------------------------------------------------------------------
// Default Constrcutor: method to initialize private & protected data members
Item::Item() {
	 left = nullptr;
    right = nullptr;
>>>>>>> Stashed changes
	 numInLib = 0;
	 maxNumInLib = 5;
	 itemType = 'I';
}

//----------------------------------------------------------------------------
<<<<<<< Updated upstream
// Destructor
=======
>>>>>>> Stashed changes
// Destructor: sets the left and right Item pointers to null
Item::~Item() {
	 left = nullptr;
	 right = nullptr;
}


//----------------------------------------------------------------------------
<<<<<<< Updated upstream
// checkOut() : method to check out a book from the library
=======
>>>>>>> Stashed changes
// checkOut(): method to check out an Item contained in Library catalogue
// @pre:
// @post:
void Item::checkOut() {
	 if (numInLib > 0) {
		  numInLib--;
		  return;
	 }
	 cout << "Error: Cannot check out, no more copies available." << endl;
}


//----------------------------------------------------------------------------
<<<<<<< Updated upstream
// checkIn() : method to check in a book from the library
=======
>>>>>>> Stashed changes
// checkIn(): method to check out an Item contained in Library catalogue
// @pre:
// @post:
void Item::checkIn() {
	 if (numInLib < maxNumInLib) {
		  numInLib++;
		  return;
	 }
	 cout << "Error: Cannot check in, no room in Library." << endl;
}


<<<<<<< Updated upstream
//----------------------------------------------------------------------------  should this be virtual?
// returnItemType() : method to return the type of object being held within 
// the item class
=======
//----------------------------------------------------------------------------
>>>>>>> Stashed changes
char Item::returnItemType() const {
	 return itemType;
}


//----------------------------------------------------------------------------
<<<<<<< Updated upstream
// validate() : method to check the input data being set as data members of 
// Item object class
=======
>>>>>>> Stashed changes
//----------------------------------------------------------------------------
// validate(): method to validate contained within object is valid
// @pre:
// @post:
bool Item::validate() const {

}


ostream& operator<<(ostream& out, const Item& anItem) {
	 anItem.print(out);
	 return out;
<<<<<<< Updated upstream
}
=======
}
>>>>>>> Stashed changes
