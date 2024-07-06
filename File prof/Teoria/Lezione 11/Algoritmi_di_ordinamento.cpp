//  Esempi di implementazione di algoritmi di ordinamento

#include <iostream>
#include <cstring>

using namespace std;

typedef int el;

void print(el array[],size_t n);

void insertionSort(el array[], size_t n);
void selectionSort(el v[], size_t n);
void mergeSort(el v[], size_t n);
void mergeSort(el v[], size_t p, size_t r);
void quickSort(el v[], size_t n);
void quickSort(el v[], size_t p, size_t r);

int main()
{
    el array[] = {10,32,11,34,15};
    size_t n = sizeof(array)/sizeof(array[0]);
    
    cout << "Array iniziale: "; print(array,n);
    //insertionSort(array,n);
    //selectionSort(array,n);
    mergeSort(array, n);
    //quickSort(array,n);
    cout << "Array finale: "; print(array,n);
    
    return 0;
}

void print(el array[],size_t n)
{
    for(size_t i=0; i<n; i++)
        cout << array[i] << " ";
    cout << endl;
}

void scambia (el& a, el& b) // si passano i riferimenti altrimenti lo scambio non avviene (si avrebbe un passaggio per valore)
{
    el appoggio = a;
    a = b;
    b = appoggio;
}

// Considera il 1° elemento come già ordinato e sistema gli elementi ancora da ordinare confrontandoli con quelli già ordinati (si considera l'array come diviso in una parte ordinata e una ancora da ordinare)
void insertionSort(el array[], size_t n)
{
    for (size_t i = 1; i < n; i++)
    {
        el appoggio = array[i];
        size_t j = i - 1;
        while ((array[j] > appoggio) && (j >= 0))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = appoggio;
    }
}

// Considera il 1° elemento come il minimo e scorre il resto dell'array cercando la posizione di un nuovo minimo (= elemento minore del minimo considerato). Infine li scambia.
void selectionSort(el v[], size_t n)
{
    for(int i = 0; i < n - 1; i++)
    {
        size_t posminimo = i;
        for(int j = i + 1; j < n; j++)
        {
            if (v[j] < v[posminimo])
                posminimo = j;
        }
        scambia(v[i], v[posminimo]);
        /*equivale a:
            el temp = v[i];
            v[i] = v[posminimo];
            v[posminimo] = temp;
        */
    }
}

// Vedere il mergeSort degli appunti della lezione 4 di laboratorio, è più semplice di questo
void mergeSort(el v[], size_t n)
{
    // si passano gli indici di inizio e fine
    mergeSort(v, 0, n-1);
}

void merge(el v[], size_t p, size_t q, size_t r)
{
    size_t n = r - p + 1; // numero di element
    el* v2 = new el[n]; // array ausiliario
    
    size_t i = p; // puntatore alla prima metà dell'array
    size_t j = q + 1; // puntatore alla seconda metà
    size_t k = 0; // puntatore all'array ausiliario
    while ((k < n) && (i <= q) && (j <= r))
    {
        // se l'elemento nella prima metà è maggiore
        if (v[i] < v[j])
        {
            v2[k] = v[i];
            i++;
        }
        // se l'elemento della seconda metà è maggiore
        else
        {
            v2[k] = v[j];
            j++;
        }
        k++; // l'incremento dell'indice all'array ausiliario va fatto fuori dall'if
    }
    // se sono rimasti elementi nella prima metà
    while(i <= q)
    {
        v2[k] = v[i];
        i++;
        k++;
    }
    // se sono rimasti elementi nella seconda metà
    while(j <= r)
    {
        v2[k] = v[j];
        j++;
        k++;
    }
            
    // copia gli elementi del'array ausiliario nell'array di partenza (si aggiunge p alla destinazione per ricopiare gli elementi a partire dalla posizione corretta)
    memcpy(v + p, v2, n * sizeof(el));
    delete [] v2;
}

void mergeSort(el v[], size_t p, size_t r)
{
    if (r <= p) // se l'array è vuoto o ha un solo elemento
        return;
    
    size_t q = (p + r) / 2; // punto medio dell'array
    // chiamate ricorsive sulla prima e seconda metà dell'array
    mergeSort(v, p, q);
    mergeSort(v, q + 1, r);
    // unisce i sottoarray (questa procedura è ripetuta per ogni chiamata id mergeSort)
    merge(v,p,q,r);
}

void quickSort(el v[], size_t n)
{
    quickSort(v, 0, n-1);
}

// Versione del quickSort senza la procedura partition che utilizza 2 indici che scorrono l'array
void quickSort(el v[], size_t p, size_t r)
{
    if (r <= p)
        return;
    
    // prende l'ultimo elemento dell'array come pivot
    el pivot = v[r];
    
    // j punta all'inizio dell'array, i alla posizione immediatamente precedente
    size_t i = p - 1;
    size_t j = p;

    // Il ciclo termina quando j = r (cioè quando j raggiungie l'ultimo elemento dell'array)
    while (j < r)
    {
        if (v[j] <= pivot)
        {
            i++;
            scambia(v[i], v[j]);
        }
        j++;
    }
    scambia(v[i+1],v[r]);
    
    quickSort(v,p,i);
    // si chiama su i + 2 e non su i + 1 perché si deve escludere il pivot
    quickSort(v,i+2,r);
}
