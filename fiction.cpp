/*
@File contents: Fiction.cpp function definitions
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
*/
//-----------------------------------------------------------------------------
#include "fiction.h"
#include <iomanip>


//sorted by title, then author


// Default Constructor
Fiction::Fiction()
{
	author = "";
}

//----------------------------------------------------------------------------
// Destructor
Fiction::~Fiction() {}

//----------------------------------------------------------------------------
// returnItemType():
// @pre:
// @post:
char Fiction::returnItemType() const
{
	return itemType;
}
//----------------------------------------------------------------------------
// returnItemType_Genre():
// @pre:
// @post:
char Fiction::returnItemType_Genre() const
{
	return bookType;
}
//----------------------------------------------------------------------------
// operator = : Assignment operator, creates deep copy of the Item& anItem
// passed in
// @pre:
//@post:
Item& Fiction::operator=( const Item& item )
{
	const Fiction& aFiction = static_cast<const Fiction&>(item);

	this->title = aFiction.title;
	this->year = aFiction.year;
	this->author = aFiction.author;
	this->numInLib = aFiction.numInLib;
	this->itemFormat = aFiction.itemFormat;

	return *this;
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Fiction::operator==( const Item& item ) const
{
	const Fiction& aFiction = static_cast<const Fiction&>(item);

	return (this->title == aFiction.title && this->author == aFiction.author);
}

//----------------------------------------------------------------------------
//operator != : 
//@pre:
//@post:
bool Fiction::operator!=( const Item& item ) const
{
	return !this->operator==( item );
}

//----------------------------------------------------------------------------
//operator < : 
//@pre:
//@post:
bool Fiction::operator<( const Item& item ) const
{
	const Fiction& aFiction = static_cast<const Fiction&>(item);

	if (this->author < aFiction.author)
	{
		return true;
	}
	else if (this->author == aFiction.author)
	{
		return this->title < aFiction.title;
	}

	return false;
}

//----------------------------------------------------------------------------
//operator > : 
//@pre:
//@post:
bool Fiction::operator>( const Item& item ) const
{
	const Fiction& aFiction = static_cast<const Fiction&>(item);

	if (this->operator==( item ) || this->operator<( item ))
	{
		return false;
	}

	if (this->author > aFiction.author)
	{
		return true;
	}
	else if (this->author == aFiction.author)
	{
		return this->title > aFiction.title;
	}

	return false;
}

//----------------------------------------------------------------------------
//create() : 
//@pre:
//@post:
Item* Fiction::create() const
{
	return new Fiction;
}

//----------------------------------------------------------------------------
//setData() : 
//@pre:
//@post:
bool Fiction::setData( istream& infile ){

	getline( infile, author, ',' );     // input author, looks for comma terminator
	if (author.size() < 1){
		cout << "ERROR: Name of author not given." << endl;
		string invalidLine = "";
		getline( infile, invalidLine );
		return false;
	}

	infile.get();                     // get (and ignore) blank before title
	getline( infile, title, ',' );      // input title
	if (title.size() < 1){
		cout << "ERROR: Title of book not given." << endl;
		string invalidLine = "";
		getline( infile, invalidLine );
		return false;
	}

	if (infile.peek() == '\n'){
		cout << "ERROR: Year the book was published is not given." << endl;
		return false;
	}
	infile >> year;                   // input year

	numInLib = 5;     // setting numer of Book copies -> Item class
	bookType = 'F';   // setting bookType -> Book class
	maxNumInLib = 5;	// setting the max number of book copies in library
	itemFormat = itemFormats[0];   //setting the format type of the book
	return true;
}

//----------------------------------------------------------------------------
// setDataInput():
// data members
// @pre:
// @post:
bool Fiction::setDataInput( istream& infile ){

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
		return false;
	}

	infile.get();
	getline( infile, author, ',' );
	infile.get();
	getline( infile, title, ',' );
	bookType = 'F';
	return true;
}

//----------------------------------------------------------------------------
//print():
// @pre:
// @post:
void Fiction::print( ostream& out ) const{
	out << numInLib << "      " << setw( AUTHOR_SPACE_LENGTH );
	out << left << author << setw( TITLE_SPACE_LENGTH );
	out << left << title << setw( YEAR_SPACE_LENGTH );
	out << right << year;
}

//----------------------------------------------------------------------------
// printHeader(): method to print the genre of book and headings for avail, 
// author, title, and year
void Fiction::printHeader() const
{
	cout << "---------------" << endl;
	cout << HEADER << endl;
	cout << "---------------" << endl;
	cout << "AVAIL" << "   " << left << setw( AUTHOR_SPACE_LENGTH ) <<
		"AUTHOR" << setw( TITLE_SPACE_LENGTH ) <<
		"TITLE" << right << setw( YEAR_SPACE_LENGTH ) << "YEAR" << endl;
	return;
}

void Fiction::printKeyInfo() const{

	cout << this->author << "    " << this->title << "    " << this->year;
}
