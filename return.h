#ifndef RETURN_H
#define RETURN_H
#include <string>
#include "patron.h"
#include "transaction.h"
#include "factorydriver.h"

class Return : public Transaction {

private:
    Item* theItem;            // the book that is being returned
    int patronID;             // the Patron that returns the book
    FactoryDriver facDriver;  // factory to create Item objects

public:
    Return();                 // default constructor
    Return(Item*, int);   // constructor for class Return
    ~Return();
    virtual void setData(istream&);
    virtual Transaction* create() const;
    virtual void doTransaction(Storage&, HashMap&);   // overridden from Transaction
                                                      // performs return on book and
                                                      // adds this Return object to Patron's history
};

#endif