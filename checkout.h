#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <string>
#include "patron.h"
#include "transaction.h"
#include "factorydriver.h"

class Checkout : public Transaction {

private:
    Item* theItem;            // the book that is being returned
    int patronID;             // the Patron that returns the book
    FactoryDriver facDriver;  // factory to create Item objects

public:

    Checkout();                     // default constructor
    Checkout(Item*, int);       // constructor for class Checkout
    Transaction* create() const;
    ~Checkout();
    void doTransaction(Storage&, HashMap&);           // overridden from Transaction
                                    // performs checkout on book and
                                    // adds this Checkout object to Patron's history

};

#endif
