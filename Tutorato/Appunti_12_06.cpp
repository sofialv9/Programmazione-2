#include <iostream>
using namespace std;


//L'insieme di dati viene scansionato, ogni coppia di elementi adiacenti viene comparata ed i due elementi vengono invertiti di posizione se sono nell'ordine sbagliato. L'algoritmo deve il suo nome al modo in cui gli elementi vengono ordinati: quelli più piccoli "risalgono" verso un'estremità della lista, mentre quelli più grandi "affondano" verso l'estremità opposta della lista.
void bubbleSort(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// con sentinella - ad ogni passata controlla se è avvenuto uno swap
void bubbleSortOptimised(int* array, int size)
{
    bool swapped = true;
    for(int i = 0; i < size; i++) // finché swapped == true
    {
        for(int j = 0; j < size - 1 && swapped; j++)
        {
            swapped = false;
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
    }
}


int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, size);
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

