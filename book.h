/*
@File contents: Book class function and variable declarations

@Purpose: The Book Class is a derived class of Item, thus can be stored inside
of BinTree's Nodes. Book holds a only a few private data members and hold the
constant int variables used for the the printing of the Book's information

@Assumptions: The Base class of Item and its derived class (type) is defined

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Book objects are instantiated within the FacDriver class to
create new empty book objects that can be inserted into a BinTree
*/
//-----------------------------------------------------------------------------
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "item.h"
#include <string>
using namespace std;

//global constants to be used in derived classes
const int AUTHOR_SPACE_LENGTH = 26; //size of the space after author output
const int TITLE_SPACE_LENGTH = 33;  //size of the space after title output
const int MONTH_SPACE_LENGTH = 10; //size of the space after month output
const int YEAR_SPACE_LENGTH = 10;  //size of the space after year output

class Book : public Item
{
    friend ostream& operator<<( ostream&, const Book& );

public:
    Book(); // constructor
    virtual ~Book(); // destructor

    //virtual methods
    virtual char returnItemType() const = 0; // virtual return ItemType method
    // virtual return ItemType genre method
    virtual char returnItemType_Genre() const = 0;
    virtual Item* create() const = 0;     // virtual create method
    virtual bool setData( istream& ) = 0; // virtual set data method
    // virtual set search data method
    virtual bool setSearchData( istream& ) = 0;
    // virutal print item method
    virtual void printItem( ostream& os ) const = 0;
    virtual void printHeader() const = 0;  // virtual print header method
    virtual void printKeyInfo() const = 0; // virtual print key info method

    //virtual comparison operators
    virtual Item& operator=( const Item& ) = 0;
    virtual bool operator==( const Item& ) const = 0;
    virtual bool operator!=( const Item& ) const = 0;
    virtual bool operator<( const Item& ) const = 0;
    virtual bool operator>( const Item& ) const = 0;


//protected data members of Book
protected:
    string title;
    int year;
    char bookType;
};

#endif
