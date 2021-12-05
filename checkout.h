#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <string>
#include "item.h"
#include "patron.h"
#include "librarymanager.h"
#include "transaction.h"
#include "factorydriver.h"
using namespace std;

class Checkout : public Transaction
{

private:
    Item* theItem;                     // the book that is being returned
    Patron* thePatron;                 // the Patron that returns the book

public:
    Checkout();                     // default constructor
    //Checkout( Item*, Patron* );       // constructor for class Return
    virtual ~Checkout();
    virtual void setData( istream& );
    virtual Transaction* create() const;
    virtual void doTransaction( Storage&, HashMap& );   // overridden from Transaction
                                                      // performs return on book and
                                                      // adds this Return object to Patron's history
};

#endif

