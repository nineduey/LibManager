/*
@File contents: Periodical.cpp function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------
#include "periodical.h"
#include <iomanip>



// Default Constructor
Periodical::Periodical()
{
	month = 0;
}

//----------------------------------------------------------------------------
// Destructor
Periodical::~Periodical()
{
}

//----------------------------------------------------------------------------
// returnItemType():
// @pre:
// @post:
char Periodical::returnItemType() const
{
	return itemType;
}

//----------------------------------------------------------------------------
// returnItemType_Genre():
// @pre:
// @post:
char Periodical::returnItemType_Genre() const
{
	return bookType;
}

//----------------------------------------------------------------------------
// operator = : Assignment operator, creates deep copy of the Item& anItem
// passed in
// @pre:
// @post:
Item& Periodical::operator=( const Item& item )
{
	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	this->title = aPeriodical.title;
	this->month = aPeriodical.month;
	this->year = aPeriodical.year;

	return *this;
}

//----------------------------------------------------------------------------
// operator == : 
// @pre:
// @post:
bool Periodical::operator==( const Item& item ) const
{
	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	return (this->year == aPeriodical.year && this->month == aPeriodical.month);
}

//----------------------------------------------------------------------------
// operator != : 
// @pre:
// @post:
bool Periodical::operator!=( const Item& item ) const
{
	return !operator==(item);
}

//----------------------------------------------------------------------------
// operator < : 
// @pre:
// @post:
bool Periodical::operator<( const Item& item ) const
{
	//sorted by date (year, then month), then by title 
	
	if (this->operator==( item ))
	{
		return false;
	}

	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	if (this->year < aPeriodical.year)
	{
		return true;
	}
	else if (this->month == aPeriodical.month)
	{
		return this->month < aPeriodical.month;
	}

	return false;
}

//----------------------------------------------------------------------------
// operator > : 
// @pre:
// @post:
bool Periodical::operator>( const Item& item ) const
{
	//sorted by date (year, then month), then by title 

	if (this->operator==( item ) || this->operator<( item ))
	{
		return false;
	}

	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	if (this->year > aPeriodical.year)
	{
		return true;
	}
	else if (this->month == aPeriodical.month)
	{
		return this->month > aPeriodical.month;
	}

	return false;
}

//----------------------------------------------------------------------------
// create() : 
// @pre:
// @post:
Item* Periodical::create() const
{
	return new Periodical;
}

//----------------------------------------------------------------------------
// setData():
// data members
// @pre:
// @post:
void Periodical::setData( istream& infile)
{
	getline( infile, title, ',' );// input author, looks for comma terminator

	infile.get();                // get (and ignore) blank before month

	infile >> month;

	infile.get();               // get (and ignore) blank before year

	infile >> year;             // input year

	itemType = 'B';   // setting itemType -> Item class
	numInLib = 5;     // setting numer of Book copies -> Item class
	bookType = 'P';   // setting bookType -> Book class
	maxNumInLib = 5;	// setting the max number of book copies in library
}
//----------------------------------------------------------------------------
// print(): method to print the data members of fiction class & its base class
// data members
// @pre:
// @post:
void Periodical::print( ostream& os ) const
{
	os << numInLib << "      " << setw(TITLE_SPACE_LENGTH);
	os << left << title << setw(MONTH_SPACE_LENGTH);
	os << right << month << setw(YEAR_SPACE_LENGTH);
	os << right << year;
}
