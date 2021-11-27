#ifndef FICTION_H
#define FICTION_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Fiction : public Book {

protected:
    string authorFirst;
    string authorLast;

public:
    Fiction();
    ~Fiction();
    virtual Item& operator=(const Item&);
    virtual bool operator==(const Item&);
    virtual bool operator!=(const Item&);
    virtual bool operator<(const Item&);
    virtual bool operator>(const Item&);
    virtual Item* create() const { return new Item; };
    virtual void setData(ifstream&);
};

#endif