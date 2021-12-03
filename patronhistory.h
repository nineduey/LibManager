#ifndef PATRONHISTORY_H
#define PATRONHISTORY_H
#include "transaction.h"
#include "patron.h"

class PatronHistory : public Transaction {

private:
    Patron* patron;                 // the patron whos history is displayed

public:
    PatronHistory();  			 // constructor for class PatronHistory
    PatronHistory(Patron*);
    void setData(Patron*);
    void doTransaction();            // calls display on our patron pointer

};

#endif