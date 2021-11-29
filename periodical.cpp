#include "periodical.h"

Periodical::Periodical()
{
	month = 0;
}

Periodical::~Periodical()
{
}

char Periodical::returnItemType() const
{
	return itemType;
}

char Periodical::returnItemType_Type() const
{
	return bookType;
}

Item& Periodical::operator=( const Item& item )
{
	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	this->title = aPeriodical.title;
	this->month = aPeriodical.month;
	this->year = aPeriodical.year;

	return *this;
}

bool Periodical::operator==( const Item& item ) const
{
	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	return (this->year == aPeriodical.year && this->month == aPeriodical.month);
}

bool Periodical::operator!=( const Item& item ) const
{
	return !operator==(item);
}

bool Periodical::operator<( const Item& item ) const
{
	//sorted by date (year, then month), then by title 
	
	if (this->operator==( item ))
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

	return false;
}

bool Periodical::operator>( const Item& item ) const
{
	//sorted by date (year, then month), then by title 

	if (this->operator==( item ) || this->operator<( item ))
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

	return false;
}

Item* Periodical::create() const
{
	return new Periodical;
}

void Periodical::setData( istream& infile)
{
	getline( infile, title, ',' );     // input author, looks for comma terminator

	infile.get();                     // get (and ignore) blank before month

	infile >> month;

	infile.get();                     // get (and ignore) blank before year

	infile >> year;                   // input year

	//do we set numInLib and maxNumInLib here?

	itemType = 'B';

	bookType = 'P';

	numInLib = 5;

	maxNumInLib = 5;
}

void Periodical::print( ostream& os ) const
{
	cout << numInLib << "     " << title << ",     " << month << " " << year;
}
