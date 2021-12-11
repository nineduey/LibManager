/*
@File contents: Periodical class function and variable declarations

@Purpose: The Periodical Class is a derived class of Book and Item, thus can be
stored inside of BinTree's Nodes. Periodical holds a only a couple private data
members annd all of definitions for the virtual functions declared in its Base
classes Book & Item

@Assumptions: The Base class of Item and Book are defined

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Periodical objects are instantiated within the FacDriver class
to create new empty Periodical object that can be inserted into a BinTree.
Periodical class defines all the virtual functions of its Base classes Item and
Book. Periodical methods include create() to instantiate a Periodical object,
setData to set the private and protected data members of the object, and a few
different print functions for displaying the catalogue of the library, to
display the header of the book type contained
*/
//-----------------------------------------------------------------------------
#include "periodical.h"
#include <iomanip>


//-----------------------------------------------------------------------------
// Default Constructor
// @Pre: None
// @Post: a new Periodical object is created that is empty, only holds default 
// values
Periodical::Periodical()
{
	month = 0;
}

//----------------------------------------------------------------------------
// Destructor
// @Pre: None
// @Post: Periodical object and its private & protected data members are erased
// from memory
Periodical::~Periodical() {}

//----------------------------------------------------------------------------
// returnItemType() : method to return the itemType of the Item object, for
// implementation, this should return 'B' for book. The data member itemType
// is stored within Periodical's base class ->Item
//@pre: None
//@post: Returns a char stored in the data member variable called ItemType
char Periodical::returnItemType() const
{
	return itemType;
}

//----------------------------------------------------------------------------
// returnItemType_Genre() : method to return the bookType of the Book object, 
// for implementation, this should return 'P' for Periodical. The data member 
// itemType is stored within Periodical's base class ->Book
// @Pre: None
// @Post: Returns a char stord in the data member variable called bookType
char Periodical::returnItemType_Genre() const
{
	return bookType;
}

//----------------------------------------------------------------------------
// operator = : Assignment operator, creates deep copy of the Item& anItem
// passed in. Uses static casting for comparison of base class object to 
// derived class object. 
// @pre: Function's argument must be a referenced Item object
// @post:  Returns a referenced Item object ( current object) that
// hold the same values of the data members of the argument passed in
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
//operator == : method to compare current object (derived class of Item) to 
// another Item object for equality. Uses static casting for compaison of 
// base class object to derived class object. 
//@pre:  Function's argument must be a referenced Item object
//@post: Returns a boolean value based on if the Item object is equivalent to
// to the current object (which is a derived class of Item)
bool Periodical::operator==( const Item& item ) const
{

	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	return (this->year == aPeriodical.year && this->month == aPeriodical.month
		&& this->title == aPeriodical.title);
}

//----------------------------------------------------------------------------
//operator != : method to compare current object (derived class of Item) for
// in equality. Uses static casting for compaison of base class object to 
// derived class object
//@pre: Function's argument must be a referenced Item object
//@post: Returns a boolean value determined by if the current object is not 
// equivalent to the item passed in as an arguement
bool Periodical::operator!=( const Item& item ) const
{

	return !operator==( item );
}

//----------------------------------------------------------------------------
//operator < : method to compare current object (derived class of Item) for
// lesser than item being passed in as arg. Uses static casting for compaison 
// of base class object to  derived class object.
//@pre: Function's argument must be a referenced Item object
//@post: Returns a boolean value determined by if the current object is lesser 
// than the item passed in as an argument
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
//operator > : method to compare current object (derived class of Item) for
// greater than item being passed in as arg. Uses static casting for comparison 
// of base class object to derived class object
// @pre: Function's argument must be a referenced Item object
// @post: Returns a boolean value determined by if the current object is greater 
// than the item passed in as an arguement
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
// create() : method to create a new Periodical object
// @Pre: None
// @Post: Returns a pointer to a new Periodical object
Item* Periodical::create() const
{
	return new Periodical;
}

//----------------------------------------------------------------------------
// setData() : method to set the private and protected data member of the 
// current Periodical object. Private data members of the current object are 
// set to the data that in pulled in from the istream.  Each piece of data is 
// tested for validity before it moved on to the next piece of data. 
// @Pre: Function takes a referenced istream object
// @Post: Private data members of the current object are set to the data that
// in pulled in from the istream. Boolean value is return if the data pulled
// in was valid and set correctly
bool Periodical::setData( istream& infile )
{
	getline( infile, title, ',' );// input author, looks for comma terminator
	if (title.size() < 1)
	{
		cout << "ERROR: Title of book not given." << endl;
		string invalidLine;
		getline( infile, invalidLine );
		return false;
	}

	infile.get();                // get (and ignore) blank before month
	infile >> month;
	if (month < 1 || month > 12)
	{
		cout << "ERROR: Valid month number is not given." << endl;
		string invalidLine;
		getline( infile, invalidLine );
		return false;
	}

	infile.get();
	if (infile.peek() == '\n')
	{
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
// setSearchData(): method to set a limited number of private data members of
// the current Periodical object to enable a search to be conducted in the
// data structure that holds it. 
// @Pre: Function takes a referenced istream object
// @Post: Private data members of the current object are set to the data that
// in pulled in from the istream. Boolean value is return if the data pulled
// in was valid and set correctly
bool Periodical::setSearchData( istream& infile )
{
	 infile >> itemFormat;
	 bool itemFormatIsValid = false;;
	 for (int i : itemFormats) {
		  if (itemFormat == itemFormats[0]) {
				itemFormatIsValid = true;
				break;
		  }
	 }
	 if (!itemFormatIsValid) {
		  cout << "ERROR: The given item format " << itemFormat
				<< " is not valid." << endl;
		  return false;
	 }

	 infile >> year >> month;
	 infile.get();
	 getline(infile, title, ',');

	 bookType = 'P';
	 return true;
}

//----------------------------------------------------------------------------
//print(): method to print the private and protected data members of current
// object being held within the Periodical class and its base classes. 
// @Pre: Funtion takes a referenced ostream object to send the data memeber
// to the ostream with << 
// @Post: Private and protected data memeber are send to ostream with <<,
// returns void
void Periodical::printItem( ostream& out ) const
{
	out << numInLib << "      " << setw( TITLE_SPACE_LENGTH );
	out << left << title << setw( MONTH_SPACE_LENGTH );
	out << left << month << setw( YEAR_SPACE_LENGTH );
	out << right << year;
}

//----------------------------------------------------------------------------
// printHeader(): method to print the genre of book and headings for avail,
// author, title, and year
// @Pre: None
// @Post: Private HEADER constant variable along with identifying data names
// are sent to cout <<  for display
void Periodical::printHeader() const
{
	cout << "---------------" << endl;
	cout << HEADER << endl;
	cout << "---------------" << endl;
	cout << "AVAIL" << "   " << left << setw( TITLE_SPACE_LENGTH ) <<
		"TITLE" << left << setw( MONTH_SPACE_LENGTH ) <<
		"MONTH" << right << setw( YEAR_SPACE_LENGTH ) << "YEAR" << endl;
}

//----------------------------------------------------------------------------
// printKeyInfo() : method to print only select private data members
// considered key for error messages and error checking purposes
// @Pre: None
// @Post: Select data memebrs are sent to cout <<  for display
void Periodical::printKeyInfo() const{

	cout << this->title << "     " << this->month << "     " << this->year;
}
