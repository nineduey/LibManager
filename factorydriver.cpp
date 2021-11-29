#include "factorydriver.h"

FactoryDriver::FactoryDriver()
{
    factoryTypeMap.insert( { 'B', 0 } );

    factories.push_back( new BookFactory );
}

FactoryDriver::~FactoryDriver()
{
    for (int i = 0; i < factories.size(); i++)
    {
        delete factories[i];
        factories[i] = NULL;
    }
}

Item* FactoryDriver::createItem( char itemType, char itemType_type) const
{
    int subscript = factoryTypeMap.at( itemType );
    return factories[subscript]->createItem( itemType_type );
}
