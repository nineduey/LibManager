/*
@File contents: Item.cpp function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------
#include "item.h"


// operator << :
ostream& operator<<(ostream& out, const Item& anItem) {
	 anItem.print(out);
	 return out;
}

//---------------------------------------------------------------------------
//Default Constrcutor
Item::Item() {
	 left = nullptr;
   right = nullptr;
	 numInLib = 0;
	 itemType = 'I';
}

//----------------------------------------------------------------------------
// Destructor
Item::~Item() {
	 left = nullptr;
	 right = nullptr;
}


//----------------------------------------------------------------------------
// checkOut() : method to check out a book from the library
void Item::checkOut() {
	 if (numInLib > 0) {
		  numInLib--;
		  return;
	 }
	 cout << "Error: Cannot check out, no more copies available." << endl;
}


//----------------------------------------------------------------------------
// checkIn() : method to check in a book from the library
void Item::checkIn() {
	 if (numInLib < maxNumInLib) {
		  numInLib++;
		  return;
	 }
	 cout << "Error: Cannot check in, no room in Library." << endl;
}

//----------------------------------------------------------------------------
// print() : method to call virtual print function for ostream operator<<
void Item::print(ostream& os) const {
	 this->print(os);
}

//----------------------------------------------------------------------------
// validate() : method to check the input data being set as data members of 
// Item object class
bool Item::validate() const {

}
