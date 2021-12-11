/*
@File contents: Function and variable declarations of the Patron class

@Purpose: Represents a Patron of the Library who is able to check out
and return library items 

@Assumptions: Each patron will have a valid patronID, firstName and lastName

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code will be used: A file containing data on patrons will be used to 
instantiate a patron and sets its data. The patron will be registered in 
the library administrative system.
*/
#ifndef PATRON_H
#define PATRON_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>  
#include "item.h"
using namespace std;

class Patron
{
	friend class HashMap;
	friend ostream& operator<<( ostream&, const Patron& );//outputs patron data 

public:

	//constructor, creates empty Patron object
	Patron();
	
	// Sets the pointers to item objects that are stored in the patronHistory 
	// vector to nullptr so their memory is freed
	virtual ~Patron();

	//setData(): sets values of all data members in Patron object
	bool setData( int patronID, istream& );

	//addToHistory(): function to add Transaction data to patron's transaction
	//history vector. The item involved in the transaction and a string indicated
	//what type of transaction was performed are the function parameters
	void addToHistory( Item*, string ); 

	//getHistory(): method to retrieve transaction history of a certain 
	//patron. Returns pointer to 1st element of transaction history vector
	vector<pair<Item*, string>> getHistory() const; 

	//checks if patron performed a transaction that is logged in their transaction
	//history vector
	bool transExists(Item*, string);

	//sends patron data to be outputted to a ostream object reference and will
	//be called by the overloaded operator<< to display patron data
	void print( ostream& ) const;

	//prints the details of the transactions performed by the patron in the same
	//order the patron performed them
	void printHistory( vector<pair<Item*, string>> ) const;

	//returns patron's ID 
	int getPatronID(); 

private:

	int patronID;        // the ID number for the Patron
	string firstName;      // Patron's first name
	string lastName;       // Patrons last name

	//private vector holding Patron’s transaction history data
	vector<pair<Item*, string>> patronHistory;
};
#endif

