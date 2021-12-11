/*
@File contents: Function and variable declarations of the Return class

@Purpose: Represents a command to return a previously checked out 
book to the library catalogue.

@Assumptions: The the library's catalogue has been populated with items
and patrons have been registered in the library system.

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code will be used: When the command to create a Return object is 
read in, the TransFactory will create an a new Return object, which
the virtual doTransaction method is called upon it. This class holds the 
definition of the doTransaction() which will return an object to the 
library
*/
#ifndef RETURN_H
#define RETURN_H
#include <string>
#include "transaction.h"
#include "factorydriver.h"
using namespace std;

class Return : public Transaction
{

private:
    Item* theItem;                     // the book that is being returned
    int patronID;             // the Patron that returns the book
    FactoryDriver facDriver;  // factory to create Item objects

public:
    Return();                     // default constructor
    virtual ~Return();            //destructor 
    virtual bool setData( istream& );   //sets data for item and patron involved in 
                                       //the checkout transaction 
    virtual Transaction* create() const;    //creates and return new Checkout object
    virtual void doTransaction( Storage&, HashMap& );  // overridden from Transaction
                                                       // performs return on book and
                                                       // adds return details to 
                                                       //patron's vector of transactions
};

#endif

