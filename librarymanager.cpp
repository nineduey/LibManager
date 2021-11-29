/*
@File contents: LibraryManager.cpp function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------

#include "librarymanager.h"

//-----------------------------------------------------------------------------
void LibraryManager::readInventory(istream& inFile){

    Item* item;
	char itemType;
	char itemType_type;
	
	 while (!inFile.eof()) {

		inFile >> itemType_type;

		itemType = 'B';
		item = this->facdriver.createItem( itemType, itemType_type );
		if(item == nullptr)
		{
			continue;
		}
		inFile.get();
		item->setData( inFile );
		//item->display();
		catalogue.append( item );
	 }
}

//-----------------------------------------------------------------------------
void LibraryManager::readCustomer(istream& inFile) {

}

//-----------------------------------------------------------------------------
void LibraryManager::readTransaction(istream& inFile) {

}
