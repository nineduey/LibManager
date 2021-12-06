/*
@File contents: Function and variable declarations
of the Transaction class
@Purpose:
@Assumptions
@Authors: Shushmitha Radjaram and Amanda Todakonzie
@How code is used:
*/
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <fstream>
#include <string>
#include "storage.h"
#include "hashmap.h"
#include "patron.h"
using namespace std;

//class HashMap;

class Transaction
{

public:
    Transaction(); // default constructor
    virtual ~Transaction(); // virtual destructor
    virtual Transaction* create() const = 0; //virtual create method to return a pointer to the certain transaction type object
    virtual void setData( istream& ) = 0; // virtual set data method
    virtual void doTransaction( Storage&, HashMap& ) = 0;   // performs whichever transaction based on the type of derived class created
    virtual void clear() = 0;
};

#endif

