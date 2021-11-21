#ifndef RETURN_H
#define RETURN_H
#include <string>
#include "transaction.h"

class Return : private Transaction {

private:

    Book* book;                              // the book that is checked out
    Patron* patron;                   // the Patron that checks the book out

public:

    Return(Book*, Patron*);                  	// constructor for class Return

    void doTransaction();                     	// overridden from Transaction
                                              // performs checkout on book and
                                     // adds book to Patron's checked out list

};

#endif
