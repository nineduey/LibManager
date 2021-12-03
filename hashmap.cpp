#include "hashmap.h"

HashMap::HashMap(){}

HashMap::~HashMap(){

	int i = 0;
	while(patronsArray[i] != nullptr){
		patronsArray[i] = nullptr;
	}
	delete patronsArray;
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

	patronToAdd->setData( patronID, inFile );

	if(patronID != -1){
		patronsArray[hashify( patronID )] = patronToAdd;
		return true;
	}
	
	return false;
}

void HashMap::deletePatron( Patron* patron){

	if(patron != nullptr){
		patronsArray[hashify( patron->getID() )] = nullptr;
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

	while (patronsArray[indexInHashMap] != nullptr){
		i++;

		if(i > 0){
			indexInHashMap += ( i * h2);
		}
	}

	return indexInHashMap;
}
