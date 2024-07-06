// Classe base

#include <iostream>
using namespace std;

class ShortBook
{
private:
	string title;
	string author;
public:
	ShortBook(string title, string author);
	string getTitle() const;
	string getAuthor() const;
};