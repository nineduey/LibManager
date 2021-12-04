#ifndef PATRON_H
#define PATRON_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Patron {

    friend ostream& operator<<(ostream&, const BinTree&);

public:
    Patron();                                       // default constructor
    ~Patron();                                      // destructor

    // public methods
    void setData(int, string, string);   // calls on data validation & sets data
    int getID();        // returns the ID number
    string getFirstName();                             // returns the first name
    string getLastName();                               // returns the last name

private:
    vector<Transaction*> transHistory;      // vector of transaction objects
    int customerID;                           // the ID number for the Patron
    string firstName;                                     // Patron's first name
    string lastName;                                        // Patrons last name

    //private methods
    bool setID(int);                // checks the ID number and sets if valid
    bool setFirstName(string);        // checks the first name and sets if valid
    bool setLastName(string);          // checks the last name and sets if valid

};

#endif