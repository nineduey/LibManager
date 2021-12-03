#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <string>
#include "book.h";
#include "patron.h"

class Checkout : private Transaction {

private:

    Book* theBook;                     // the book that is checked out
    Patron* thePatron;                 // the Patron that checks the book out

public:

    Checkout();                     // default constructor
    Checkout(Book*, Patron*);       // constructor for class Checkout
    ~Checkout();
    void doTransaction();           // overridden from Transaction
                                    // performs checkout on book and
                                    // adds this Checkout object to Patron's history

};