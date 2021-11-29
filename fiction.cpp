#include "fiction.h"

//----------------------------------------------------------------------------
// Default Constructor
Fiction::Fiction() {
    author = "";
}

//----------------------------------------------------------------------------
// Destructor
Fiction::~Fiction() {}

//----------------------------------------------------------------------------
// returnItemType():
char Fiction::returnItemType() const {
    return itemType;
}

//----------------------------------------------------------------------------
// returnBookType():
char Fiction::returnBookType() const {
    return bookType;
}

//----------------------------------------------------------------------------
// operator = : Assignment operator, creates deep copy of the Item& anItem
// passed in
// @pre:
//@post:
Item& Fiction::operator=( const Item& item) {
    const Fiction& aFiction = static_cast<const Fiction&>(item);

    this->title = aFiction.title;
    this->year = aFiction.year;
    this->author = aFiction.author;
    this->numInLib = aFiction.numInLib;

    return *this;
}

bool Fiction::operator==( const Item& item ) const
{
    const Fiction& aFiction = static_cast<const Fiction&>(item);

    return (this->title == aFiction.title && this->author == aFiction.author);
}

bool Fiction::operator!=( const Item& item ) const
{
    return !this->operator==( item );
}

bool Fiction::operator<( const Item& item ) const
{
    //sorted by author, then title
    if (this->operator==( item )) {
		return false;
    }

    const Fiction& aFiction = static_cast<const Fiction&>(item);
    if (this->author < aFiction.author) {
		return true;
    }
    else if (this->author == aFiction.author) {
        return this->title < aFiction.title;
    }
    return false;
}

bool Fiction::operator>( const Item& item ) const
{
    const Fiction& aFiction = static_cast<const Fiction&>(item);

    if (this->operator==( item ) || this->operator<( item )) {
        return false;
    }

    if (this->author > aFiction.author) {
        return true;
    }
    else if (this->author == aFiction.author) {
        return this->title > aFiction.title;
    }
    return false;
}

Item* Fiction::create() const {
    return new Fiction;
}

void Fiction::setData( istream& infile)
{
    getline( infile, author, ',' );     // input author

    /*infile.get();
    getline( infile, authorLast, ',' );*/

    infile.get();                     // get (and ignore) blank before title
    getline( infile, title, ',' );    // input title
    infile >> year;                  // input year
	
    itemType = 'B';     // setting itemType -> Item class
    numInLib = 5;       // setting numer of Book copies -> Item class
    bookType = 'F';     // setting bookType -> Book class
    maxNumInLib = 5;
}

//----------------------------------------------------------------------------
//print(): method to send private data members to display
void Children::print(ostream& os) const {
    cout << numInLib << "     " << author << "     " << title <<
    "     " << year;
}
