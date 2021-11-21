#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <string>
#include "transaction.h"

class Checkout : private Transaction {

private:

    Book* book;                              // the book that is checked out
    Patron* patron;                   // the Patron that checks the book out

public:

    Checkout(Book*, Patron*);              	// constructor for class Checkout

    void doTransaction();                     	// overridden from Transaction
                                                 // performs return on book and
                                           // adds checkout to Patron's history

};
