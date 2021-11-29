
/*
@File contents: Periodical class function definitions
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
  
private:

    int month;

    const int MONTH_SPACE_LENGTH = 4; //size of the space after month output
    const int YEAR_SPACE_LENGTH = 4;  //size of the space after year output

public:
    Periodical();
    ~Periodical();
    virtual Item* create() const;
    virtual void setData( istream& ); 
    virtual void print(ostream& os) const;
    virtual char returnItemType() const;
    virtual char returnBookType() const;
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& ) const;
    virtual bool operator!=( const Item& ) const;
    virtual bool operator<( const Item& ) const;
    virtual bool operator>( const Item& ) const;

};

#endif
