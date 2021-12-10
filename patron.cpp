#include "patron.h"


Patron::Patron(){

	lastName = "";
	firstName = "";
}

Patron::~Patron(){

	int i;
	for (i = 0; i < patronHistory.size(); i++){
		patronHistory[i].first = nullptr;
	}
}

bool Patron::setData( int patronID, istream& inFile){
	
	if (patronID < 1000 || patronID > 9999){
		cout << "ERROR: Patron ID " << patronID << " is not valid." << endl;
		this->patronID = -1;
		return false;
	}
	this->patronID = patronID;

	inFile.get();
	getline( inFile, this->lastName, ' ' );
	if(lastName.size() < 1){
		cout << "ERROR: Patron's Last Name is not given." << endl;
		return false;
	}

	inFile >> this->firstName;
	if(firstName.size() < 1){
		cout << "ERROR: Patron's First Name is not given." << endl;
		return false;
	}

	return true;
}

void Patron::addToHistory( Item* item, string transType){

	patronHistory.push_back( make_pair(item,transType) );
}

vector<pair<Item*, string>> Patron::getHistory() const{
	
	return patronHistory;
}

void Patron::print( ostream& out ) const{

	out << patronID << "   " << lastName << ",  " << firstName;
}

void Patron::printHistory( vector<pair<Item*, string>> historyVec ) const{
	
	for(int i = 0; i < historyVec.size(); i++){

		cout << historyVec[i].second << "   ";
		cout << *historyVec[i].first << endl;
	} 
}

void Patron::setPatronID( int patronID ){

	this->patronID = patronID;
}

int Patron::getPatronID(){

	return this->patronID;
}

ostream& operator<<( ostream& out, const Patron& p){

	p.print( out );
	return out;
}
