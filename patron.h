//-------------------------------------------------------------------
/*@File Contents: Patron Class Header
*@Description: Represents a customer of the SHHH library system. Stored within is the customers first name, last name, and a unique ID number. Also stored is that customer’s transaction history.
*@Authors: Monica King, Amanda Todakonzie, Brennan Richards,      *Shushmitha Radjaram, Phuong K Vu
*/

#ifndef PATRON_H
#define PATRON_H
#include <iostream>
#include <string>
using namespace std;

class Patron
{

public:

	//constructor, creates empty Patron object
	Patron();

	//------------------------------------------------------------------
	//destructor, this method will export the record of this Patron to a data file before it deletes the data members of the Patron object and empty and erase the the Transaction objects that are stored in the custHistory vector
	~Patron();

	//public methods
	//------------------------------------------------------------------
	//setData(): sets all data members in Patron object
	//@pre: Called on a Patron object. Int passed must be 4 digits long  // and strings passed must be valid
	//@post: Modifies customerID, firstName, lastName to passed variables // if valid
	void setData( int patronID, istream& );

	//------------------------------------------------------------------
	//addToHistory(): method to add Transaction objects to a Patron’s  //Transaction history vector
	//@pre: Called on a Patron object. Transaction passed should only be // of type Checkout or Return
	//@post: Modified history vector, adding the passed Transaction.
	//void addToHistory( Transaction* );

	//------------------------------------------------------------------
	//getHistory(): method to retrieve transaction history of a certain //patron. Returns pointer to 1st element of transaction history //vector
	//@pre: Called on a Patron object
	//@post: returns a pointer to an array of Transactions representing  // this patrons transaction history, this is unchanged
	//Transaction* getHistory() const;

	//------------------------------------------------------------------
	//getID(): method to retrieve ID number for a certain Patron,        // returns the ID number 
	//@pre: Called on a Patron object
	//@post: returns customerID, this is unchanged
	int getID() const;

	//------------------------------------------------------------------
	//getFirstName(): method to retrieve first name for a certain Patron
	//@pre: Called on a Patron object
	//@post: returns firstName, this is unchanged
	string getFirstName() const;

	//------------------------------------------------------------------
	//getLastName(): method to retrieve last name for a certain Patron
	//@pre: Called on a Patron object
	//@post: returns lastName, this is unchanged
	string getLastName() const;

private:

	int patronID;        // the ID number for the Patron
	string firstName;      // Patron's first name
	string lastName;       // Patrons last name

	//private vector holding Patron’s transaction history
	//vector<Transaction*> history;

	//private methods
	//------------------------------------------------------------------
	//setID(): checks the ID number and sets if valid
	//@pre: called on a Patron object
	//@post: if valid, customerID is set to passed int
	//bool setID( int );

	//------------------------------------------------------------------
	//setFirstName(): checks the first name and sets if valid
	//@pre: called on a Patron object
	//@post: if valid, firstName is set to passed string
	//bool setFirstName( string );

	//------------------------------------------------------------------
	//setLastName(): checks the last name and sets if valid
	//@pre: called on a Patron object
	//@post: if valid, lastName is set to passed string
	//bool setLastName( string );
};

#endif

