#include "children.h"

//sorted by title, then author

Children::Children()
{
}

Children::~Children()
{
}

Item& Children::operator=( const Item& item)
{
	const Children& aChildren = static_cast<const Children&>(item);

	this->title = aChildren.title;
	this->year = aChildren.year;
	this->author = aChildren.author;
	this->numInLib = aChildren.numInLib;

	return *this;
}

bool Children::operator==( const Item& item)
{
	const Children& aChildren = static_cast<const Children&>(item);

	return (this->title == aChildren.title && this->author == aChildren.author);
}

bool Children::operator!=( const Item& item)
{
	return !this->operator==( item );
}

bool Children::operator<( const Item& item)
{
	if(this->operator==( item ))
	{
		return false;
	}

	const Children& aChildren = static_cast<const Children&>(item);

	if(this->title < aChildren.title)
	{
		return true;
	}
	else if(this->title == aChildren.title)
	{
		return this->author < aChildren.author;
	}
}

bool Children::operator>( const Item& item)
{
	if(this->operator==(item) || this->operator<(item))
	{
		return false;
	}

	const Children& aChildren = static_cast<const Children&>(item);

	if (this->title > aChildren.title)
	{
		return true;
	}
	else if (this->title == aChildren.title)
	{
		return this->author > aChildren.author;
	}
}

Item* Children::create() const
{
	return new Children;
}

void Children::setData( istream& infile)
{
	getline( infile, author, ',');     // input author, looks for comma terminator

	/*infile.get();

	getline( infile, authorLast, ',' );*/

	infile.get();                     // get (and ignore) blank before title

	getline( infile, title, ',' );      // input title

	infile >> year;                   // input year

	//do we set numInLib and maxNumInLib here

	itemType = 'B';

	bookType = 'C';

	numInLib = 5;

	maxNumInLib = 5;
}

ostream& operator<<( ostream& out, const Item& item )
{
	const Children& aChildren = static_cast<const Children&>(item);

	out << aChildren.author << setw( aChildren.AUTHOR_SPACE_LENGTH )
		<< aChildren.title << setw( aChildren.TITLE_SPACE_LENGTH ) << aChildren.year;

	return out;
}

