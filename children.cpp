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
Item& Children::operator=( const Item& item)
{
	const Children& aChildren = static_cast<const Children&>(item);

	this->title = aChildren.title;
	this->year = aChildren.year;
	this->author = aChildren.author;
	this->numInLib = aChildren.numInLib;

	return *this;
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Children::operator==( const Item& item) const
{
	const Children& aChildren = static_cast<const Children&>(item);

	return (this->title == aChildren.title && this->author == aChildren.author);
}
//----------------------------------------------------------------------------
//operator != : 
//@pre:
//@post:
bool Children::operator!=( const Item& item) const
{
	return !this->operator==( item );
}

//----------------------------------------------------------------------------
//operator < : 
//@pre:
//@post:
bool Children::operator<( const Item& item) const
{
	if(this->operator==( item ))
	{
		return false;
	}

	const Children& aChildren = static_cast<const Children&>(item);

	if(this->title < aChildren.title)
	{
		return true;
	}
	else if(this->title == aChildren.title)
	{
		return this->author < aChildren.author;
	}
	return false;
}

//----------------------------------------------------------------------------
//operator > : 
//@pre:
//@post:
bool Children::operator>( const Item& item) const
{
	if(this->operator==(item) || this->operator<(item))
	{
		return false;
	}

	const Children& aChildren = static_cast<const Children&>(item);

	if (this->title > aChildren.title)
	{
		return true;
	}
	else if (this->title == aChildren.title)
	{
		return this->author > aChildren.author;
	}
	return false;
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
void Children::setData( istream& infile)
{
	getline( infile, author, ',');     // input author, looks for comma terminator

	infile.get();                     // get (and ignore) blank before title

	getline( infile, title, ',' );      // input title

	infile >> year;                   // input year

	itemType = 'B';   // setting itemType -> Item class
	numInLib = 5;     // setting numer of Book copies -> Item class
	bookType = 'C';   // setting bookType -> Book class
	maxNumInLib = 5;	// setting the max number of book copies in library
}

//----------------------------------------------------------------------------
//print():
// @pre:
// @post:
void Children::print( ostream& os ) const
{
	os << numInLib << "      " << setw(AUTHOR_SPACE_LENGTH);
	os << left << author << setw(TITLE_SPACE_LENGTH); 
	os << right << title << setw(YEAR_SPACE_LENGTH);
	os << right << year;
}
