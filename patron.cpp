#include "patron.h"

Patron::Patron() {}
Patron::~Patron() {}

void Patron::setData(int, string, string) {}   // calls on data validation & sets data
int Patron::getID() {}                                         // returns the ID number
string Patron::getFirstName() {}                             // returns the first name
string Patron::getLastName() {}

bool Patron::setID(int) {}                // checks the ID number and sets if valid
bool Patron::setFirstName(string) {}        // checks the first name and sets if valid
bool Patron::setLastName(string) {}          // checks the last name and sets if valid