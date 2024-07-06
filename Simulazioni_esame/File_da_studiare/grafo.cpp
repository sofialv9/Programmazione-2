// GRAFO - array dinamico di liste di adiacenza

#include <iostream>
using namespace std;

class Graph
{
public:
    Graph(int _n) : n(_n) {adj = new List[n];} // alloca un array di n liste
    ~Graph() {delete [] adj;}
    Graph& AddEdge(int u, int v) {adj[u].InsertTail(v); adj[v].InsertTail(u); return *this;}
    int GetN() const {return n;}
    const List& GetAdj(int v) const {return adj[v];}

    void PrintShortestPath(int s, int v);

private:
    enum color_t {white, gray, black};

    void BFS(int s);
    void PrintPath(ostream& os, int s, int v);

    color_t* color;
    int* d;
    int* pred;
    List* adj;
    int n;

};

void Graph::PrintShortestPath(int s, int v)
{
    color = new color_t[n];
    d = new int[n];
    pred = new int[n];

    BFS(s);
    cout << "Il cammino minimo tra " << s << " e " << v << " ha lunghezza " << d[v] << " ed è il seguente: ";
    PrintPath(cout, s, v);
    cout << endl;

    delete [] color;
    delete [] d;
    delete [] pred;
}


void Graph::BFS(int s)
{
    for(int i = 0; i < n; i++)
    {
        color[i] = white;
        d[i] = INT_MAX;
        pred[i] = -1;
    }
    color[s] = gray;
    d[s] = 0;
    Queue q;
    q.Enqueue(s);
    while(!q.IsEmpty())
    {
        int u = q.Dequeue();
        const ListElem* p = adj[u].GetHead();
        while(p != nullptr)
        {
            int v = p->GetNode();
            if(color[v] == white)
            {
                color[v] = gray;
                d[v] = d[u] + 1;
                pred[v] = u;
                q.Enqueue(v);
            }
            p = p->GetNext();
        }
        color[u] = black;
    }
}

// Stampa ricorsiva del cammino tra 2 nodi
void Graph::PrintPath(ostream &os, int s, int v)
{
    if(v == s)
        os << s << " ";
    else if(pred[v] == -1)
        os << "Nessun path da" << s << " a " << v;
    else
    {
        PrintPath(os, s, pred[v]);
        os << v << " ";
    }
}