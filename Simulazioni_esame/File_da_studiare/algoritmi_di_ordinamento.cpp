// ALGORITMI DI ORDINAMENTO - il tipo di dato considerato è l'intero

#include <iostream>
using namespace std;

// BUBBLE SORT - scorre l'array confrontando elementi successivi e li scambia se il 2° è maggiore del 1°
void bubbleSort(int* array, int size){
    for(int i = 0; i < size; i++){ // da 0 a size
        for(int j = 0; j < size - 1; j++){ // da 0 a size - 1 (l'ultimo elemento sarà già ordinato)
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// BUBBLE SORT CON FLAG - la flag indica se sono fatti scambi, se nella passata precedente all'attuale non ne sono stati fatti allora l'array è già ordinato e la procedura si interrompe
void bubbleSortOptimized(int* array, int size){
    bool swapped = true; // impostato a true
    for(int i = 0; i < size && swapped; i++){
        swapped = false; // impostato a false
        for(int j = 0; j < size - 1; j++){
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true; // true dopo lo scambio
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// INSERTION SORT - considera il 1° elemento come già ordinato e considera l'arrayay come diviso in 2 parti (ordinata e non)
void insertionSort(int* array, int size){
    for(int i = 1; i < size; i++){
        int toOrder = array[i]; // elemento da ordinare
        int j = i - 1;

        while(j >= 0 && array[j] > toOrder){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = toOrder;
    }
}


// SELECTION SORT - a ogni passata seleziona il minimo e lo pone nella posizione corretta
void selectionSort(int* array, int size){
    for(int i = 0; i < size - 1; i++){
        int posmin = i;
        for(int j = i + 1; j < size; j++){
            if(array[j] < array[posmin]){
                posmin = j;
            }
        }
        int temp = array[i];
        array[i] = array[posmin];
        array[posmin] = temp;
    }
}


// MERGE SORT (procedura merge + mergesort interno + mergesort esterno) - divide l'array in 2 sottoarray da ordinare separatamente)
void _merge_(int* array, int begin, int middle, int end)
{
    size_t leftSize = middle - begin + 1;  // !!!
    size_t rightSize = end - middle;       // !!!
    int* leftArray = new T[leftSize];
    int* rightArray = new T[rightSize];

    for(size_t i = 0; i < leftSize; i++)  // !!!
        leftArray[i] = array[begin + i];  // !!!

    for(size_t i = 0; i < rightSize; i++)
        rightArray[i] = array[middle + i + 1]; // !!!

    size_t leftIndex = 0; 
    size_t rightIndex = 0;
    size_t arrayIndex = begin;

    while(leftIndex < leftSize && rightIndex < rightSize)
    {
        if(leftArray[leftIndex] < rightArray[rightIndex])
        {
            array[arrayIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else
        {
            array[arrayIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        arrayIndex++;
    }

    while(leftIndex < leftSize)
    {
        array[arrayIndex] = leftArray[leftIndex];
        leftIndex++;
        arrayIndex++;
    }

    while(rightIndex < rightSize)
    {
        array[arrayIndex] = rightArray[rightIndex];
        rightIndex++;
        arrayIndex++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void _mergesort_(int* array, int begin, int end)
{
    if(begin >= end) // !!!
        return;

    int middle = begin + (end - begin) / 2; 

    _mergesort_(array, begin, middle);
    _mergesort_(array, middle + 1, end);
    _merge_(array, begin, middle, end);
}

void mergesort(int* array, int size)
{
    _mergesort_(array, 0, size - 1);
}


// QUICK SORT - ordina l'array dividendolo in base ad un pivot che ad ogni passata si trova nella sua posizione finale
int _partition_(int* array, int begin, int end)
{
    int pivot = begin;
    for(int i = begin; i <= end; i++)
    {
        if(array[i] <= array[end])
        {
            swap(array[i], array[pivot]);
            pivot++;
        }
    }
    return pivot - 1;
}

void _quicksort_(int array, int begin, int end)
{
    if(begin >= end)
        return;
    int pivot = _partition_(array, begin, end);
    _quicksort_(array, begin, pivot - 1);
    _quicksort_(array, pivot + 1, end);
}

void quicksort(int array, int size)
{
    _quicksort_(array, 0, size - 1);
}
