/*@File Contents : Function definitions of the HashMap class
* @Description : This Class is designed to
* handle the methods of reading a datafile containing all Patron
* information, and building the database of Patron objects via a
* hashing algorithm.
* @Assumptions: the datafiles being passed in
* are correctly formatted for this program to build the Patron Hashmap
* @Authors : Amanda Todakonzie and Shushmitha Radjaram
*/
#include "hashmap.h"

HashMap::HashMap(){

	for(int i = 0; i < BUCKETS; i++){
		patronsArray[i] = nullptr;
	}
}

HashMap::~HashMap(){

	for(int i = 0; i < BUCKETS; i++){
		delete patronsArray[i];
		patronsArray[i] = nullptr;
	}
}

//-------------------------------------------------------------------
//addPatron(): this method will take variables containing new 
//customer information, it will create a new Patron object and add it 
//to the HashMap object
//@pre: must be passed an int for the ID number, and two strings 
//containing the first and last name of the customer
//@post: new Patron object will be created using params passed in, a 
//call to function hashify once the Patron object has been created, 
//which will encode the Patron object and place it within the HashMap
bool HashMap::addPatron( int patronID, istream& inFile ){

	Patron* patronToAdd = new Patron();

	if(patronToAdd->setData( patronID, inFile )){

		int indexToInsertIn = hashify( patronID );

		//ensure that a duplicate patron does not exist in patronsArray before insertion
		if (patronsArray[indexToInsertIn] != nullptr){

			if (!(patronsArray[indexToInsertIn]->patronID == patronID)){
				patronsArray[indexToInsertIn] = patronToAdd;
				return true;
			}
			else{
				cout << "ERROR: Patron with ID " << patronToAdd->patronID << 
					" already exists in the system." << endl;
			}
		}
		else{
			patronsArray[indexToInsertIn] = patronToAdd;
			return true;
		}
	}

	delete patronToAdd;
	patronToAdd = nullptr;
	return false;
}

//-------------------------------------------------------------------
//deletePatron(): deletes a Patron from the HashMap
//@pre: must be passed a Patron object param, this method will search 
//for the Patron within the HashMap that matches the object passed in
//@post: the Patron object will be deleted from the HashMap, but only 
//a shallow deletion. Records of past Patrons will be kept in a local 
//file for business record keeping purposes.
void HashMap::deletePatron( Patron* patron){

	if(patron != nullptr){
		patronsArray[hashify( patron->getPatronID())] = nullptr;
	}
	else{
		cout << "Patron is not logged in the library's system." << endl;
	}
}

//-------------------------------------------------------------------
//getPatron(): returns the Patron associated with passed id param
//@pre: Called on a HashMap object.
//@post: if Patron is found, returns pointer to that Patron. If not  
//found, nullptr is returned. This HashMap is unchanged.
Patron* HashMap::getPatron( int patronID ) const{

	return patronsArray[hashify( patronID )];
}

//-------------------------------------------------------------------
//getAllPatrons(): returns pointer to array of all patrons
//@pre: Called on a HashMap object
//@post: Returns a pointer to an array of all stored patrons. This   
//Hashmap is unchanged.
Patron* HashMap::getAllPatrons() const{

	return *patronsArray;
}

//-------------------------------------------------------------------
//operator<<: displays data of patrons stored in the patronsArray
//@pre: the print() function of the HashMap class functions correctly 
//@post: The print function of this class is called on by the 
//reference to the HashMap object passed. The ID, firstnames and 
//lastNames of the patrons stored in the patronsArray are displayed.
ostream& operator<<( ostream& out, const HashMap& h ){
	
	h.print( out );
	return out;
}

//----------------------------------------------------------------------------
//print(): sends patron data stored in the patronsArray to a ostream object 
//reference. This function will be called by the overloaded operator<< to 
//display patrons' data
//@pre: Patron objects are is intialized with valid ID, firstName, and lastName
//@post: reference to ostream object 'out' will contain a formatted line of the 
//containing the each patron's ID, firstName, and lastName
void HashMap::print( ostream& out ) const{
	
	for(int i = 0; i < BUCKETS; i++){

		if(patronsArray[i] != nullptr){

			patronsArray[i]->print( out );
			out << endl;
		}
	}
}

//-------------------------------------------------------------------
//hashify(): creates hash code for passed id number
//@pre: Called on a HashMap object, int passed must be a valid key (ID 
// number in this case)
//@post: returns the index that this key will be associated with. If 
//matching key is in array, returns index of that key. This HashMap 
//is unchanged.
int HashMap::hashify( int patronID) const{

	int h1 = patronID % BUCKETS;
	int h2 = 11 - (patronID % 11);

	int indexInHashMap = h1;
	int i = 0;

	while ((patronsArray[indexInHashMap] != nullptr) 
		&& (patronsArray[indexInHashMap]->getPatronID() != patronID)){
		i++;
		if(i > 0){
			indexInHashMap += ( i * h2);
		}
	}

	return indexInHashMap;
}
