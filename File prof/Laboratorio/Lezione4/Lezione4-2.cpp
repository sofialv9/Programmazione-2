#include <bits/stdc++.h>
using namespace std;

template<class T> size_t partition(T arr[], const size_t& low, const size_t& high)
{
    size_t pivotIndex = low;
    for (size_t i = low; i <= high; i++)
    {
        if (arr[i] <= arr[high])
        {
            swap(arr[pivotIndex], arr[i]);
            pivotIndex++;
        }
    }
    return pivotIndex - 1;
}

template<class T> void quickSort(T arr[], const size_t& low, const size_t& high)
{
    if (low >= high)
        return;
    size_t PIndex = partition(arr, low, high);
    if (PIndex > 0) //due to the use of size_t, PIndex cannot be negative
       quickSort(arr, low, PIndex - 1);
    if (PIndex < high)
       quickSort(arr, PIndex + 1, high);
    
}

template<class T> void quickSort(T arr[], const size_t& size)
{
    quickSort(arr, 0, size - 1);
}


int main()
{

    int arr[] = { 32, 10, 7, 4, 8, 59, 9, 1, 5 };
    size_t n = sizeof(arr) / sizeof(arr[0]);
    quickSort<int>(arr, n - 1);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)    
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}