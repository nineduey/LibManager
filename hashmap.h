/*@File Contents : Function and variable declarations of the HashMap 
* class
* @Description : This file contains the function and variable 
* declarations for the HashMap Class.This Class is designed to
* handle the methods of reading a datafile containing all Patron
* information, and building the database of Patron objects via a
* hashing algorithm.
* @Assumptions: the datafiles being passed in
* are correctly formatted for this program to build the Patron Hashmap
* @Authors : Amanda Todakonzie and Shushmitha Radjaram
* 
* @How code will be used: A file containing data on patrons will be used to 
*instantiate a patron and sets its data. The patron will be inserted in the 
* patronsArray data member of this class which will be used to search for
* patrons.
*/
#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include <fstream>
#include "patron.h"
using namespace std;


int const BUCKETS = 11197; //global variable -- size of patrons array,
                           //it is a prime number so it can be used by
                           //the hashify function without issues

class HashMap
{
    //displays data of patrons stored in the patronsArray
    friend ostream& operator<<( ostream&, const HashMap& );

public:

    //default constructor, creates a HashMap object
    HashMap();

    //destructor
    virtual ~HashMap();
    
    //this method will take variables containing new 
    //customer information, it will create a new Patron object and add it 
    //to the HashMap object
    bool addPatron( int, istream&);

    //deletes a Patron from the HashMap
    void deletePatron( Patron* );

    //returns the Patron associated with passed id param
    Patron* getPatron( int ) const;

    //returns pointer to array of all patrons
    Patron* getAllPatrons() const;

    //prints the patronID, firstName, and lastName of all Patrons
    //whos data is stored in the patronsArray
    void print( ostream& ) const;

private:

    Patron* patronsArray[BUCKETS]; // array of size size BUCKETS
                                   // holding pointers to Patron objects

    //uses double hashing to determine index in the patronArray to insert
    //a pointer to patron object into 
    int hashify( int) const;

};

#endif

