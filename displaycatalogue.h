/*
@File contents: Function and variable declarations of the DisplayCatalogue

@Purpose: The DisplayCatalogue represents a command to display the catalogue 
that is held within the LibraryManager class. 

@Assumptions: The Base Class of Transaction is defined and 

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: When the command to create a DisplayCatalogue object is 
read in, the TransFactory will create an a new DisplayCatalogue object, which
the virtual doTransaction method is called upon it. This class holds the 
definition of the doTransaction() which will display the entire library's 
catalogue contents
*/
//----------------------------------------------------------------------------
#ifndef DISPLAYCATALOGUE_H
#define DISPLAYCATALOGUE_H
#include "transaction.h"
#include "item.h"
#include <string>
using namespace std;

class DisplayCatalogue : public Transaction
{

public:

    DisplayCatalogue();    // default constructor
    virtual ~DisplayCatalogue(); // destructor
    virtual Transaction* create() const; // virtual create method
    virtual bool setData( istream& ); // virtual set data method
    virtual void doTransaction( Storage&, HashMap& ); // displays the catalogue

};
#endif

