#include "item.h"


Item::Item() {
	 left = nullptr;
    right = nullptr;
	 numInLib = 5;
	 maxNumInLib = 5;
	 objectType = 'I';
}

Item::~Item() {
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

char Item::returnObjectType() const {
	 return objectType;
}
