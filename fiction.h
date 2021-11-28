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

    const int AUTHOR_SPACE_LENGTH = 9; //size of the space after author output
    const int TITLE_SPACE_LENGTH = 9;  //size of the space after title output

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

