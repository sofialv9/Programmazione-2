#include <iostream>

using namespace std;

int main()
{
	//implicit cast
	int i = 65;
	double d = i;		
	cout << fixed << "Casting int to double: " << d << endl; // "fixed" is a floatfield manipulator

	char c = i;
	cout << "Casting int to char: " << c << endl;

	//explicit cast
	int i2 = 75;
	double d2 = double(i2);
	cout << fixed << "Casting int to double: " << d2 << endl;
	cout << fixed << "Casting int to double: " << static_cast<double>(i2) << endl;
	return 0;
}