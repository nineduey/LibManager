#include "periodical.h"

Periodical::Periodical()
{
}

Periodical::~Periodical()
{
}

Item& Periodical::operator=( const Item& item )
{
	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	this->title = aPeriodical.title;
	this->month = aPeriodical.month;
	this->year = aPeriodical.year;
}

bool Periodical::operator==( const Item& item )
{
	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	return (this->year == aPeriodical.year && this->month == aPeriodical.month)
}

bool Periodical::operator!=( const Item& item )
{
	return !operator==(item);
}

bool Periodical::operator<( const Item& item )
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
}

bool Periodical::operator>( const Item& item )
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

	itemType = 'Book';

	bookType = 'P';

	numInLib = 5;

	maxNumInLib = 5;
}

ostream& operator<<( ostream& out, const Item& item )
{
	const Periodical& aPeriodical = static_cast<const Periodical&>(item);

	out << aPeriodical.month << setw( aPeriodical.MONTH_SPACE_LENGTH )
		<< aPeriodical.year << setw( aPeriodical.YEAR_SPACE_LENGTH ) << aPeriodical.title;

	return out;
}
