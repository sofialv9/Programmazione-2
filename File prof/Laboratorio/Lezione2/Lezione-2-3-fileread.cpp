#include<iostream>
#include<fstream>

using namespace std;

static void readByChar(string filename)
{
	ifstream myfile;
	myfile.open(filename);
	if (myfile.is_open())
	{
		char ch;
		while (myfile.get(ch))
		{
			cout << ch << endl;
		}
	  myfile.close();
	}
	
}

static void readBySpace(string filename)
{
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		string text;
		while (myfile)
		{
			myfile >> text;
			cout << text << endl;
		}
		myfile.close();
	}
}


static void readByLine(string filename)
{
	ifstream myfile;
	myfile.open(filename);
	string text;
	if (myfile.is_open())
	{
		while (getline(myfile, text)) //myfile //myfile.good()
		{	
		  cout << text << endl;
		}
	 myfile.close();
	}
	
}



int main()
{	
	string path = "testo.txt";
	cout << "Read char by char" << endl; 
	readByChar(path); // stampa il testo carattere per carattere
	cout << "Read space by space" << endl;
	readBySpace(path); // stampa il testo parola per parola
	cout << "Read line by line" << endl;
	readByLine(path); // stampa il testo riga per riga
  	return 0;
}