/*
@File contents: Book.cpp function definitions

@Purpose:

@Assumptions:

@Authors: Shushmitha Radjaram and Amanda Todakonzie

@How code is used:
*/
//-----------------------------------------------------------------------------

#include "book.h"
#include "item.h"
#include "fiction.h"
#include "children.h"
#include "periodical.h"

ostream& operator<<(ostream&, const Book&) {

}

Book::Book() {
	title = "";
	year = 0000;
	bookType = 'b';
}

Book::~Book() {

}

Book::validate() {


}

