#include <iostream>
#include "shelf.h"
#include "book.h"
#include "weekly.h"

using namespace std;


// La funzione usa l'operatore sovraccaricato << (definito in manuscript.h)
template<class T> void print(T &printable)
{
	cout << printable << endl;
}

int main()
{
	Manuscript m("Manuscript Author", "Manuscript Name");
	Book b1("Tolkien", "Lord of the Rings", 1972);
	Weekly w("Sprea", "Star Wars");	
	// Dichiara un'oggetto di tipo Shelf che può contenere max 3 Manuscript
	Shelf<Manuscript> myshelf(3);
	// la funzione add ritorna 1 se è andata a buon fine
	cout << myshelf.add(&m)<< endl;
	cout << myshelf.add(&b1) << endl;
	cout << myshelf.add(&w) << endl;	

	//funzione definita nel main
    myshelf.print();
	
	// dichiara una Shelf di max 4 interi
	Shelf<int> myNumbershelf(4);
	int val1 = 8;
	int val2 = 6;
	int val3 = 10;
	int val4 = 16;
	cout << myNumbershelf.add(&val1) << endl;
	cout << myNumbershelf.add(&val2) << endl;
	cout << myNumbershelf.add(&val3) << endl;
	cout << myNumbershelf.add(&val4) << endl;	
	myNumbershelf.print(); // usa l'operatore << normalmente

	cout << "Template function print" << endl;
	print(m);
	print<Book>(b1);
	print<Manuscript>(b1); // usa il getLabel di Book (l'override è automatico)
}