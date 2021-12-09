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
	this->itemFormat = aPeriodical.itemFormat;

	return *this;
}

//----------------------------------------------------------------------------
// operator == : 
// @pre:
// @post:
bool Periodical::operator==( const Item& item ) const
{

	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	return (this->year == aPeriodical.year && this->month == aPeriodical.month
		&& this->title == aPeriodical.title);
}

//----------------------------------------------------------------------------
// operator != : 
// @pre:
// @post:
bool Periodical::operator!=( const Item& item ) const
{

	return !operator==( item );
}

//----------------------------------------------------------------------------
// operator < : 
// @pre:
// @post:
bool Periodical::operator<( const Item& item ) const
{
	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	if (this->year < aPeriodical.year)
	{
		return true;
	}
	else if (this->year == aPeriodical.year)
	{
		if (this->month < aPeriodical.month)
		{
			return true;
		}
		else if (this->month == aPeriodical.month)
		{
			return (this->title < aPeriodical.title);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	return false;
}

//----------------------------------------------------------------------------
// operator > : 
// @pre:
// @post:
bool Periodical::operator>( const Item& item ) const
{
	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	if (this->year > aPeriodical.year)
	{
		return true;
	}
	else if (this->year == aPeriodical.year)
	{
		if (this->month > aPeriodical.month)
		{
			return true;
		}
		else if (this->month == aPeriodical.month)
		{
			return (this->title > aPeriodical.title);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
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
void Periodical::setData( istream& infile )
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
	itemFormat = itemFormats[0];   //setting the format type of the book
}

//----------------------------------------------------------------------------
// setData():
// data members
// @pre:
// @post:
void Periodical::setDataInput( istream& infile )
{
	infile >> itemFormat >> year >> month;
	infile.get();
	getline( infile, title, ',' );
	itemType = 'B';
	bookType = 'P';
}

//----------------------------------------------------------------------------
// print(): method to print the data members of fiction class & its base class
// data members
// @pre:
// @post:
void Periodical::print( ostream& out ) const
{
	out << numInLib << "      " << setw( TITLE_SPACE_LENGTH );
	out << left << title << setw( MONTH_SPACE_LENGTH );
	out << left << month << setw( YEAR_SPACE_LENGTH );
	out << right << year;
}

//----------------------------------------------------------------------------
// printHeader(): method to print the genre of book and headings for avail, 
// title, month and year
void Periodical::printHeader() const
{
	cout << "---------------" << endl;
	cout << HEADER << endl;
	cout << "---------------" << endl;
	cout << "AVAIL" << "   " << left << setw( TITLE_SPACE_LENGTH ) <<
		"TITLE" << left << setw( MONTH_SPACE_LENGTH ) <<
		"MONTH" << right << setw( YEAR_SPACE_LENGTH ) << "YEAR" << endl;
}