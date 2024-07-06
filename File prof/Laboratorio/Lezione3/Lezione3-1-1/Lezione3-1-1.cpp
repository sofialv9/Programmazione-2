// Esempio di classe e classe derivata con separazione in file .h e file .cpp

#include <iostream>
#include "mybook.h"

using namespace std;


int main()
{
	MyBook m("Fodamenti di Programmazione in C++", "Luis Joyanes Aguilar");
	cout << m.getTitle() << endl;
	cout << m.getAuthor() << endl;
}