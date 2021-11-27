#include "librarymanager.h"


class Book;
class BookFactory;
class TransactionFactory;
class HashMap;


void LibraryManager::readInventory(ifstream& inFile){

    	 Book* temp;
	 char bookType;
	
	 while (!inFile.eof()) {
		  inFile >> bookType;
		  temp = bf.createBook(bookType);
		  inFile.get();
		  temp.setData(inFile);
	 }
}

void LibraryManager::readCustomer(ifstream& inFile) {

}


void LibraryManager::readTransaction(ifstream& inFile) {

}
