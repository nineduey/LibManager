#include "patron.h"


Patron::Patron(){
	lastName = "";
	firstName = "";
}

Patron::~Patron(){

	for(int i = 0; i < patronHistory.size(); i++){
		//delete patronHistory[i];
		patronHistory[i] = nullptr;
	}

	//patronHistory.clear();
}

void Patron::setData( int patronID, istream& inFile){
	
	if (patronID < 1000 || patronID > 9999){
		cout << "Patron ID is not valid." << endl;
		this->patronID = -1;
	}
	this->patronID = patronID;

	inFile.get();
	getline( inFile, this->lastName, ' ' );
	if(lastName.size() < 1){
		cout << "No value is entered for Patron last name." << endl;
	}

	inFile >> this->firstName;
	if(firstName.size() < 1){
		cout << "No value is entered for Patron first name." << endl;
	}
}

void Patron::addToHistory( Transaction* patronTransac ){

	patronHistory.push_back( patronTransac );
}

vector<Transaction*> Patron::getHistory() const{
	
	return patronHistory;
}

void Patron::print( ostream& out ) const
{
	out << patronID << "   " << lastName << ",  " << firstName;
}

void Patron::setPatronID( int patronID )
{
	this->patronID = patronID;
}

int Patron::getPatronID()
{
	return this->patronID;
}

ostream& operator<<( ostream& out, const Patron& p){

	p.print( out );
	return out;
}
