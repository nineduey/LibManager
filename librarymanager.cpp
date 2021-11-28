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

			if (itemType_type == 'C' || itemType_type == 'F' || itemType_type == 'P')
			{
				itemType = 'B';
				item = this->facdriver.createItem( itemType, itemType_type );
				inFile.get();
				item->setData( inFile );
			}
			else
			{
				//insert error message
				continue;
			}
	 }
}

//-----------------------------------------------------------------------------
void LibraryManager::readCustomer(istream& inFile) {

}

//-----------------------------------------------------------------------------
void LibraryManager::readTransaction(istream& inFile) {

}
