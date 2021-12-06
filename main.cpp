#include "librarymanager.h"
#include <iostream>
#include <fstream>

//----------------------------------main -------------------------------------
// main(): Opens files with data executes the entire program
// Preconditions: "inventory.txt", "customers.txt", and "transactions.txt"
// must be saved to the same folder main.cpp is saved to
// Postconditions: Program completes execution, output visible on terminal window
int main(){

	LibraryManager libManager;

	ifstream infile1( "data4books.txt" );

	if (!infile1)
	{
		cout << "File with inventory data could not be opened." << endl;
		return 1;
	}

	istream& infile1_istream = infile1;
	libManager.readInventory( infile1_istream );

	ifstream infile2( "data4patrons.txt" );

	if (!infile2)
	{
		cout << "File with patrons' data could not be opened." << endl;
		return 1;
	}

	istream& infile2_istream = infile2;
	libManager.readPatrons( infile2_istream );

	ifstream infile3( "data4commands.txt" );
	istream& infile3_istream = infile3;

	if (!infile3)
	{
		cout << "File with commands data could not be opened." << endl;
		return 1;
	}

	libManager.readTransactions( infile3_istream );
}
