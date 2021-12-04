#ifndef RETURN_H
#define RETURN_H
#include <string>
#include "book.h";
#include "patron.h"
#include "transaction.h"

class Return : public Transaction {

private:
    Item* theItem;                     // the book that is being returned
    Patron* thePatron;                 // the Patron that returns the book

public:
    Return();                     // default constructor
    Return(Item*, Patron*);       // constructor for class Return
    ~Return();
    virtual void setData(istream&);
    virtual Transaction* create() const;
    virtual void doTransaction(Storage&, HashMap&);   // overridden from Transaction
                                                      // performs return on book and
                                                      // adds this Return object to Patron's history
};

#endif
