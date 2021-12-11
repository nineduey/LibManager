/*
@File contents: Function defintions of the Patron class

@Purpose: Represents a Patron of the Library who is able to check out
and return library items

@Assumptions: -----?

@Authors: Shushmitha Radjaram and Amanda Todakonzie
*/
#include "patron.h"

//----------------------------------------------------------------------------
// Default Constructor
//@pre: None
//@post: A patron object is intiated. function calls by it can be used
// to sets its data, add to its history, and search and display its history 
// and data
Patron::Patron(){

	lastName = "";
	firstName = "";
}

//----------------------------------------------------------------------------
//Destructor, 
// Sets the pointers to item objects that are stored in the patronHistory 
// vector to nullptr so their memory is freed
//@pre: Patron object must be instantiated 
//@post: The pointers to Item object in the patronHistory vector are set to 
// nullptr and their memory is freed
Patron::~Patron(){

	int i;
	for (i = 0; i < patronHistory.size(); i++){
		patronHistory[i].first = nullptr;
	}
}

//------------------------------------------------------------------
//setData(): sets values of all data members in Patron object
//@pre: Called on a Patron object. The file containing patron data
// must be formatted in the same way specified in the assignment
// instructions
//@post: If the line of the file passed in contains valid patron 
// data, the Patron's patronID, lastName, and firstName data values
// are initialized to the data given in the line and function 
//returns true. If not, the function returns false 
bool Patron::setData( int patronID, istream& inFile){
	
	if (patronID < 1000 || patronID > 9999){
		cout << "ERROR: Patron ID " << patronID << " is not valid." << endl;
		this->patronID = -1;
		string invalidLine = "";
		getline( inFile, invalidLine );
		return false;
	}
	this->patronID = patronID;

	inFile.get();
	inFile >> this->lastName;
	if(lastName.size() < 1){
		cout << "ERROR: Patron's Last Name is not given." << endl;
		string invalidLine = "";
		getline( inFile, invalidLine );
		return false;
	}

	getline(inFile, this->firstName);
	if(firstName.size() < 1){
		cout << "ERROR: Patron's First Name is not given." << endl;
		string invalidLine = "";
		getline( inFile, invalidLine );
		return false;
	}

	return true;
}

//----------------------------------------------------------------------------
//addToHistory(): function to add Transaction data to patron's transaction
//history vector. The item involved in the transaction and a string indicated
//what type of transaction was performed are the function parameters
//@pre: Patron object is intialized with valid ID, firstName, and lastName
//@post: An Item object involved in the transaction and a string indicating
//the type of the transaction are added as a pair to the patronHistory vector
void Patron::addToHistory( Item* item, string transType){

	patronHistory.push_back( make_pair(item,transType) );
}

//----------------------------------------------------------------------------
//getHistory(): method to retrieve transaction history of a certain 
//patron. Returns pointer to 1st element of transaction history vector
//@pre: Patron object is intialized with valid ID, firstName, and lastName
//@post: The Patron object's patronHistory vector is returned
vector<pair<Item*, string>> Patron::getHistory() const{
	
	return patronHistory;
}

//----------------------------------------------------------------------------
//checks if patron performed a transaction that is logged in their transaction
//history vector
//@pre: Patron object is intialized with valid ID, firstName, and lastName
//@post: Function returns true if the transaction indicated by the object 
//pointed at by the item pointer and string passed in is in the patron's 
//history. Function returns false if the indicated transaction does not exist 
bool Patron::transExists(Item* item, string transType)
{
	for(int i = 0; i < patronHistory.size(); i++){

		if(patronHistory[i].first == item 
			&& patronHistory[i].second == transType){
			return true;
		}
	}
	return false;
}

//----------------------------------------------------------------------------
//print():sends patron data to be outputted to a ostream object reference 
//and will be called by the overloaded operator<< to display patron data
//@pre: Patron object is intialized with valid ID, firstName, and lastName
//@post: reference to ostream object 'out' will contain a formatted line of the 
//containing the patron's ID, firstName, and lastName
void Patron::print( ostream& out ) const{

	out << patronID << "   " << lastName << ",  " << firstName;
}

//----------------------------------------------------------------------------
//printHistory(): prints the details of the transactions performed by the 
//patron in the same order the patron performed them
//@pre: Patron object is intialized with valid ID, firstName, and lastName
//@post: If the patronHistory vector is empty, the user will be notified.
//If the patronHistory vector contains elements, the type of transaction
//and data of the item of each corresponding transaction will be printed
void Patron::printHistory( vector<pair<Item*, string>> historyVec ) const{
	
	if(historyVec.empty()){
		cout << "Patron has not made any valid transactions." << endl;
		return;
	}

	for(int i = 0; i < historyVec.size(); i++){
		cout << historyVec[i].second << "   ";
		cout << left << *historyVec[i].first << endl;
	} 
}

//----------------------------------------------------------------------------
//getPatronID():returns patron's ID
//@pre: Patron object is intialized with valid ID, firstName, and lastName
//@post:Patron object's ID is returned
int Patron::getPatronID(){

	return this->patronID;
}

//----------------------------------------------------------------------------
//operator<<: outputs patron data 
//@pre: the print() function of the Patron class functions correctly 
//@post: The print function of this class is called on by the reference to the 
//patron object passed in and a patron's ID, firstName and lastName are printed
ostream& operator<<( ostream& out, const Patron& p){

	p.print( out );
	return out;
}
