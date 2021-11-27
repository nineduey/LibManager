#include "librarymanager.h"


class Book;
class BookFactory;
class TransactionFactory;
class HashMap;


void LibraryManager::readInventory(ifstream& inFile){

    Book* temp;
	 char bookType;
	 string author;
	 string title;
	 int month;
	 int year;


	 while (!inFile.eof()) {

		  inFile >> bookType;
		  inFile.get();
		  if (bookType == 'P') { //if peridical?
				getline(inFile, title, ',');
				inFile >> month;
				inFile >> year;
				temp = bf.createBook(bookType);
				temp->setData(author, month, year);
				

		  }
		  else {
				getline(inFile, author, ',');
				inFile.get();
				getline(inFile, title, ',');
				inFile >> year;
				temp = bf.createBook(bookType);
				temp->setData(author, title, year);
		  }	 	  
	 }
}

void LibraryManager::readCustomer(ifstream& inFile) {

}


void LibraryManager::readTransaction(ifstream& inFile) {

}
