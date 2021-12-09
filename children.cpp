/*
@File contents: Chidlren.cpp function definitions
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
*/
//-----------------------------------------------------------------------------
#include "children.h"
#include <iomanip>

//sorted by title, then author


// Default Constructor
Children::Children()
{
	author = "";
}

//----------------------------------------------------------------------------
// Destructor
Children::~Children() {}

//----------------------------------------------------------------------------
//returnItemType() :  method to return the itemType of the Item object, for
// implementation, this should return 'B' for book. The data member itemType
// is stored within ChilDren's base class ->Item
//@pre:
//@post:
char Children::returnItemType() const
{
	return itemType;
}

//----------------------------------------------------------------------------
//returnItemType_Genre() :
char Children::returnItemType_Genre() const
{
	return bookType;
}

//----------------------------------------------------------------------------
// operator = : Assignment operator, creates deep copy of the Item& anItem
// passed in
// @pre:
// @post:
Item& Children::operator=( const Item& item )
{
	const Children& aChildren = static_cast<const Children&>(item);

	this->title = aChildren.title;
	this->year = aChildren.year;
	this->author = aChildren.author;
	this->numInLib = aChildren.numInLib;
	this->itemFormat = aChildren.itemFormat;

	return *this;
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Children::operator==( const Item& item ) const
{
	const Children& aChildren = static_cast<const Children&>(item);

	return (this->title == aChildren.title && this->author == aChildren.author);
}
//----------------------------------------------------------------------------
//operator != : 
//@pre:
//@post:
bool Children::operator!=( const Item& item ) const
{
	return !this->operator==( item );
}

//----------------------------------------------------------------------------
//operator < : 
//@pre:
//@post:
bool Children::operator<( const Item& item ) const
{
	//if (this->operator==( item ))
	//{
	//	return false;
	//}

	const Children& aChildren = static_cast<const Children&>(item);

	if (this->title < aChildren.title)
	{
		return true;
	}
	else if (this->title == aChildren.title)
	{
		return this->author < aChildren.author;
	}
	else
	{
		return false;
	}
}

//----------------------------------------------------------------------------
//operator > : 
//@pre:
//@post:
bool Children::operator>( const Item& item ) const
{
	//if (this->operator==( item ) || this->operator<( item ))
	//{
	//	return false;
	//}

	const Children& aChildren = static_cast<const Children&>(item);

	if (this->title > aChildren.title)
	{
		return true;
	}
	else if (this->title == aChildren.title)
	{
		return this->author > aChildren.author;
	}
	else
	{
		return false;
	}
}
//----------------------------------------------------------------------------
//create() : 
//@pre:
//@post:
Item* Children::create() const
{
	return new Children;
}

//----------------------------------------------------------------------------
//setData() : 
//@pre:
//@post:
void Children::setData( istream& infile ){
	getline( infile, author, ',' );     // input author, looks for comma terminator
	infile.get();                     // get (and ignore) blank before title
	getline( infile, title, ',' );      // input title
	infile >> year;                   // input year

	itemType = 'B';   // setting itemType -> Item class
	numInLib = 5;     // setting numer of Book copies -> Item class
	bookType = 'C';   // setting bookType -> Book class
	maxNumInLib = 5;	// setting the max number of book copies in library
	itemFormat = itemFormats[0];   //setting the format type of the book
}

//----------------------------------------------------------------------------
// setDataInput():
// data members
// @pre:
// @post:
void Children::setDataInput( istream& infile ){
	infile >> itemFormat;
	infile.get();
	getline( infile, title, ',' );
	infile.get();
	getline( infile, author, ',' );
	itemType = 'B';
	bookType = 'C';
}

//----------------------------------------------------------------------------
//print():
// @pre:
// @post:
void Children::print( ostream& out ) const
{
	out << numInLib << "      " << setw( AUTHOR_SPACE_LENGTH );
	out << left << author << setw( TITLE_SPACE_LENGTH );
	out << left << title << setw( YEAR_SPACE_LENGTH );
	out << right << year;
}

//----------------------------------------------------------------------------
// printHeader(): method to print the genre of book and headings for avail, 
// author, title, and year
void Children::printHeader() const
{
	cout << "---------------" << endl;
	cout << HEADER << endl;
	cout << "---------------" << endl;
	cout << "AVAIL" << "   " << left << setw( AUTHOR_SPACE_LENGTH ) <<
		"AUTHOR" << setw( TITLE_SPACE_LENGTH ) <<
		"TITLE" << right << setw( YEAR_SPACE_LENGTH ) << "YEAR" << endl;
	return;
}