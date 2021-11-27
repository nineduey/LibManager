/*
@File contents: Item.cpp function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------

#include "item.h"
#include "book.h"

Item::Item() {
	left = nullptr;
    right = nullptr;
	numInLib = 5;
	maxNumInLib = 5;
	//itemType is set in derived class constructors
}

Item::~Item() {
	left = nullptr;
	right = nullptr;
}

void Item::checkOut() {
	 if (numInLib > 0) {
		  numInLib--;
		  return;
	 }
	 cout << "Error: Cannot check out, no more copies available." << endl;
}

void Item::checkIn() {
	 if (numInLib < maxNumInLib) {
		  numInLib++;
		  return;
	 }
	 cout << "Error: Cannot check in, no room in Library." << endl;
}

char Item::returnItemType() const {
	 return itemType;
}
