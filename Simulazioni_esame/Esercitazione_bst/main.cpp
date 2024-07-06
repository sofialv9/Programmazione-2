// Esercitazione sui bst

#include <iostream>
#include <fstream>
#include "bst.h"

using namespace std;

int main()
{
    // apertura file di input
    ifstream file;
    file.open("input.txt", ios::in);
    if (!file.is_open()) { // se il file non si è aperto correttamente
        cout << "Errore file\n";
        return 0; // termina il programma
    }

    // popolamento dell'albero binario di ricerca (BST)
    BST tree;
    while (!file.eof()) {
        size_t pos = 0;
        size_t newpos;
        string line;
        getline(file, line); // legge una riga alla volta
        string token[5]; // conserva i 5 attributi di ogni studente
        for (size_t i = 0; i < 5; i++) {
            // la funzione find() ritorna la prima occorrenza della stringa al 1° membro all'interno della stringa su cui è applicata a partire dall'indice (2° membro). Ritorna npos se non trova nulla.
            newpos = line.find(",", pos);

            // la funzione substr prende in input come 1° membro la posizione iniziale da cui cercare la sottostringa della lunghezza indicata dal 2° membro.
            token[i] = line.substr(pos, newpos - pos);
            if (newpos == string::npos) // se si è arrivati alla fine della riga
                break;
            pos = newpos + 1; // il + 1 serve per saltare la virgola
        }

        Studente stud(stoi(token[0]),token[1],token[2],stof(token[3]));
        //stud.print();    
        //cout << endl;
        tree.Insert(stud);
        //tree.print();
        //cout << endl;
    }

    // ricerca e stampa l'elemento di matricola 1004
    int matr = 1004;
    BSTNode* p = tree.Search(matr); // p puntatore al nodo cercato
    if (p == NULL)
        cout << "Nodo " << matr << " non trovato";
    else
        p->GetData().print();
    cout << endl;

    // stampa dell'intero albero
    tree.print();

    return 0;
}