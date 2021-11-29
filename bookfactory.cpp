#include "bookfactory.h"

BookFactory::BookFactory()
{
	bookFac.push_back( new Children );
	bookFac.push_back( new Fiction );
	bookFac.push_back( new Periodical );

	bookMap.insert( { 'C', 0 } );
	bookMap.insert( { 'F', 1 } );
	bookMap.insert( { 'P', 2 } );
}

BookFactory::~BookFactory()
{
	for (int i = 0; i < bookFac.size(); i++)
	{
		delete bookFac[i];
		bookFac[i] = NULL;
	}
}

Item* BookFactory::createItem( char bookType ) const
{
	if(bookMap.find( bookType ) == bookMap.end())
	{
		return nullptr;
	}
	else
	{
		int subscript = bookMap.at( bookType );
		return bookFac[subscript]->create();
	}
}

