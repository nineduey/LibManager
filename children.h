#ifndef CHILDREN_H
#define CHILDREN_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class Children : public Book {
protected:
    string authorFirst;
    string authorLast;

public:
    virtual Children& operator=(const Children&);
    virtual bool operator==(const Children&);
    virtual bool operator!=(const Children&);
    virtual bool operator<(const Children&);
    virtual bool operator>(const Children&);
    virtual Book* create() const { return new Children; };
    virtual void setData(string);
};

#endif