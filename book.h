/*
@File contents: Book class function and variable declarations
@Purpose: 

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "item.h"
#include <string>
using namespace std;

//global constants for output
const int AUTHOR_SPACE_LENGTH = 10; //size of the space after author output
const int TITLE_SPACE_LENGTH = 10;  //size of the space after title output
const int MONTH_SPACE_LENGTH = 10; //size of the space after month output
const int YEAR_SPACE_LENGTH = 10;  //size of the space after year output

<<<<<<< Updated upstream
//global constants to be used in derived classes
const int AVAILABILITY_LENGTH = 6;
const int AUTHOR_LENGTH = 9; // size of the space after author output
const int TITLE_LENGTH = 9; // size of the space after title output


class Book : public Item
{
    friend ostream& operator<<( ostream&, const Item& );
=======
// global constants
const int AUTHOR_SPACE_LENGTH = 9; //size of the space after author output
const int TITLE_SPACE_LENGTH = 9;  //size of the space after title output
const int MONTH_SPACE_LENGTH = 4; //size of the space after month output
const int YEAR_SPACE_LENGTH = 4;  //size of the space after year output

class Book: public Item {

    friend ostream& operator<<(ostream&, const Book&);
>>>>>>> Stashed changes

public:
    Book();
    ~Book();

    virtual Item& operator=(const Item&) const = 0;
    virtual bool operator==(const Item&) const = 0;
    virtual bool operator!=(const Item&) const = 0;
    virtual bool operator<(const Item&) const = 0;
    virtual bool operator>(const Item&) const = 0;
    virtual Item* create() const = 0;
<<<<<<< Updated upstream
    virtual void setData( istream& ) = 0;
=======
    virtual void setData(istream&) const = 0;
>>>>>>> Stashed changes
    virtual void print(ostream& os) const;

    virtual char returnItemType() const = 0;
    virtual char returnItemType_Genre() const = 0;
    virtual Item* create() const = 0;
    virtual void setData(istream&) = 0;
    virtual void print(ostream& os) const = 0;

    //virtual comparison operators
    virtual Item& operator=( const Item& ) = 0;
    virtual bool operator==( const Item& ) const = 0;
    virtual bool operator!=( const Item& ) const = 0;
    virtual bool operator<( const Item& ) const = 0;
    virtual bool operator>( const Item& ) const = 0;


protected:
    string title;
    int year;
    char bookType;
};

#endif
// Override compare opperator in the 3 type so that if they 
// encounter the first equal comparing, then move to the next criteria.
// Check for other override.
