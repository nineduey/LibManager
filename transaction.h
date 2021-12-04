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
#include "book.h"
#include "patron.h"
#include "librarymanager.h"



class Transaction {

public:
    Transaction(); // default constructor
    virtual ~Transaction(); // virtual destructor
    virtual void doTransaction(Storage*&, HashMap*&) = 0;   // performs whichever transaction based on the type of derived class created
};

#endif
