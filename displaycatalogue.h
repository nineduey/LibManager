#ifndef DISPLAYCATALOGUE_H
#define DISPLAYCATALOGUE_H
#include "transaction.h"
#include <string>

class DisplayCatalogue : public Transaction {

public:

    DisplayCatalogue();    // constructor for class DisplayCatalogue
    void doTransaction();                    	// displays the catalogues data

};

#endif
