#include<iostream>
using namespace std;

// La funzione inline viene eseguita più velocemente poichè trattata come una macro internamente - normalmente ilcodice di una funzione va preso dal codice, inveve con la funzione inline l'intestazione viene sostituita dal corpo della funzione durante la compilazione
// Struttura memoria (dal basso all'alto): codice sorgente, heap, stack.

// Quale riga genera errore?
void esercizio1() {
    int x, y;
    int* const p = &x;
    const int* q = &y;
    q = &x;
    // *q = 4 // questa riga genera errore di compilazione poiché q è un puntatore a costante (quindi non si può modificare il valore a cui punta)
}

// Qual è l'output dei 2 sizeof?
void esercizio2() {
    char str[] = {'T', 'e', 's', 't'};
    char str2[] = "Test";
    cout << sizeof(str) << endl; // 4 (array di 4 caratteri)
    cout << sizeof(str2) << endl; // 5 (stringa di 4 caratteri + carattere nullo)
    cout << str << endl; // c'è un errore di esecuzione poichè la stringa non è terminata da un carattere nullo, quindi la stsmpa continua a leggere in memoria fino a trovarlo
    cout << str2 << endl; // stampa corretta
}

template<typename T>
T max(T a, T b) {
    return (a > b ? a : b) ;
}

// Quale riga genera errore?
void esercizio3() {
    // i :: prima di max sono necessari per indicare che si tratta di una funzione globale e non di una funzione membro (di libreria)
    cout << ::max(2, 5) << endl;
    cout << ::max(2.0, 5.0) << endl;
    //cout << ::max(2, 5.0) << endl; // questa genera errore di compilazione poichè il tipo è ambiguo
    cout << ::max<float>(2, 5.0) << endl;
}

// Qual è l'output di questa funzione?
template<typename T>
void fun(const T& x) {
    int static count = 0;
    cout << "x = " << x << "  count = " << count << endl;
    ++count;
    return;
}

void esercizio4() {
    fun<int>(1); // count = 0
    cout << endl;
    fun<int>(1); // count = 1
    cout << endl;
    fun<double>(1.1); // count = 0 poichè la funzione è stata chiamata con un tipo diverso e quindi la variabile statica count è diversa poichè appartiene ad un'altra "istanza" della funzione
    cout << endl;
    fun<int>(4); // count = 2
    cout << endl;
}

// Qual è l'output di questa funzione?
class Test{
    public:
        // inline static int x = 0; // inline gli dà un valore di default (senza non compila)
        static int x; // la variabile statica viene ereditata dai vari membri della classe
        Test() {}
};

int Test::x = 0; // il valore di default va dato all'esterno e senza il programma non compila

void esercizio5() {
    Test t1;
    Test t2;
    cout << "Prima della modifica" << endl;
    cout << t1.x << endl; // 0
    cout << t2.x << endl; // 0
    t1.x = 5;
    cout << "Dopo la modifica" << endl;
    cout << t1.x << endl; // 5
    cout << t2.x << endl; // 5
}


// Stampa degli elementi di una matrice
void esercizio6() {
    double m[2][3] = {1, 2, 3, 4, 5, 6};
    // Puntatore iniziale della matrice
    cout << m << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            // Prova 1
            //cout << *m[i+j] << endl; // Incorretta poichè mostra l'indirizzo di un elemento della matrice
            // Prova 2
            //cout << *(m + 1)[j] << endl; // Incorretta poichè l'operatore [] ha precedenza sull'operatore *
            // Prova 3
            cout << *(*(m + i) + j) << " ";
            // Prova 4
            // cout << m[i]+j << " " // Incorretta poichè somma un indrizzo di memoria con un intero, perciò mostra l'indirizzo delle locazioni. Per accedere al valore si dovrebbe scrivere *(m[i]+j)

        }
        cout << endl;
    }
}

// Qual è l'output di questa funzione?
class abc {
    void f();
    void g();
    long double x;
};

void esercizio7() {
    cout << sizeof(abc) << endl; // 16
}

template<class T>
class def{
    void esercizio8();
};

template<class T>
void def<T>::esercizio8(){ };
// non void def<T>::esercizio8<T>{ };

// Conta il numero di elementi uguali a 'x' presenti nella lista puntata da 'testa'
int boo(Lista<T>& testa, T& x, int i = 20) {
    Lista<T> q = testa; i = 0;
    while(q != NULL) {
        if(x == q.getValore()) i++;
        q = q->succ;
    }
    return i;
}


int main(int argc, char* argv[]) {
    int x, y;
    //esercizio1();
    //esercizio2();
    //esercizio3();
    //esercizio4();
    //esercizio5();
    //esercizio6();
    esercizio7();
    // l'esercizio 8 è nella classe def
    
    return 0;
}