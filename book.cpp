#/*
@File contents: Book.cpp function definitions
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
*/
//-----------------------------------------------------------------------------

#include "book.h"

ostream& operator<<( ostream& out, const Book& aBook ){
    aBook.print( out );
    return out;
}

//----------------------------------------------------------------------------
// Default Constructor: sets default values when creating a new instance
Book::Book(){
    title = "";
    year = 1000;
    bookType = ' ';
    itemType = 'I';
    bookFormatTypes[0] = 'B';
}

//----------------------------------------------------------------------------
// Destructor
Book::~Book() {}

//----------------------------------------------------------------------------
// print() : Virtual print function, will display data members of Book object
void Book::print( ostream& out ) const{
    this->print( out );
}
