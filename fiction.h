#ifndef FICTION_H
#define FICTION_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Fiction : public Book
{
    friend ostream& operator<<( ostream&, const Item& );

private:

    string author;
    
    //consts for output (TODO: put in a dictionary)
    //const string fictionBookDeclar = "FICTION BOOK";
    const int AVAILABILITY_LENGTH = 6;
    const int AUTHOR_LENGTH = 9;
    const int TITLE_LENGTH = 9;

public:
    Fiction();
    ~Fiction();
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& );
    virtual bool operator!=( const Item& );
    virtual bool operator<( const Item& );
    virtual bool operator>( const Item& );
    virtual Item* create() const;
    virtual void setData( istream& );
};

#endif

