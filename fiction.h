/*
@File contents: Fiction class function definitions
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@File contents: Fiction function and variable declarations

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

>>>>>>> Stashed changes
@How code is used:
*/
//-----------------------------------------------------------------------------
#ifndef FICTION_H
#define FICTION_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Fiction : public Book {

    friend ostream& operator<<(ostream&, const Item&);

private:

    string author;
<<<<<<< Updated upstream
    //consts for output (TODO: put in a dictionary)
class Fiction : public Book
{
    //const string fictionBookDeclar = "FICTION BOOK";
    
=======

    //consts for output (TODO: put in a dictionary)
    //const string fictionBookDeclar = "FICTION BOOK";
    

>>>>>>> Stashed changes
public:
    Fiction();
    ~Fiction();
    virtual Item& operator=(const Item&);
    virtual bool operator==(const Item&);
    virtual bool operator!=(const Item&);
    virtual bool operator<(const Item&);
    virtual bool operator>(const Item&);
    virtual Item* create() const;
    virtual void setData(istream&);
    virtual void print(ostream& os) const;
<<<<<<< Updated upstream
=======


public:
    Fiction();
    ~Fiction();
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
    string author;

>>>>>>> Stashed changes
};

#endif

