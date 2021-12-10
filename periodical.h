/*
@File contents: Periodical.h class Function and Variable Declarations
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
*/
//-----------------------------------------------------------------------------
#ifndef PERIODICAL_H
#define PERIODICAL_H
#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Periodical : public Book
{

public:
    Periodical();  // constructor
    virtual ~Periodical() = default; // destructor
    virtual char returnItemType() const;
    virtual char returnItemType_Genre() const;
    virtual Item* create() const;
    virtual bool setData( istream& );
    virtual bool setDataInput( istream& infile );
    virtual void print( ostream& ) const;
    virtual void printHeader() const;
    virtual void printKeyInfo() const;

    // virtual comparison operators
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& ) const;
    virtual bool operator!=( const Item& ) const;
    virtual bool operator<( const Item& ) const;
    virtual bool operator>( const Item& ) const;

private:
    int month; // month of book published
    string const HEADER = "PERIODICALS";
};

#endif