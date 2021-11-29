#include "periodical.h"

//----------------------------------------------------------------------------
// Default Constructor
Periodical::Periodical() {
    month = 0;
}

//----------------------------------------------------------------------------
// Destructor
Periodical::~Periodical() {}

//----------------------------------------------------------------------------
//returnItemType():
char Periodical::returnItemType() const {
    return itemType;
}
//----------------------------------------------------------------------------
//returnBookType():
char Periodical::returnBookType() const {
    return bookType;
}

//----------------------------------------------------------------------------
//operator = : Assignment operator, creates deep copy of the Item& anItem
//passed in
//@pre:
//@post:
Item& Periodical::operator=( const Item& item ) {
    const Periodical& aPeriodical = static_cast<const Periodical&>(item);
    this->title = aPeriodical.title;
    this->month = aPeriodical.month;
    this->year = aPeriodical.year;
    return *this;
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Periodical::operator==( const Item& item ) const {
    const Periodical& aPeriodical = static_cast<const Periodical&>(item);

    return (this->year == aPeriodical.year && this->month == aPeriodical.month);
}

//----------------------------------------------------------------------------
//operator != : 
//@pre:
//@post:
bool Periodical::operator!=( const Item& item ) const {
    return !operator==(item);
}

//----------------------------------------------------------------------------
//operator < : 
//@pre:
//@post:
bool Periodical::operator<( const Item& item ) const {
    //sorted by date (year, then month), then by title 
    if (this->operator==( item )) {
        return false;
    }
    //static cast of item object as periodical
    const Periodical& aPeriodical = static_cast<const Periodical&>(item);
        if (this->year < aPeriodical.year) {
            return true;
	}
	else if (this->month == aPeriodical.month) {
            return this->month < aPeriodical.month;
	}
	return false;
}

//----------------------------------------------------------------------------
//operator > : 
//@pre:
//@post:
bool Periodical::operator>( const Item& item ) const {
    //sorted by date (year, then month), then by title 
    if (this->operator==( item ) || this->operator<( item )) {
        return false;
    }
    //static cast of item object as periodical
    const Periodical& aPeriodical = static_cast<const Periodical&>(item);

    if (this->year > aPeriodical.year) {
		return true;
    }
    else if (this->month == aPeriodical.month) {
        return this->month > aPeriodical.month;
    }
    return false;
}

//----------------------------------------------------------------------------
//create() : 
//@pre:
//@post:
Item* Periodical::create() const {
    return new Periodical;
}

//----------------------------------------------------------------------------
//setData() : 
//@pre:
//@post:
void Periodical::setData( istream& infile) {
    getline( infile, title, ',' ); // input author, looks for comma terminator
    infile.get();                  // get (and ignore) blank before month
    infile >> month;
    infile.get();                  // get (and ignore) blank before year
    infile >> year;                // input year

    itemType = 'B';
    bookType = 'P';
    numInLib = 5;
    maxNumInLib = 5;
}

//----------------------------------------------------------------------------
void Periodical::print(ostream& os) const {
    cout << numInLib << "     " << title << ",     " << month <<
    " " << year;
}
