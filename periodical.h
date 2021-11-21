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
    virtual Periodical& operator=(const Periodical&);
    virtual bool operator==(const Periodical&);
    virtual bool operator!=(const Periodical&);
    virtual bool operator<(const Periodical&);
    virtual bool operator>(const Periodical&);
    virtual Book* create() const { return new Periodical; };
    virtual void setData(string);
};

#endif