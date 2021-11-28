#ifndef PERIODICAL_H
#define PERIODICAL_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Periodical : public Book
{
    friend ostream& operator<<( ostream&, const Item& );

private:
    int month;

    const int MONTH_SPACE_LENGTH = 4; //size of the space after month output
    const int YEAR_SPACE_LENGTH = 4;  //size of the space after year output

public:
    Periodical();
    ~Periodical();
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& );
    virtual bool operator!=( const Item& );
    virtual bool operator<( const Item& );
    virtual bool operator>( const Item& );
    virtual Item* create() const;
    virtual void setData( istream& ); // need to change params
};

#endif
