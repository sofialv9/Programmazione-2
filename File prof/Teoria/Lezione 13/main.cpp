#include <iostream>
#include "bst.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    BST<int> bst;
    bst.Insert(7).Insert(4).Insert(3).Insert(10);
    cout << "Il nostro albero contiene gli elementi: " << bst << endl; // operatore << sovraccaricato

    // Si può applicare il metodo getValue alla Search poichè quest'ultima ritorna un puntatore a BSTNode
    cout << "Il nodo con valore 3 ha come puntatore " << bst.Search(3) << " e valore " << bst.Search(3)->GetValue() << endl;

    cout << "Il minimo del nostro albero è " << bst.Min()->GetValue() << endl;
    cout << "Il successore del nodo 3 è " << bst.Next(bst.Search(3))->GetValue() << endl;

    cout << "Cancellazione del nodo 3" << endl;
    bst.Remove(bst.Search(3));
    cout << "Il nostro albero adesso contiene gli elementi: " << bst << endl;
    cout << "Cancellazione del nodo 7" << endl;
    bst.Remove(bst.Search(7));
    cout << "Il nostro albero adesso contiene gli elementi: " << bst << endl;
    return 0;
}
