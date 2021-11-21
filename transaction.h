#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <fstream>
#include <string>
#include “book.h”
#include “patron.h”

class Transaction {


public:

    static void readFile(ifstream&);            	// static readFile processes
                                                 //  transactions from a file
    virtual void doTransaction();         // performs whichever transaction

};

#endif
