#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <string>
#include "transaction.h"
#include "factorydriver.h"
using namespace std;


class Checkout : public Transaction
{

private:
    Item* theItem;                     // the book that is being returned
    int patronID;             // the Patron that returns the book
    FactoryDriver facDriver;  // factory to create Item objects

public:
    Checkout();                     // default constructor
    virtual ~Checkout();
    virtual bool setData( istream& );
    virtual Transaction* create() const;
    virtual void doTransaction( Storage&, HashMap& );   // overridden from Transaction
                                                      // performs return on book and
                                                      // adds this Return object to Patron's history
};

#endif

