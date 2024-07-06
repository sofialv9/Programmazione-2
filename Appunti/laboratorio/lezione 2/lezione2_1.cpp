#include <iostream>
using namespace std;

int main()
{
    double d = 10.5;
    int i = static_cast<int>(d); // cast esplicito - facilmente individuabile
    cout << i << endl;

    int i = 76;
    char c = static_cast<char>(i); // se esiste la codifica di un carattere con i byte corrispondenti a quelli del numero i stampa il carattere
    cout << c << endl;

    // il cast è sempre possibile tra tipi di base (sempre safe)
    // safeness --> il programma compila
    
    return 0;
}