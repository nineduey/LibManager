/*
@File contents: Function definitions of the Transaction class

@Purpose: Transaction class serves as an abstract class for the derived classes
that handle commands being read into the program from the readTransaction()
method of the libraryManager class. The .cpp for this class won't have any
functions defined because it is an abstract class, and only holds virtual
functions, which are defined in their respective derived classes

@Assumptions: Derived classes of the Transaction class are defined.

@Authors: Shushmitha Radjaram and Amanda Todakonzie
*/
//----------------------------------------------------------------------------
#include "transaction.h"

//----------------------------------------------------------------------------
// Default Constructor: Abstract Class, holds no private data members
// @Pre: None
// @Post: None, this is an abstract class, a single Transaction Object cannot
// be instantiated unless its one of its derived classes.
Transaction::Transaction()
{
}

//----------------------------------------------------------------------------
// Destructor:
// @Pre: None
// @Post: Virtual destuctor will be called based on the derived class.
Transaction::~Transaction()
{
}
