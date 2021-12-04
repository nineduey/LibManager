#ifndef PATRONHISTORY_H
#define PATRONHISTORY_H
#include "transaction.h"
#include "patron.h"

class PatronHistory : public Transaction {

private:
    Patron* thePatron;                 // the patron whos history is displayed

public:
    PatronHistory();  		 // constructor for class PatronHistory
    PatronHistory(Patron*); // constructor for PatronHistorym, takes a Patron*
    void setData(Patron*);  // setData() method that sets up thePatron* to Patron* param
    void doTransaction(Storage*&, HashMap*&);  // calls display on our patron pointer
};

#endif
