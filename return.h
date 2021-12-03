#ifndef RETURN_H
#define RETURN_H
#include <string>
#include "book.h";
#include "patron.h"

class Return : private Transaction {

private:

    Book* theBook;                     // the book that is being returned
    Patron* thePatron;                 // the Patron that returns the book

public:

    Return();                     // default constructor
    Return(Book*, Patron*);       // constructor for class Return
    ~Return();
    void doTransaction();           // overridden from Transaction
                                    // performs return on book and
                                    // adds this Return object to Patron's history

};