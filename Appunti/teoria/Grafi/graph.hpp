#ifndef graph_hpp
#define graph_hpp

#include <iostream>
using namespace std;

class List;

class ListElem
{
public:
    const ListElem* GetNext() const {return next;};
    int GetNode() const {return node;}

private:
    ListElem(int _node) : node(_node) {}
    int node;
    ListElem* next;

    friend class List; // List può accedere ai membri privati della classe (deve essere definita prima della classe ListElem)
};


class List
{
public:
    List() : head(nullptr), tail(nullptr) {}
    ~List();
    List& InsertHead(int node); // ritorna un riferimento a List per permettere chiamate a cascata
    List& InsertTail(int node);
    int RemoveHead(); // ritorna il valore del nodo rimosso
    const ListElem* GetHead() const {return head;} // metodo costante (= non modifica i dati dell'oggetto) - il const iniziale è necessario in quanto la funzione GetNext è un metodo costante
    bool IsEmpty() const {return (head == nullptr);}

private:
    ListElem* head;
    ListElem* tail;
};

class Queue : private List // ereditarietà privata: un oggetto di tipo Queue non può accedere ai membri di List (nemmeno quelli pubblici)
{
public:
    void Enqueue(int node) {InsertTail(node);}
    int Dequeue() {return RemoveHead();}
    bool IsEmpty() const {return List::IsEmpty();} // richiama la funzione della classe base
};

class Stack : private List
{
public:
    void Push(int node) {InsertHead(node);}
    int Pop() {return RemoveHead();}
    bool IsEmpty() const {return List::IsEmpty();} 
};

// Grafo implementato come array dinamico di liste di adiacenza
class Graph
{
public:
    Graph(int _n) : n(_n) {adj = new List[n];} // alloca un array di n liste
    ~Graph() {delete [] adj;}
    Graph& AddEdge(int u, int v) {adj[u].InsertTail(v); adj[v].InsertTail(u); return *this;} // si aggiunge un arco tra 2 nodi
    int GetN() const {return n;}
    const List& GetAdj(int v) const {return adj[v];}

    void PrintShortestPath(int s, int v);

private:
    enum color_t {white, gray, black}; // ERRORE: non scrivere = per definire una enum

    void BFS(int s); // s = nodo sorgente // visita del grafo
    void PrintPath(ostream& os, int s, int v); // stampa i vertici del cammino minimo tra i vertici s e v

    // i primi 3 servono per la procedura BFS
    color_t* color; // array dinamico
    int* d; // distanza
    int* pred;
    List* adj; // array di liste
    int n;

};

ostream& operator<<(ostream& os, const List& list);
ostream& operator<<(ostream& os, const Graph& graph);

#endif /* graph_hpp */