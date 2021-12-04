#include "patron.h"

Patron::Patron(){
	lastName = "";
	firstName = "";
}

Patron::~Patron(){
}

void Patron::setData( int patronID, istream& inFile){
	
	if (patronID < 1000 || patronID > 9999){
		cout << "Patron ID is not valid." << endl;
		this->patronID = -1;
	}

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

//void Patron::addToHistory( Transaction* )
//{
//}

//Transaction* Patron::getHistory() const{
//	return nullptr;
//}

int Patron::getID() const{
	
	return patronID;
}

string Patron::getLastName() const{

	return lastName;
}

string Patron::getFirstName() const{
	
	return firstName;
}

void Patron::print( ostream& out)
{
	out << patronID << "     " << lastName << ",  " << firstName;
}
