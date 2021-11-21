
#ifndef HASHMAP_H
#define HASHMAP_H
#include "patron.h"
#include <iostream>
#include <string>
using namespace std;

int const MAX = 100;

class HashMap {
 
public:

    HashMap();                    // Hashmap constructor, creates empty Hashmap

    //public methods
    void readFile(ifstream&);                         // reads patrons from file
    void addPatron(int, string, string);     // adds a new Patron to the HashMap
    void deletePatron(Patron);              // deletes a Patron from the HashMap
    Patron getPatron(int id);    // returns the Patron associated with passed id

 // should we include a way to get every patron? 
 // like returning an array or something

private:

    Patron patronsArray[MAX];                  // an array of Nodes containing Patron

    //private methods
    int hashify(string);               // creates hash code for passed id number
};

#endif