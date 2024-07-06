// INUTILE

#include <iostream>
#include<string>

using namespace std;

int main()
{
	int number = 10;
	float fnumber = 10.0;
	double dnumber = 10.0000000;
	char ch = 's';
	bool b = true;
	void *v = NULL;
	signed int snumber = -1;
	unsigned int unumber = 1;
	unsigned long int ulnumber = 1;
	unsigned short int usnumber = 1;
	string str = "s";
	cout << "Size of int: " << sizeof(number) << endl;
	cout << "Size of float: " << sizeof(fnumber) << endl;
	cout << "Size of double: " << sizeof(dnumber) << endl;
	cout << "Size of char: "  << sizeof(ch) << endl;
	cout << "Size of bool: "  << sizeof(b) << endl;
	cout << "Size of pointer: " << sizeof(v) << endl;
	cout << "Size of signed number: " << sizeof(snumber) << endl;
	cout << "Size of unsigned number: " << sizeof(unumber) << endl;
	cout << "Size of unsigned long number: " << sizeof(ulnumber) << endl;
	cout << "Size of unsigned short number: " << sizeof(usnumber) << endl;
	cout << "Size of string: " << sizeof(str) << endl;
	cout << "Size of NULL:" << sizeof(NULL) << endl;
	return 0;
}