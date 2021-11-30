/*
@File contents: Periodical class function definitions
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

<<<<<<< Updated upstream
const int MONTH_SPACE_LENGTH = 4; //size of the space after month output
const int YEAR_SPACE_LENGTH = 4;  //size of the space after year output
=======
>>>>>>> Stashed changes

class Periodical : public Book
{
    friend ostream& operator<<(ostream&, const Item&);

private:
    int month;

public:
    Periodical();
    ~Periodical();
    virtual Item& operator=(const Item&);
    virtual bool operator==(const Item&);
    virtual bool operator!=(const Item&);
    virtual bool operator<(const Item&);
    virtual bool operator>(const Item&);
    virtual Item* create() const;
    virtual void setData(istream&);
    virtual void print(ostream& os) const;
  
public:
    Periodical();  // constructor
    ~Periodical(); // destructor
    virtual char returnItemType() const;
    virtual char returnItemType_Genre() const;
    virtual Item* create() const;
    virtual void setData(istream&);
    virtual void print(ostream& os) const;

    // virtual comparison operators
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& ) const;
    virtual bool operator!=( const Item& ) const;
    virtual bool operator<( const Item& ) const;
    virtual bool operator>( const Item& ) const;

private:
    int month; // month of book published

};

#endif
