/*
@File contents: Children class function and variable declarations

@Purpose: The Children Class is a derived class of Book and Item, thus can be
stored inside of BinTree's Nodes. Children holds a only a couple private data
members annd all of definitions for the virtual functions declared in its Base
classes Book & Item

@Assumptions: The Base class of Item and Book are defined

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Chidren objects are instantiated within the FacDriver class
to create new empty children object that can be inserted into a BinTree.
Children class defines all the virtual functions of its Base classes Item and
Book. Children methods include create() to instantiate a children object,
setData to set the private and protected data members of the object, and a few
different print functions for displaying the catalogue of the library, to
display the header of the book type contained
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

public:
    Children(); // constructor
    virtual ~Children(); // destructor
    virtual char returnItemType() const; // return ItemType method
    virtual char returnItemType_Genre() const; // return ItemType genre method
    virtual Item* create() const;        // create method
    virtual bool setData( istream& );    // setData method
    virtual bool setSearchData( istream& ); // set search data method
    virtual void printItem( ostream& os ) const; // print item method
    virtual void printHeader() const;    // print header method
    virtual void printKeyInfo() const;   // print key info method

    //virtual comparison operators
    virtual Item& operator=( const Item& );
    virtual bool operator==( const Item& ) const;
    virtual bool operator!=( const Item& ) const;
    virtual bool operator<( const Item& ) const;
    virtual bool operator>( const Item& ) const;

// private data members of children
private:
    string author; // author of children book
    string const HEADER = "CHILDRENS BOOKS"; // const string holding HEADER
};

#endif
