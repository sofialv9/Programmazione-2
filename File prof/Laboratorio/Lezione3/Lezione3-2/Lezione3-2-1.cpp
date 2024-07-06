#include <iostream>
#include "book.h"
#include "weekly.h"

using namespace std;


int main()
{
	Manuscript m("Manuscript Author", "Manuscript Name");
	cout << m.getAuthor() << endl;
	cout << m.getTitle() << endl;
	cout << m.getLabel() << endl;

	Manuscript m1("Manuscript Author", "Manuscript Name");
	//l'overloading dell'operatore == ritorna 1 se i 2 manoscritti confrontati hanno stesso autore e stesso titolo
	cout << "Comparing m and m1: " << (m == m1) << endl;

	Book b("Tolkien", "Lord of the Rings", 1972);
	cout << b.getAuthor() << endl;
	cout << b.getTitle() << endl;
	cout << b.getYear() << endl;
	cout << b.getLabel() << endl;

	Book b1("Tolkien", "Lord of the Rings", 1972);
	// == ritorna 1 se i 2 libri hanno stesso autore, titolo e anno
	cout << "Comparing b and b1: " << (b == b1) << endl;
	// l'operatore > è definito per la classe Manuscript, ritorna 1 se il titolo del primo libro è maggiore del titolo del secondo (in ordine alfabetico)
	cout << "Comparing b and b1: " << (b > b1) << endl;
	
	Weekly w("Sprea", "Star Wars");
	cout << w.getAuthor() << endl;
	cout << w.getTitle() << endl;
	cout << w.getFrequency() << endl;
	cout << w.getLabel() << endl;
    

// Si può fare solo upcast (cast di un elemento di una classe derivata ad un elemento dela classe base), non downcast (viceversa)
	cout << "Upcast: " << static_cast<Manuscript>(b1).getLabel() << endl;
	//compile error//cout << "Downcast: " << static_cast<Weekly>(m).getLabel() << endl; //unreasonable downcast
	//compile error//Manuscript* nodown= dynamic_cast<Weekly*>(&m); //unreasonable downcast

// Allocazione dinamica di oggetti
	Manuscript* basem = new Book("Tolkien", "Lord of the Rings", 1972);
	Book* yesdown = dynamic_cast<Book*>(basem); //reasonable downcast (il libro è stato allocato come puntatore a Manuscript, quindi può essere castato ad un puntatore a Book)
	if (yesdown != 0)
		cout << "Downcast: " << yesdown->getLabel() << endl;
	
	/* NON FUNZIONA IL DOWNCAST
	Manuscript basem2 = Book("Tolkien", "Lord of the Rings", 1972);
	Manuscript* basem3 = &basem2;
	Book* yesdown2 = dynamic_cast<Book*>(basem3); //reasonable downcast
	if (yesdown2 != 0)
		cout << "Downcast: " << yesdown2->getLabel() << endl;
	*/

	cout << "Manuscript array: " << endl;
	//This calls two times the copy constructor of Manuscript 
	//Manuscript arr[] = {m, m1, b, b1, w};
	//for (Manuscript manu : arr)
	//	cout << manu.getLabel() << endl;
	
	//This calls copy constructor and move constructor of Manuscript
	//Manuscript arr[] = {Book("","",90) };
	//for (Manuscript manu : arr)
	//	cout << manu.getLabel() << endl;

	//This call copy constructor of Manuscript
	//Manuscript* arr = new Manuscript[5]{m,m1,b,b1,w};	
	//for (int i=0; i<5; i++)
	//    cout << arr[i].getLabel() << endl;
	
	Manuscript arr[]{ m, m1, b, b1, w }; // virtual not working, we need pointers!
	for (int i = 0; i < 5; i++)
		cout << arr[i].getLabel() << endl; // usa il metodo getLabel di Manuscript

	Manuscript* arrpt[]{&m, &m1, &b, &b1, &w};
	for (int i = 0; i < 5; i++)
	  cout << arrpt[i]->getLabel() << endl; // thanks to virtual function in Printable, the compiler chooses the "correct" getLabel function (senza i puntatori il binding rimane statico - il puntatore all'oggetto nasconde il puntatore alla virtual table)
	
}