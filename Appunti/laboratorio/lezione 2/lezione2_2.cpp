#include <iostream>
using namespace std;

int main()
{
    int size = 3;
    int x[size] = {4, 5, 6};

    int *y = new int[size];
    for(int i = 0; i < size; i++)
        y[i] = i + 4;

    return 0;
}