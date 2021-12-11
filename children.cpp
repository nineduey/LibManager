/*
@File contents: Children class function and variable declarations

@Purpose: The Children Class is a derived class of Book and Item, thus can be
stored inside of BinTree's Nodes. Children holds a only a couple private data
members annd all of definitions for the virtual functions declared in its Base
classes Book & Item

@Assumptions: The Base class of Item and Book are defined

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Chidren objects are instantiated within the FacDriver class
to create new empty children object that can be inserted into a BinTree
*/
//-----------------------------------------------------------------------------
#include "children.h"
#include <iomanip>


//-----------------------------------------------------------------------------
// Default Constructor
// @Pre: None
// @Post: a new Children object is created that is empty, only holds default 
// values
Children::Children()
{
	author = "";
}

//----------------------------------------------------------------------------
// Destructor
// @Pre: None
// @Post: Children object and its private & protected data members are erased
// from memory
Children::~Children() {}

//----------------------------------------------------------------------------
//returnItemType() : method to return the itemType of the Item object, for
// implementation, this should return 'B' for book. The data member itemType
// is stored within ChilDren's base class ->Item
//@pre: None
//@post: Returns a char stored in the data member variable called ItemType
char Children::returnItemType() const
{
	return itemType;
}

//----------------------------------------------------------------------------
//returnItemType_Genre() : method to return the bookType of the Book object, 
// for implementation, this should return 'C' for Children. The data member 
// itemType is stored within Children's base class ->Book
// @Pre: None
// @Post: Returns a char stord in the data member variable called bookType
char Children::returnItemType_Genre() const
{
	return bookType;
}

//----------------------------------------------------------------------------
// operator = : Assignment operator, creates deep copy of the Item& anItem
// passed in. Uses static casting for compaison of base class object to 
// derived class object. 
// @pre: Function's argument must be a referenced Item object
// @post:  Returns a referenced Item object ( current object) that
// hold the same values of the data members of the argument passed in
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
//operator == : method to compare current object (derived class of Item) to 
// another Item object for equality. Uses static casting for compaison of 
// base class object to derived class object. 
//@pre:  Function's argument must be a referenced Item object
//@post: Returns a boolean value based on if the Item object is equivalent to
// to the current object (which is a derived class of Item)
bool Children::operator==( const Item& item ) const
{
	const Children& aChildren = static_cast<const Children&>(item);

	return (this->title == aChildren.title && this->author == aChildren.author);
}
//----------------------------------------------------------------------------
//operator != : method to compare current object (derived class of Item) for
// in equality. Uses static casting for compaison of base class object to 
// derived class object. 
//@pre: Function's argument must be a referenced Item object
//@post: Returns a boolean value determined by if the current object is not 
// equivalent to the item passed in as an arguement
bool Children::operator!=( const Item& item ) const
{
	return !this->operator==( item );
}

//----------------------------------------------------------------------------
//operator < : method to compare current object (derived class of Item) for
// lesser than item being passed in as arg. Uses static casting for compaison 
// of base class object to  derived class object.
//@pre:   Function's argument must be a referenced Item object
//@post: Returns a boolean value determined by if the current object is lesser 
// than the item passed in as an argument
bool Children::operator<( const Item& item ) const
{

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
//operator > : method to compare current object (derived class of Item) for
// greater than item being passed in as arg. Uses static casting for comparison 
// of base class object to derived class object
// @pre: Function's argument must be a referenced Item object
// @post: Returns a boolean value determined by if the current object is greater 
// than the item passed in as an arguement
bool Children::operator>( const Item& item ) const
{
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
// create() : method to create a new Children object
// @Pre: None
// @Post: Returns a pointer to a new Children object
Item* Children::create() const
{
	return new Children;
}

//----------------------------------------------------------------------------
// setData() : method to set the private and protected data member of the 
// current Children object. Private data members of the current object are set
// to the data that in pulled in from the istream.  Each piece of data is 
// tested for validity before it moved on to the next piece of data. 
// @Pre: Function takes a referenced istream object
// @Post: Private data members of the current object are set to the data that
// in pulled in from the istream. Boolean value is return if the data pulled
// in was valid and set correctly
bool Children::setData( istream& infile ){


	 getline(infile, author, ',');  // input author, looks for comma terminator
	 if (author.size() < 1) {
		  cout << "ERROR: Name of author not given." << endl;
		  string invalidLine;
		  getline(infile, invalidLine);
		  return false;
	 }

	 infile.get();                    // get (and ignore) blank before title
	 getline(infile, title, ',');      // input title
	 if (title.size() < 1) {
		  cout << "ERROR: Title of book not given." << endl;
		  string invalidLine;
		  getline(infile, invalidLine);
		  return false;
	 }

	 if (infile.peek() == '\n') {
		  cout << "ERROR: Year the book was published is not given." << endl;
		  return false;
	 }
	 infile >> year;                   // input year

	 numInLib = 5;     // setting numer of Book copies -> Item class
	 bookType = 'C';   // setting bookType -> Book class
	 maxNumInLib = 5;	// setting the max number of book copies in library
	 itemFormat = itemFormats[0];   //setting the format type of the book
	 return true;
}

//----------------------------------------------------------------------------
// setSearchData(): method to set a limited number of private data members of
// the current Children object to enable a search to be conducted in the
// data structure that holds it. 
// @Pre: Function takes a referenced istream object
// @Post: Private data members of the current object are set to the data that
// in pulled in from the istream. Boolean value is return if the data pulled
// in was valid and set correctly
bool Children::setSearchData( istream& infile ){

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

	 infile.get();
	 getline(infile, title, ','); // input author, looks for comma terminator
	 infile.get();                // get (and ignore) blank before title
	 getline(infile, author, ','); // input title
	 bookType = 'C';
	 return true;
}

//----------------------------------------------------------------------------
//print(): method to print the private and protected data members of current
// object being held within the Children class and its base classes. 
// @Pre: Funtion takes a referenced ostream object to send the data memeber
// to the ostream with << 
// @Post: Private and protected data memeber are send to ostream with <<,
// returns void
void Children::printItem( ostream& out ) const
{
	out << numInLib << "      " << setw( AUTHOR_SPACE_LENGTH );
	out << left << author << setw( TITLE_SPACE_LENGTH );
	out << left << title << setw( YEAR_SPACE_LENGTH );
	out << right << year;
}

//----------------------------------------------------------------------------
// printHeader(): method to print the genre of book and headings for avail,
// author, title, and year
// @Pre: None
// @Post: Private HEADER constant variable along with identifying data names
// are sent to cout <<  for display
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

//----------------------------------------------------------------------------
// printKeyInfo() : method to print only select private data members
// considered key for error messages and error checking purposes
// @Pre: None
// @Post: Select data memebrs are sent to cout <<  for display
void Children::printKeyInfo() const{

	cout << this->author << "    " << this->title << "    " << this->year;
}
