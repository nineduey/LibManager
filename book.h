#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "item.h"
#include <string>
using namespace std;

class Book: public Item {
    friend ostream& operator<<(ostream&, const Book&);

protected:
    string title;
    int year;
    char bookType;

public:
    Book();
    virtual ~Book();
    virtual Item& operator=(const Item&);
    virtual bool operator==(const Item&) const = 0;
    virtual bool operator!=(const Item&) const = 0;
    virtual bool operator<(const Item&) const = 0;
    virtual bool operator>(const Item&) const = 0;
    virtual Item* create() const = 0;
    virtual void setData(string) const = 0; // need to change params

};

#endif
// Override compare opperator in the 3 type so that if they 
// encounter the first equal comparing, then move to the next criteria.
// Check for other override.