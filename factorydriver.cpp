/*
@File contents: Function defintions and variable initializations of the 
FactoryDriver class

@Purpose: Calls createItem() function of appropriate derived ItemFactory
class to instantiate an Item object of a specific type

@Assumptions: The ItemFactory class has derived classes that are associated with 
the derived classes of the Item class. The derived classes of ItemFactory are defined.

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used: Determines which derived class of ItemFactory should be used to
instiate an object, based on the indicated type of the object that needs to be
created. Calls createItem() function of the appropriate derived ItemFactory
class to create an Item of the specified type
*/

#include "factorydriver.h"

//----------------------------------------------------------------------------
//FactoryDriver(): Default constructor for FactoryDriver class. 
//The 'factoryTypeMap' map and 'factories' vector are populated. 
//Pre-conditions:None
//Post-conditions: 'factoryTypeMap' map and 'factories' vector are populated.
FactoryDriver::FactoryDriver(){
    
    factoryTypeMap.insert( { 'B', 0 } );
    factories.push_back( new BookFactory );
}

//----------------------------------------------------------------------------
//~FactoryDriver(): Destructor of FactoryDriver class
//Pre-conditions: None
//Post-Conditions: Deletes the ItemFactory objects of 'factories' vector from 
//memory
FactoryDriver::~FactoryDriver(){
    
    for (int i = 0; i < factories.size(); i++){
        delete factories[i];
        factories[i] = nullptr;
    }

//    factories.clear();
}

//----------------------------------------------------------------------------
//createItem(): Instantiates book object to equal Item object of the type 
//associated with the first char variable passed in and the type of this 
//type of Item object, which is associated with the second char variable passed
//in. (For a fiction book, parameters would equal 'B' for Item type Book and 
//'F' for Book type Fiction 
//Pre-conditions: 'factories' vector contains the ItemFactory object that creates 
//Items of the type associated with the first argument. The map 
//contains a key-value pair in which the key is equal to the first argument. 
//Post-conditions: An Item object of the specified type is instantiated. 
Item* FactoryDriver::createItem( char itemType, char itemType_type) const{
    
    int subscript = factoryTypeMap.at( itemType );
    Item* itemCreated = factories[subscript]->createItem( itemType_type );

    if (itemCreated == nullptr){
        
        return nullptr;
    }
    else{

        return itemCreated;
    }
}
