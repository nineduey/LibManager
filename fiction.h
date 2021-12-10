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

public:
    Fiction();
    virtual ~Fiction();
    virtual char returnItemType() const;
    virtual char returnItemType_Genre() const;
    virtual Item* create() const;
    virtual void setData( istream& );
    virtual void setDataInput( istream& infile );
    virtual void print( ostream& os ) const;
    virtual void printHeader() const;
    virtual void printKeyInfo() const;

    // virtual comparison operators
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& ) const;
    virtual bool operator!=( const Item& ) const;
    virtual bool operator<( const Item& ) const;
    virtual bool operator>( const Item& ) const;

private:
    string author;
    string const HEADER = "FICTION BOOKS";

};

#endif


