#include "factorydriver.h"

FactoryDriver::FactoryDriver()
{
    factoryTypeMap.insert( { 'B', 0 } );

    factories.push_back( new BookFactory );
}

Item* FactoryDriver::createItem( char itemType, char itemType_type) const
{
    int subscript = factoryTypeMap.at( itemType );
    return factories[subscript]->createItem( itemType_type );
}
