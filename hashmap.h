/*@File Contents : HashMap Class Header
* @Description : This file contains the function and variable 
* declarations for the HashMap Class.This Class is designed to
* handle the methods of reading a datafile containing all Patron
* information, and building the database of Patron objects via a
* hashmap algorithm.Assumptions include the datafiles being passed in
* are correctly formatted for this program to build the Patron Hashmap
* Authors : Amanda Todakonzie and Shushmitha Radjaram
*/

#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include <fstream>
#include "patron.h"

using namespace std;

// global variable -- size of patrons array
int const BUCKETS = 397;

class HashMap
{

public:

    //default constructor, creates a HashMap object
    HashMap();

    //-------------------------------------------------------------------
    //destructor
    virtual ~HashMap();

    //-------------------------------------------------------------------
    //readFile(): static readFile processes Patron information from a 
    //datafile
    //@pre: variable of type ifstream that contains correctly formatted 
    //.txt file must be passed in
    //@post: processes the .txt file commands based on the first char 
    //data that is read off on the start of each line, returns void
    // - calls TransactionFactory
    //static void readFile( ifstream& );
    
    //-------------------------------------------------------------------
    //addPatron(): this method will take variables containing new 
    //customer information, it will create a new Patron object and add it 
    //to the HashMap object
    //@pre: must be passed an int for the ID number, and two strings 
    //containing the first and last name of the customer
    //@post: new Patron object will be created using params passed in, a 
    //call to function hashify once the Patron object has been created, 
    //which will encode the Patron object and place it within the HashMap
    bool addPatron( int, string, string );

    //-------------------------------------------------------------------
    //deletePatron(): deletes a Patron from the HashMap
    //@pre: must be passed a Patron object param, this method will search 
    //for the Patron within the HashMap that matches the object passed in
    //@post: the Patron object will be deleted from the HashMap, but only 
    //a shallow deletion. Records of past Patrons will be kept in a local 
    //file for business record keeping purposes.
    void deletePatron( Patron* );

    //-------------------------------------------------------------------
    //getPatron(): returns the Patron associated with passed id param
    //@pre: Called on a HashMap object.
    //@post: if Patron is found, returns pointer to that Patron. If not  
    //found, nullptr is returned. This HashMap is unchanged.
    Patron* getPatron( int id ) const;

    //-------------------------------------------------------------------
    //getAllPatrons(): returns pointer to array of all patrons
    //@pre: Called on a HashMap object
    //@post: Returns a pointer to an array of all stored patrons. This   
    //Hashmap is unchanged.
    Patron* getAllPatrons() const;

private:

    Patron* patronsArray[BUCKETS]; // array holding Patron objects of   
                                   // size BUCKETS

  //-------------------------------------------------------------------
  //hashify(): creates hash code for passed id number
  //@pre: Called on a HashMap object, int passed must be a valid key (ID 
  // number in this case)
  //@post: returns the index that this key will be associated with. If 
  //matching key is in array, returns index of that key. This HashMap 
  //is unchanged.
    int hashify( int) const;

};

#endif

