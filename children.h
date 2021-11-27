/*
@File contents: Children class function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------
#ifndef CHILDREN_H
#define CHILDREN_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Children : public Book {

protected:
    string authorFirst;
    string authorLast;

public:
    Children();
    ~Children();
    virtual Item& operator=(const Item&);
    virtual bool operator==(const Item&);
    virtual bool operator!=(const Item&);
    virtual bool operator<(const Item&);
    virtual bool operator>(const Item&);
    virtual Item* create() const { return new Item; };
    virtual void setData(ifstream&);
};

#endif