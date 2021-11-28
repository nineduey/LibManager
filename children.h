/*
@File contents: Children class function definitions
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
*/
//-----------------------------------------------------------------------------
#ifndef CHILDREN_H
#define CHILDREN_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Children : public Book 
{

private:

    string author;

    const int AUTHOR_SPACE_LENGTH = 9; //size of the space after author output
    const int TITLE_SPACE_LENGTH = 9;  //size of the space after title output

public:
    Children();
    ~Children();
    virtual char returnItemType() const;
    virtual char returnBookType() const;
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& ) const;
    virtual bool operator!=( const Item& ) const;
    virtual bool operator<( const Item& ) const;
    virtual bool operator>( const Item& ) const;
    virtual Item* create() const;
    virtual void setData( istream& );

    virtual void display( const Item& ) const;
};

#endif

