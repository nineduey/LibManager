#include "factorydriver.h"

FactoryDriver::FactoryDriver()
{
    factoryTypeMap.insert( { 'B', 0 } );

    factories.push_back( new BookFactory );
}

Item* FactoryDriver::create( char itemType, char itemType_type) const
{
    int subscript = factoryTypeMap.at( itemType );
    return factories[subscript]->create( itemType, itemType_type );
}
