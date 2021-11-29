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
ostream& operator<<(ostream& out, const Item& anItem) {
	 anItem.print(out);
	 return out;
}

Item::Item() {
	 left = nullptr;
	 right = nullptr;
	 numInLib = 0;
	 maxNumInLib = 5;
	 itemType = 'I';
}

//----------------------------------------------------------------------------
Item::~Item() {
	 left = nullptr;
	 right = nullptr;
}


//----------------------------------------------------------------------------
void Item::checkOut() {
	 if (numInLib > 0) {
		  numInLib--;
		  return;
	 }
	 cout << "Error: Cannot check out, no more copies available." << endl;
}


//----------------------------------------------------------------------------
void Item::checkIn() {
	 if (numInLib < maxNumInLib) {
		  numInLib++;
		  return;
	 }
	 cout << "Error: Cannot check in, no room in Library." << endl;
}


//----------------------------------------------------------------------------
char Item::returnItemType() const {
	 return itemType;
}


//----------------------------------------------------------------------------
bool Item::validate() const {
	 if (numInLib >= 0 && numInLib <= maxNumInLib) {
		  return true;
	 }
	 return false;
}

void Item::print(ostream& os) const {
	 this->print(os);
}

