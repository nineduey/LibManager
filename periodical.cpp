#include "periodical.h"
#include <iomanip>


//----------------------------------------------------------------------------
// Default Constructor
Periodical::Periodical()
{
	 month = 01;
}

//----------------------------------------------------------------------------
// Destructor
Periodical::~Periodical(){}
<<<<<<< Updated upstream


=======


>>>>>>> Stashed changes
//----------------------------------------------------------------------------
// operator = : Assignment operator, creates deep copy of the Item& anItem
// passed in
// @pre:
//@post:
Item& Periodical::operator=(const Item& item)
{
	 const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	 this->title = aPeriodical.title;
	 this->month = aPeriodical.month;
	 this->year = aPeriodical.year;
}

//----------------------------------------------------------------------------
//operator == : 
//@pre:
//@post:
bool Periodical::operator==(const Item& item)
{
	 const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	 return (this->year == aPeriodical.year && this->month == aPeriodical.month);
}

//----------------------------------------------------------------------------
bool Periodical::operator!=(const Item& item)
{
	 return !operator==(item);
}

//----------------------------------------------------------------------------
bool Periodical::operator<(const Item& item)
{
	 //sorted by date (year, then month), then by title 

	 if (this->operator==(item))
	 {
		  return false;
	 }

	 const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	 if (this->year < aPeriodical.year)
	 {
		  return true;
	 }
	 else if (this->month == aPeriodical.month)
	 {
		  return this->month < aPeriodical.month;
	 }
}


//----------------------------------------------------------------------------
bool Periodical::operator>(const Item& item)
{
	 //sorted by date (year, then month), then by title 

	 if (this->operator==(item) || this->operator<(item))
	 {
		  return false;
	 }

	 const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	 if (this->year > aPeriodical.year)
	 {
		  return true;
	 }
	 else if (this->month == aPeriodical.month)
	 {
		  return this->month > aPeriodical.month;
	 }
}


//----------------------------------------------------------------------------
// create() : method to create new Periodical object
Item* Periodical::create() const {
	 return new aPeriodical;
}
<<<<<<< Updated upstream


//----------------------------------------------------------------------------
void Periodical::setData(istream& infile)
{
	 getline(infile, title, ',');    // input author, looks for comma terminator
	 infile.get();                   // get (and ignore) blank before month
	 infile >> month;						// input month
	 infile.get();                   // get (and ignore) blank before year
	 infile >> year;                 // input year

	 itemType = 'B';     // setting itemType -> Item class
	 numInLib = 5;          // setting numer of Book copies -> Item class
	 bookType = 'P';        // setting bookType -> Book class
}

//----------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Periodical& aPeriodicalBook)
{
	 aPeriodicalBook.print(out);
	 return out;
}

//----------------------------------------------------------------------------
void Periodical::print(ostream& os) const {
	 cout << numInLib << "     " << title << ",     " << month << " " << year;
=======


//----------------------------------------------------------------------------
void Periodical::setData(istream& infile)
{
	 getline(infile, title, ',');    // input author, looks for comma terminator
	 infile.get();                   // get (and ignore) blank before month
	 infile >> month;						// input month
	 infile.get();                   // get (and ignore) blank before year
	 infile >> year;                 // input year

	 itemType = 'B';     // setting itemType -> Item class
	 numInLib = 5;          // setting numer of Book copies -> Item class
	 bookType = 'P';        // setting bookType -> Book class
}

//----------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Periodical& aPeriodicalBook)
{
	 aPeriodicalBook.print(out);
	 return out;
>>>>>>> Stashed changes
}

//----------------------------------------------------------------------------
void Periodical::print(ostream& os) const {
	 cout << numInLib << "     " << title << ",     " << month << " " << year;
}