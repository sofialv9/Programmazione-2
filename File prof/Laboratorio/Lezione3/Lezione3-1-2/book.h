#include <iostream>

/*
  For the sake of simplicity, hearder and implementation are in the same file
*/

using namespace std;

class Book
{
private:
	string author;
	string title;

public:
	 Book(string author, string title) : author{ author }, title{ title } {};
     
	 /*
	 * Default constructor
	 */
	 //Book() : author{ "" }, title{ "" } {}; 
	 Book() = default; //default constructor
	 

	/*
	*   Override the default copy constructor
	*/
	Book(const Book& book) : author{ "Copied " + book.author }, title{ "Copied " + book.title} {}

	/*
	*   Override the default copy constructor
	*/
	Book(Book &&book) : author{ "Move Source Author" + book.author }, title{ "Move Source Title" + book.title }
	{
		book.setAuthor("Move Dest. Author");
		book.setTitle("Move Dest. Title");
	}
	
	/*
	*  Override the default destructor
	*/
	~Book() { cout << "object destructed" << endl; }

	string getAuthor() const
	{
		return this->author;
	}

	string getTitle() const
	{
		return this->title;
	}

	void setAuthor(const string author)
	{
		this->author = author;
	}

	void setTitle(const string title)
	{
		this->title = title;
	}
	
	void print(); // implementato nel main
};



