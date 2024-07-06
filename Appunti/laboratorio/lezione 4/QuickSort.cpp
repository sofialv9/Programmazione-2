//QuickSort CON partition

#include <iostream>
using namespace std;

// Ad ogni passata il pivot si trova nella sua posizione finale all'interno dell'array
template<class T> int _partition_(T array[], const int& begin, const int& end)
{
    int pivot = begin; // il pivot è posto uguale al primo indice 
    for(int i = begin; i <= end; i++)
    {
        if(array[i] <= array[end])
        {
            swap(array[i], array[pivot]);
            pivot++; // nel pivot c'è sempre il primo elemento più grande
        }
    }
    return pivot - 1; // il decremento è necessario per escludere il pivot trovato dalla successiva partizione (senza il -1 si ha segmentation fault)
}

template<class T> void _quicksort_(T array[], const int& begin, const int& end)
{
    if(begin >= end)
        return;
    int pivot = _partition_(array, begin, end); // si usa int e non size_t per gestire anche indici negativi (altrimenti si ha stack overflow o si deve controllare che pivot sia minore di end)
    // Dopo ogni partizione l'elemento scelto come pivot si trova nella sua posizione finale, quindi viene escluso nelle successive chiamate
    _quicksort_(array, begin, pivot - 1);
    _quicksort_(array, pivot + 1, end);
}

template<class T> void quicksort(T array[], const int& size)
{
    _quicksort_(array, 0, size - 1);
}

int main()
{
    double input[] = {5, 8, 2, 1, 4, 0};
    int size = sizeof(input) / sizeof(input[0]);
    quicksort(input, size);

    for(size_t i = 0; i < size; i++)
        cout << input[i] << " ";
    cout << endl;

    return 0;
}