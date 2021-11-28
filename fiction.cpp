#include "fiction.h"
#include <iomanip>


// Default Constructor
Fiction::Fiction()
{
	 author = "";
}

//----------------------------------------------------------------------------
// Destructor
Fiction::~Fiction(){}

//----------------------------------------------------------------------------
// operator = : Assignment operator, creates deep copy of the Item& anItem
// passed in
// @pre:
//@post:
Item& Fiction::operator=(const Item& item)
{
	 const Fiction& aFiction = static_cast<const Fiction&>(item);

	 this->title = aFiction.title;
	 this->year = aFiction.year;
	 this->author = aFiction.author;
	 this->numInLib = aFiction.numInLib;

	 return *this;
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Fiction::operator==(const Item& item)
{
	 const Fiction& aFiction = static_cast<const Fiction&>(item);

	 return (this->title == aFiction.title && this->author == aFiction.author);
}

//----------------------------------------------------------------------------
//operator != : 
//@pre:
//@post:
bool Fiction::operator!=(const Item& item)
{
	 return !this->operator==(item);
}

//----------------------------------------------------------------------------
//operator < : 
//@pre:
//@post:
bool Fiction::operator<(const Item& item)
{
	 //sorted by author, then title

	 if (this->operator==(item))
	 {
		  return false;
	 }

	 const Fiction& aFiction = static_cast<const Fiction&>(item);

	 if (this->author < aFiction.author)
	 {
		  return true;
	 }
	 else if (this->author == aFiction.author)
	 {
		  return this->title < aFiction.title;
	 }
}

//----------------------------------------------------------------------------
//operator > : 
//@pre:
//@post:
bool Fiction::operator>(const Item& item)
{
	 const Fiction& aFiction = static_cast<const Fiction&>(item);

	 if (this->operator==(aFiction) || this->operator<(aFiction))
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
}

//----------------------------------------------------------------------------
//create() : 
//@pre:
//@post:
Item* Fiction::create() const {
	 return new Fiction;
}

//----------------------------------------------------------------------------
//setData() : 
//@pre:
//@post:
void Fiction::setData(istream& infile)
{
	 getline(infile, author, ',');     // input author, looks for comma terminator

	 /*infile.get();
	 getline( infile, authorLast, ',' );*/

	 infile.get();                     // get (and ignore) blank before title
	 getline(infile, title, ',');      // input title
	 infile >> year;                   // input year

	 itemType = 'B';     // setting itemType -> Item class
	 numInLib = 5;       // setting numer of Book copies -> Item class
	 bookType = 'F';     // setting bookType -> Book class
}

//----------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Fiction& aFiction)
{
	 aFiction.print(out);
	 return out;
}

//----------------------------------------------------------------------------
void Fiction::print(ostream& os) const {
	 cout << numInLib << "     " << author << "     " << title << "     " << year;
}
