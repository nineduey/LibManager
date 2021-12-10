@File contents: Function definitions of the Transaction class
@Purpose: Transaction class serves as an abstract class for the derived classes
that handle commands being read into the program from the readTransaction()
method of the libraryManager class. The .cpp for this class won't have any
functions defined because it is an abstract class, and only holds virtual
functions, which are defined in their respective derived classes
@Assumptions:
@Authors: Shushmitha Radjaram and Amanda Todakonzie
*/
#include "transaction.h"

//----------------------------------------------------------------------------
//Default Constructor
Transaction::Transaction()
{
}

//----------------------------------------------------------------------------
//Destructor
Transaction::~Transaction()
{
}
