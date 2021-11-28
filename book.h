/*
@File contents: Book class function and variable declarations
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

//class Item;
//class Fiction;
//class Children;
//class Periodical;

class Book : public Item {

protected:
    string title;
    int year;
    char bookType;

public:
    Book();
    ~Book();
    virtual Item* create() const = 0;
    virtual void setData( istream& ) = 0;
    virtual void print(ostream&) const = 0;
    virtual char returnItemType() const;
    virtual char returnBookType() const = 0;
    virtual Item& operator=( const Item& ) = 0;
    virtual bool operator==( const Item& ) const = 0;
    virtual bool operator!=( const Item& ) const = 0;
    virtual bool operator<( const Item& ) const = 0;
    virtual bool operator>( const Item& ) const = 0;
};

#endif
// Override compare opperator in the 3 type so that if they 
// encounter the first equal comparing, then move to the next criteria.
// Check for other override.
