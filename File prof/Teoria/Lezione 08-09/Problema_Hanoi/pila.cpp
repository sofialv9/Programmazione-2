// Questo file non va incluso nel linker (ad es. nella chiamata a g++) in quanto le funzioni template sono rislte dal compilatore

template <typename T>
void Pila<T>::stampa()
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}