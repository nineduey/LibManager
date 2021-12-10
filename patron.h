//-------------------------------------------------------------------
/*@File Contents: Patron Class Header
*@Description: Represents a customer of the SHHH library system. Stored within is the customers first name, last name, and a unique ID number. Also stored is that customer’s transaction history.
*@Authors: Amanda Todakonzie and Shushmitha Radjaram
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
	friend ostream& operator<<( ostream&, const Patron& );

public:

	//constructor, creates empty Patron object
	Patron();

	//------------------------------------------------------------------
	//destructor, this method will export the record of this Patron to a data file before it deletes the data members of the Patron object and empty and erase the the Transaction objects that are stored in the custHistory vector
	virtual ~Patron();

	//public methods
	//------------------------------------------------------------------
	//setData(): sets all data members in Patron object
	//@pre: Called on a Patron object. Int passed must be 4 digits long  // and strings passed must be valid
	//@post: Modifies customerID, firstName, lastName to passed variables // if valid
	bool setData( int patronID, istream& );

	//------------------------------------------------------------------
	//addToHistory(): method to add Transaction objects to a Patron’s  //Transaction history vector
	//@pre: Called on a Patron object. Transaction passed should only be // of type Checkout or Return
	//@post: Modified history vector, adding the passed Transaction.
	void addToHistory( Item*, string ); 

	//------------------------------------------------------------------
	//getHistory(): method to retrieve transaction history of a certain //patron. Returns pointer to 1st element of transaction history 
	//vector
	//@pre: Called on a Patron object
	//@post: returns a pointer to an array of Transactions representing  // this patrons transaction history, this is unchanged
	vector<pair<Item*, string>> getHistory() const; 

	bool transExists(Item*, string);

	void print( ostream& ) const;

	void printHistory( vector<pair<Item*, string>> ) const;

	void setPatronID( int patronID );

	int getPatronID(); 

private:

	int patronID;        // the ID number for the Patron
	string firstName;      // Patron's first name
	string lastName;       // Patrons last name

	//private vector holding Patron’s transaction history
	vector<pair<Item*, string>> patronHistory;
};
#endif

