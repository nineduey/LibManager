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
    bool setData( istream& );  // setData() method that sets up thePatron* to Patron* param
    virtual Transaction* create() const;
    virtual void doTransaction( Storage&, HashMap& );  // calls display on our patron pointer
};

#endif

