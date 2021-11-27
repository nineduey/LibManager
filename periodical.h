#ifndef PERIODICAL_H
#define PERIODICAL_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Periodical : public Book {

protected:
    int month;

public:
    Periodical();
    ~Periodical();
    virtual Item& operator=(const Item&);
    virtual bool operator==(const Item&);
    virtual bool operator!=(const Item&);
    virtual bool operator<(const Item&);
    virtual bool operator>(const Item&);
    virtual Item* create() const { return new Item; }; // need to change this definition
    virtual void setData(istream&); // need to change params
};

#endif