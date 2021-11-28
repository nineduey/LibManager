/*
@File contents: Fiction class function definitions
@Purpose:
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
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
    //consts for output (TODO: put in a dictionary)
    //const string fictionBookDeclar = "FICTION BOOK";
    
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
};

#endif

