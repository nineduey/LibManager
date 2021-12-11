/*
@File contents: Function and variable declarations of the Checkout class

@Purpose: Represents a command to checkout a particular book from the 
library catalogue.

@Assumptions: The the library's catalogue has been populated with items
and patrons have been registered in the library system

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code will be used: When the command to create a Checkout object is
read in, the TransFactory will create an a new Checkout object, which
the virtual doTransaction method is called upon it. This class holds the
definition of the doTransaction() which will checkout an object from the
library
*/
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
    Checkout();                        //default constructor, 
    virtual ~Checkout();               //destructor         
    virtual bool setData( istream& );  //sets data for item and patron involved in 
                                       //the checkout transaction 

    virtual Transaction* create() const;    //creates and return new Checkout object
    virtual void doTransaction( Storage&, HashMap& ); // overridden from Transaction
                                                      // performs checkout on book and
                                                      // adds checkout details to 
                                                      //patron's vector of transactions
};

#endif

