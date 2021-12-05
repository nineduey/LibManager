/*
@File contents: Fiction function and variable declarations
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
*/
//-----------------------------------------------------------------------------
#ifndef FICTION_H
#define FICTION_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Fiction : public Book
{
    //const string fictionBookDeclar = "FICTION BOOK";


public:
    Fiction();
    virtual ~Fiction();
    virtual char returnItemType() const;
    virtual char returnItemType_Genre() const;
    virtual Item* create() const;
    virtual void setData( istream& );
    virtual void setData( string, string, int, int );
    virtual void print( ostream& os ) const;

    // virtual comparison operators
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& ) const;
    virtual bool operator!=( const Item& ) const;
    virtual bool operator<( const Item& ) const;
    virtual bool operator>( const Item& ) const;

private:
    string author;

};

#endif

