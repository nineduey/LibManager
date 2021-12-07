#ifndef PATRONHISTORY_H
#define PATRONHISTORY_H
#include "transaction.h"
#include "patron.h"

class PatronHistory : public Transaction {

private:
    int patronID;                 // the patron whos history is displayed

public:
    PatronHistory();  		 // constructor for class PatronHistory
    ~PatronHistory();        // destrcutor for class PatronHistory
    virtual bool setData(istream&); // virtual set data method
    virtual Transaction* create() const;
    virtual void doTransaction(Storage&, HashMap&);  // calls display on our patron pointer
};

#endif
