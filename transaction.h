/*
@File contents: Function and variable declarations of the Transaction class

@Purpose: Transaction class serves as an abstract class for the derived classes
that handle commands being read into the program from the readTransaction()
method of the libraryManager class. Derived classes include Checkout, Return,
PatronHistory and DisplayCatalogue. Each derived class handles a transaction
process particular to its own class.

@Assumptions:  Derived classes of the Transaction class are defined.

@Authors: Shushmitha Radjaram and Amanda Todakonzie
*/
//-----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <fstream>
#include <string>
#include "storage.h"
#include "hashmap.h"
#include "patron.h"
using namespace std;

class Transaction
{

public:
    Transaction(); // default constructor
    virtual ~Transaction(); // virtual destructor
    virtual Transaction* create() const = 0; // virtual create method
    virtual bool setData( istream& ) = 0; // virtual set data method
    // virtual doTransaction method, defined in derived classes
    virtual void doTransaction( Storage&, HashMap& ) = 0;  
};

#endif
