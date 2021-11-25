#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;


// ayyoo







class Book {
    friend ostream& operator<<(ostream&, const Book&);

protected:
    string title;
    int year;
    char bookType;

public:
    Book();
    virtual ~Book();
    void checkOut();
    void checkIn();
    virtual Book& operator=(const Book&);
    virtual bool operator==(const Book&) const = 0;
    virtual bool operator!=(const Book&) const = 0;
    virtual bool operator<(const Book&) const = 0;
    virtual bool operator>(const Book&) const = 0;
    int getNumInLib() const;
    void setNumInLib(int);
    virtual Book* create() const = 0;
    virtual void setData(string) = 0;

private:
    int numInLib;
    int maxNumInLib;
    bool checkContent() const; // may want to consider making this 
                            // protected since we can not access
                            // private function in childeren class?
};

#endif
// Override compare opperator in the 3 type so that if they 
// encounter the first equal comparing, then move to the next criteria.
// Check for other override.