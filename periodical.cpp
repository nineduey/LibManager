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
bool Periodical::setData( istream& infile )
{
	getline( infile, title, ',' );// input author, looks for comma terminator
	if (title.size() < 1){
		cout << "ERROR: Title of book not given." << endl;
		string invalidLine;
		getline( infile, invalidLine );
		return false;
	}

	infile.get();                // get (and ignore) blank before month
	infile >> month;
	if(month < 1 || month > 12){
		cout << "ERROR: Valid month number is not given." << endl;
		string invalidLine;
		getline( infile, invalidLine );
		return false;
	}

	infile.get();
	if (infile.peek() == '\n'){
		cout << "ERROR: Year the book was published is not given." << endl;
		return false;
	}
	infile >> year;                   // input year

	numInLib = 5;     // setting numer of Book copies -> Item class
	bookType = 'P';   // setting bookType -> Book class
	maxNumInLib = 5;	// setting the max number of book copies in library
	itemFormat = itemFormats[0];   //setting the format type of the book
	return true;
}

//----------------------------------------------------------------------------
// setData():
// data members
// @pre:
// @post:
bool Periodical::setDataInput( istream& infile )
{
	infile >> itemFormat;
	bool itemFormatIsValid = false;;
	for (int i : itemFormats){
		if (itemFormat == itemFormats[0]){
			itemFormatIsValid = true;
			break;
		}
	}
	if (!itemFormatIsValid){
		cout << "ERROR: The given item format " << itemFormat
			<< " is not valid." << endl;
		string invalidLine;
		getline( infile, invalidLine );
		return false;
	}

	infile >> year;
	if (year == 0){
		cout << "ERROR: Year the book was published is not given." << endl;
		string invalidLine;
		getline( infile, invalidLine );
		return false;
	}

	infile.get();
	infile >> month;
	if (month < 1 || month > 12){
		cout << "ERROR: Valid month number is not given." << endl;
		string invalidLine;
		getline( infile, invalidLine );
		return false;
	}

	infile.get();
	getline( infile, title, ',' );
	if (title.size() < 1){
		cout << "ERROR: Title of book not given." << endl;
		string invalidLine;
		getline( infile, invalidLine );
		return false;
	}

	bookType = 'P';
	return true;
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

void Periodical::printKeyInfo() const{

	cout << this->title << "     " << this->month << "     " << this->year;
}
