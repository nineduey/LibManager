/*
@File contents: Book.cpp function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------

#include "book.h"

ostream& operator<<(ostream& out, const Book& aBook) {
<<<<<<< Updated upstream
    aBook.print(out);
    return out;
=======
	 aBook.print(out);
	 return out;
>>>>>>> Stashed changes
}

//----------------------------------------------------------------------------
// Default Constructor: sets default values when creating a new instance
Book::Book() {
<<<<<<< Updated upstream
    title = "";
    year = 1000;
    bookType = 'B';
    itemType = 'I';
=======
	 title = "";
	 year = 1000;
    bookType = 'B';
	 itemType = 'I';
>>>>>>> Stashed changes
}

//----------------------------------------------------------------------------
// Destructor
Book::~Book() {}

//----------------------------------------------------------------------------
// print() : Virtual print function, will display data members of Book object
void Book::print(ostream& os) const {
<<<<<<< Updated upstream
    this->print(os);
=======
	 this->print(os);
>>>>>>> Stashed changes
@File contents: Book class function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------
#include "book.h"

//----------------------------------------------------------------------------
// Default Constructor
Book::Book()
{
	 title = "";
	 year = 0000;
	 bookType = 'B';
}

//----------------------------------------------------------------------------
// Destructor
Book::~Book() {}
