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
    virtual Fiction& operator=(const Fiction&);
    virtual bool operator==(const Fiction&);
    virtual bool operator!=(const Fiction&);
    virtual bool operator<(const Fiction&);
    virtual bool operator>(const Fiction&);
    virtual Book* create() const { return new Fiction; };
    virtual void setData(string);
};

#endif