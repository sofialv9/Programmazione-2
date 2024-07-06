#include <iostream>
using namespace std;

// Le funzioni sono funzioni di template

// Verifica se i valori in input sono puntatori
template<class T> bool compare (const T& left, const T& right)
{
    // constexpr - forza la valutazione dell'espressione (in questo caso l'if) ad essere eseguita a tempo di compilazione e non di esecuzione
    if constexpr (is_pointer<T>::value) // struct che ritorna value = 1 se T è un puntatore
        return *left < *right; // ritorna i puntatori dereferenziati
    else
        return left < right; // ritorna i valori
}

template<class T> void _merge_(T array[], const size_t& begin, const size_t& mid, const size_t& end)
{
    // Si devono allocare 2 array ausiliari: uno per il sottoarray di sinistra, uno per il sottoarray di destra
    size_t leftSize = mid - begin + 1;
    size_t rightSize = end - mid;
    T* leftArray = new T[leftSize];
    T* rightArray = new T[rightSize];

    // Si copiano gli elementi dei sottoarray in input negli array ausiliari
    for(size_t i = 0; i < leftSize; i++)
        leftArray[i] = array[begin + i];

    for(size_t i = 0; i < rightSize; i++)
        rightArray[i] = array[mid + i + 1];

    size_t leftIndex = 0; // indice sottoarray sinistro
    size_t rightIndex = 0; // indice sottoarray destro
    size_t arrayIndex = begin; // indice array finale

    // si scorrono i 2 sottoarray e si confrontano elementi successivi copiando nell'array finale l'elemento minore tra i 2 elementi confrontati. Dopo si aumenta l'indice del sottoarray da cui si è copiato l'elemento e l'indice dell'array finale

    while(leftIndex < leftSize && rightIndex < rightSize) // la condizione ci assicura che il ciclo terminerà quando uno dei 2 sottoarray sarà terminato (quindi se 1 dei sottoarray è più lungo dell'altro i suoi elementi vengono direttamente copiati nell'array finale)
    {
        if(compare(leftArray[leftIndex], rightArray[rightIndex]))// if(leftArray[leftIndex] < rightArray[rightIndex])
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

    // Se ci sono ancora elementi nel sottoarray sinistro
    while(leftIndex < leftSize)
    {
        array[arrayIndex] = leftArray[leftIndex];
        leftIndex++;
        arrayIndex++;
    }

    // Se ci sono ancora elementi nel sottoarray destro
    while(rightIndex < rightSize)
    {
        array[arrayIndex] = rightArray[rightIndex];
        rightIndex++;
        arrayIndex++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template<class T> void _mergesort_(T array[], const size_t& begin, const size_t& end)
{
    if(begin >= end) // se l'array è vuoto o ha un solo elemento
        return;

    size_t mid = begin + (end - begin) / 2; // il begin iniziale è un offset necessario per iniziare dal punto giusto dell'array (dall'inizio del sottoarray analizzato e non dall'inizio del'array complessivo)

    // Ogni chiamata della funzione alloca uno spazio di memoria nello stack
    // L'ordine delle chiamate è leftmost (viene ordinato sempre per primo il sottoarray di sinistra)
    _mergesort_(array, begin, mid); // left
    _mergesort_(array, mid + 1, end); // right
    _merge_(array, begin, mid, end);
}

// La T è un "segnaposto di classe"
template<class T> void mergesort(T array[], const size_t& size)
{
    _mergesort_(array, 0, size - 1); // gli underscore indicano che è una funzione pubblica ma non dovrebbe essere utilizzata dall'utente
}

int main(){
    //double input[] = {new double(5.5), new double(4.3)}; // array di puntatori a double
    double input[] = {5, 8, 2, 1, 4, 0};
    size_t size = sizeof(input) / sizeof(input[0]);
    mergesort(input, size);

    for(size_t i = 0; i < size; i++)
        cout << input[i] << " "; // *input[i] se puntatori
    cout << endl;

    return 0;
}

// Gli algoritmi di ordinamento hanno una proprietà detta stabilità, cioè non alterano l'ordine relativo (iniziale) di elementi uguali rispetto alla relazione d'ordine