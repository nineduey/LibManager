/*
@File contents: Function and variable declarations
of the DisplayCatalogue class

@Purpose:

@Assumptions

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
#ifndef DISPLAYCATALOGUE_H
#define DISPLAYCATALOGUE_H
#include "transaction.h"
#include <string>

class DisplayCatalogue : public Transaction {

public:

    DisplayCatalogue();    // default constructor
    virtual ~DisplayCatalogue(); // destructor
    virtual Transaction* create() const;
    virtual void setData(istream&); // virtual set data method
    virtual void doTransaction(Storage&, HashMap&); // displays the catalogues data

};

#endif
