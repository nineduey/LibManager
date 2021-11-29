#include "storage.h"

Storage::Storage()
{
}

Storage::~Storage()
{
	//makeEmpty();
}

void Storage::makeEmpty()
{
	//for (auto i : binTreeMap)
	//{
	//	i.second->~BinTree();
	//	binTreeMap.erase(i.first);
	//}

	////do we need this?
	//binTreeMap.clear();
}

//insert book
//we need to get the bookType and itemType as the key for the map!
void Storage::append( Item* item)
{
	BinTree* toRetrieve;
	char key[2] = {};
	key[0] = item->returnItemType();
	key[1] = item->returnItemType_Type();

	if(!(retrieveBinTree( item, toRetrieve)))
	{
		BinTree* binTree = new BinTree();
		binTree->insert( item );
		binTreeMap.insert( { key, binTree } );
		/*binTreeMap.at( key )->retrieve( item )->print();
		cout << endl;*/
	}
	else //the appropriate bintree exists in the binTreeMap
	{
		binTreeMap.at( key )->insert( item );
	}
}

//add function to create bintree and returns pointer to that bintree root
bool Storage::retrieveBinTree( Item* item, BinTree*& retriever) const
{
	char key[2] = {};
	key[0] = item->returnItemType();
	key[1] = item->returnItemType_Type();

	if (!(binTreeMap.find( key ) == binTreeMap.end()))
	{
		retriever = (binTreeMap.at( key ));
		return true;
	}
	else
	{
		retriever = nullptr;
		return false;
	}

}

bool Storage::retrieveItem( Item* item, Item*& retriever) const
{
	char key[2] = {};
	key[0] = item->returnItemType();
	key[1] = item->returnItemType_Type();

	if(!(binTreeMap.find( key ) == binTreeMap.end()))
	{
		retriever = (binTreeMap.at( key ))->retrieve( item );
		return true;
	}
	else
	{
		retriever = nullptr;
		return false;
	}
}

void Storage::display()
{
	for (auto i : binTreeMap)
	{
		cout << i.first << "   " << i.second
			<< endl;
	}
		
}




