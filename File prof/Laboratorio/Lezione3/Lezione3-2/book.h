#include "manuscript.h"

// classe derivata da Manuscript
class Book : public Manuscript
{
private:
	int year;
public:
	Book(string author, string title, int year) : Manuscript(author, title), year{ year } {}

	int getYear() const
	{ 
		return this->year;
	}

	void setYear(int year)
	{
		this->year = year;
	}

	string getLabel() const
	{
		return Manuscript::getLabel() + "Year: " + to_string(this->getYear())+". ";
	}

	// utilizza l'operatore == di Manuscript per confrontare autore e titolo
	bool operator==(const Book& l) const
	{
		return  Manuscript::operator==(l) && l.year==this->getYear();
	}

};
