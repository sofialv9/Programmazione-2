#include <iostream>
#include "/home/Programmazione 2/File prof/Laboratorio/Lezione3/Lezione3-1-2/book.h"

using namespace std;

/*
* This is ok!
template<class T> bool compare(const T& left, const T& right)
{
  if constexpr (is_pointer<T>::value)
     return *left <= *right;
  return left <= right;
}*/

/*
* This compiles but does not work with built-in datatypes, only for user-defined datatypes.
* You can't change the behavior of operators for build-in datatypes. 
* In any case,  return *left <= *right would result in infinite recursion
* 
template<class T> bool operator<= (const T& left, const T& right)
{   
    if constexpr (is_pointer<T>::value)
        return *left <= *right;
    return left <= right;
}
*/

template<class T> typename std::enable_if<is_pointer<T>::value, int>::type
compare(const T& left, const T& right)
{
  if (*left < *right)
       return -1;
  else if (*left > *right)
      return 1;
  return 0;
}

template<class T> typename std::enable_if<!is_pointer<T>::value, int>::type
compare(const T& left, const T& right)
{
    if (left < right)
        return -1;
    else if (left > right)
        return 1;
    return 0;
}

template<class T> void merge(T array[], const size_t& left,  const size_t& mid, const size_t &right)
{
    size_t const endLeft = mid - left + 1;
    size_t const endRight = right - mid;

    // Temps arrays
    T* leftArray = new T[endLeft];
    T* rightArray = new T[endRight];

    // Copy arrays
    for (int i = 0; i < endLeft; i++)    
        leftArray[i] = array[left + i];
            
    for (int i = 0; i < endRight; i++)    
        rightArray[i] = array[mid + 1 + i];       
    

    size_t startLeft = 0, // Index of first subarray
           startRight = 0; // Index of second subarray
    size_t mergeIndex = left; // Merged array start index

    //Merge in array[left..right]
    while (startLeft < endLeft && startRight < endRight)
    {
        //leftArray[startLeft] <= rightArray[startRight]
        if (compare(leftArray[startLeft], rightArray[startRight]) <=0 )
        {
            array[mergeIndex] = leftArray[startLeft];            
            startLeft++;
        }
        else
        {
            array[mergeIndex] = rightArray[startRight];
            startRight++;
        }
        mergeIndex++;
    }
    // Copy elements of left, if any
    while (startLeft < endLeft)
    {
        array[mergeIndex] = leftArray[startLeft];
        startLeft++;
        mergeIndex++;
    }
    // Copy elements of right, if any
    while (startRight < endRight)
    {
        array[mergeIndex] = rightArray[startRight];
        startRight++;
        mergeIndex++;
    }
    delete[] leftArray;
    delete[] rightArray;
}


template<class T> void recursiveMergeSort(T array[], const size_t& begin, const size_t& end)
{
    if (begin >= end)
        return; 
    size_t mid = begin + (end - begin) / 2;
    recursiveMergeSort(array, begin, mid);
    recursiveMergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

template<class T> void recursiveMergeSort(T arr[],  const size_t& end)
{
    recursiveMergeSort(arr, 0, end - 1);
}

template<class T> void iterativeMergeSort(T arr[],  const size_t& n)
{
    size_t curr_size;  
    size_t left_start;
    // Merge subarrays in bottom up manner.
    for (curr_size = 1; curr_size < n ; curr_size = 2 * curr_size)
    {       
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {            
            size_t mid = min(left_start + curr_size - 1, n - 1);
            size_t right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

int main()
{    
    int arr[] = {80, 12, 11, 13, 5, 6, 7};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);       
    //recursiveMergeSort(arr, arr_size);
    iterativeMergeSort(arr, arr_size);
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
    Book* b1= new Book("A", "B", 1998);
    Book* b2=  new Book("A2", "B2", 1978);
    Book* b3 = new Book("A", "B", 1999);
    Book* arrBook[] = {b1, b2, b3 };
    size_t bookSize = sizeof(arrBook) / sizeof(arrBook[0]);
    recursiveMergeSort(arrBook, bookSize);
    for (int i = 0; i < bookSize; i++)
        cout << *arrBook[i] << "; ";
    cout << endl;
    return 0;
}

