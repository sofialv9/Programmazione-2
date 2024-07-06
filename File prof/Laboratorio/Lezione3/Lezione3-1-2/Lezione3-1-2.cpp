#include <iostream>
#include "book.h"

using namespace std;

void Book::print()
{
	cout << "Title: " << this->getTitle() << "; author: " << this->getAuthor() << endl;
}


int main()
{
	Book b("Tolkien", "Lord of the Rings"); //Book b{ "Tolkien", "Lord of the Rings" };
	cout << b.getAuthor() << endl;
	cout << b.getTitle() << endl;

	b.setAuthor("J.R.R. Tolkien");
	cout << b.getAuthor() << endl;

	Book* b1 = new Book(b.getAuthor(), "The Silmarillion"); // allocazione dinamica di un oggetto
	cout << b1->getTitle() << endl;

	/*
	  Initialization by copy
	*/

	Book b2 = { b };
	Book b3 (b);
	
	b.setTitle("The Lord of the Rings");
	cout << "B title: "<< b.getTitle() << endl;
	cout << "B2 title: " << b2.getTitle() << endl; //copied
	cout << "B2 author: " << b2.getAuthor() << endl; //copied
	cout << "B3 title: " << b3.getTitle() << endl; //copied
    Book b4; //default constructor
	cout << "Default constructor: " << b4.getAuthor() << endl;
	//Book b4(); // error, we are declaring a function called b4 that return an instance of Book.
	//Book b4 = { "Test", "Prova" }; //copy-list-initialization not allowed with explicit constructor
	
	Book b5 {}; //default constructor
	cout << "B5 author: " <<  b5.getAuthor() << endl;
	
//std::move is used to indicate that an object t may be "moved from", i.e. allowing the efficient transfer of resources from t to another object. In particular, std::move produces an xvalue expression that identifies its argument t. A xvalue (an “eXpiring” value) is a glvalue that denotes an object whose resources can be reused.
	Book b6 = move(b5); // b5 = dest. b6 = source
	cout << "B5 author: " << b5.getAuthor() << endl;
	cout << "B6 author: " << b6.getAuthor() << endl;
	
	b6.print();
}