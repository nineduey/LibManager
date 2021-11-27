
#include "children.h"
#include <string>
using namespace std;

Children::Children() {
	authorFirst = "";
	authorLast = "";
}

Children::~Children() {

}

virtual Item& Children::operator=(const Item&) {

}

virtual bool Children::operator==(const Item&) {

}

virtual bool Children::operator!=(const Item&) {

}

virtual bool Children::operator<(const Item&) {

}


virtual bool Children::operator>(const Item&) {
}

virtual Item* Children::create() const { 
	return new Item*; 
}

virtual void Children::setData(ifstream&) {

}
