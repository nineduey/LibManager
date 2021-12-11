/*
@File contents: Book class function and variable declarations

@Purpose: The Book Class is a derived class of Item, thus can be stored inside
of BinTree's Nodes. Book holds a only a few private data members and hold the
constant int variables used for the the printing of the Book's information

@Assumptions: The Base class of Item and its derived class (type) is defined

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Book objects are instantiated within the FacDriver class to
create new empty book objects that can be inserted into a BinTree
*/
//-----------------------------------------------------------------------------

#include "book.h"

//-----------------------------------------------------------------------------
// ostream operator << : allows the protected data members of book and its
// derived class to be printed to the output screen
// @Pre: Function takes a referenced ostream object and a referenced Book
// object
// @Post: Method called print function on the Book object, taking the ostream
// as an argument, and allows the Book's contents to be displayed to the screen
ostream& operator<<( ostream& out, const Book& aBook ){
    aBook.print( out );
    return out;
}

//----------------------------------------------------------------------------
// Default Constructor: sets default values when creating a new instance
// @Pre: None
// @Post: Book's data members will be initialized to the default values below.
Book::Book(){
    title = "";
    year = 1000;
    itemType = 'B';
    bookType = ' ';
    itemFormat = ' ';
}

//----------------------------------------------------------------------------
// Destructor
// @Pre: None
// @Post: Virtual destuctor will be called based on the derived class.
Book::~Book() {}
