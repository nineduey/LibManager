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

Item* BookFactory::create( char itemType, char bookType ) const
{
	int subscript = bookMap.at( bookType );
	return bookFac[subscript]->createItem();
}

