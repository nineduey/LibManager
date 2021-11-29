#ifndef FICTION_H
#define FICTION_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Fiction : public Book
{

private:

    string author;
    
    //consts for output (TODO: put in a dictionary)
    //const string fictionBookDeclar = "FICTION BOOK";

    const int AUTHOR_SPACE_LENGTH = 10; //size of the space after author output
    const int TITLE_SPACE_LENGTH = 10;  //size of the space after title output

public:
    Fiction();
    ~Fiction();
    virtual char returnItemType() const;
    virtual char returnItemType_Type() const;
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& ) const;
    virtual bool operator!=( const Item& ) const;
    virtual bool operator<( const Item& ) const;
    virtual bool operator>( const Item& ) const;
    virtual Item* create() const;
    virtual void setData( istream& );

    virtual void print( ostream& os ) const;

    
};

#endif

