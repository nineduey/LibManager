#include "librarymanager.h"
#include <iostream>
#include <fstream>

//----------------------------------main -------------------------------------
// main(): Opens files with data executes the entire program
// Preconditions: "inventory.txt", "customers.txt", and "transactions.txt"
// must be saved to the same folder main.cpp is saved to
// Postconditions: Program completes execution, output visible on terminal window
int main()
{
	ifstream infile1( "data4books.txt" );
	istream& infile1_istream = infile1;

	LibraryManager libManager;

	if (!infile1)
	{
		cout << "File could not be opened." << endl;
		return 1;
	}
	
	libManager.readInventory( infile1_istream );
	//libManager.readCustomer( infile2 );
	//libManager.readTransactions( infile3 );
}
