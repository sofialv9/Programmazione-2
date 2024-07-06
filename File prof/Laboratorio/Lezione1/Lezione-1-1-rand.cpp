// ABBASTANZA INUTILE

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	int s = rand() % 100;
	cout << s << endl;
	s = rand() % 25 + 3;
	cout << s << endl;
	s = rand() % 200 - 100;
	cout << s << endl;
	return 0;
}