/*
@File contents: Function and variable declarations of the TransFactory class

@Purpose: Creates and returns a new Transaction object. Does no work beyond
creation.

@Assumptions: The Transfactory class assumes that a valid character is being
is being passed into the createTransaction() method in order to create a
new Transaction object.

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Un-initialized Transaction object declared in 
LibraryManager is set equal to return value of createItem() function, 
intializing it as a new Transaction object of the indicated Type & Genre.
*/
//----------------------------------------------------------------------------
#ifndef TRANSFACTORY_H
#define TRANSFACTORY_H
#include "transaction.h"
#include "checkout.h"
#include "return.h"
#include "displaycatalogue.h"
#include "patronhistory.h"
#include <unordered_map>
#include <vector>
using namespace std;

class TransFactory
{

public:

	TransFactory(); // default constructor
	virtual ~TransFactory(); // virtual destrcutor
	Transaction* createTransaction(char) const; // create Treansaction method

private:
	//HashMap with keys equal to char variables of every possible book type
	//and values equal to integers ranging from 0  to the number of
	//transaction types - 1.
	unordered_map<char, int> transMap;

	//Vector with elements that are initialized as new
	//Transaction objects of every possible transaction type
	vector<Transaction*> transFac;
};

#endif
