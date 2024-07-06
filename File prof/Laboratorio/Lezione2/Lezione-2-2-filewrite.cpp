#include<iostream>
#include<fstream>
#include<string>

using namespace std;

static void writeFile(string filename, string message)
{
	ofstream myfile;
	myfile.open(filename);
	if (myfile.is_open())
	{
		myfile << message;
		myfile.close();
	}
}

static void writeFile(ofstream &myfile, string message)
{	
	if (myfile.is_open())
	{
		myfile << message;
		myfile.close();
	}
}

int main()
{   
	string path = "testo.txt";
	writeFile(path, "Writing this to a file.\n");
	
	ofstream myfile(path); //to append use the parameter ios::app
	writeFile(myfile, "new wonderful message 2");		

	return 0;
}