/*
@File contents: Function and variable declarations of the PatronHistory class

@Purpose: Represents a command to display a patron's transaction 
history consisting of library item checkouts and returns

@Assumptions: The the library's catalogue has been populated with items
and patrons have been registered in the library system.

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code will be used: When the command to create a PatronHistory object is 
read in, the TransFactory will create an a new PatronHistory object, which
the virtual doTransaction method is called upon it. This class holds the 
definition of the doTransaction() which will display the a Patron's 
transaction history
*/
#ifndef PATRONHISTORY_H
#define PATRONHISTORY_H
#include "transaction.h"
#include "patron.h"
using namespace std;


class PatronHistory : public Transaction
{

private:
    int patronID;             // the Patron whose history will be displayed

public:
    PatronHistory();  		 // constructor for class PatronHistory
    virtual ~PatronHistory(); // constructor for PatronHistorym, takes a Patron*
    bool setData( istream& );  // setData() method that sets up thePatron* to 
                               // Patron* param
    virtual Transaction* create() const;
    virtual void doTransaction( Storage&, HashMap& ); //displays transaction 
                                                      //history of patron with ID
                                                      //equal to value of data member
                                                      //patronID
};

#endif

