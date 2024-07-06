#include "manuscript.h"

// classe derivata da Manuscript
class Periodical : public Manuscript
{
private:
	int frequency;
public:
	Periodical(string author, string title, int frequency) : Manuscript(author, title),  frequency{frequency} {}
	
	int getFrequency() const
	{
		return this->frequency;
	}
	string getLabel() const override
	{
		return Manuscript::getLabel() + "Frequency: " + to_string(this->getFrequency()) + ". ";
	}
	bool operator==(const Periodical& l) const
	{
		return  this->operator==(l) && l.getFrequency() == this->getFrequency();
	}
};
