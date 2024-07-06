// BFS - calcolo del cammino minimo (percorso più breve) tra 2 nodi

#include <iostream>
#include "graph.hpp"
using namespace std;

int main()
{
    int r = 0, s = 1, t = 2, u = 3, v = 4, w = 5, x = 6, y = 7;
    Graph g(8);
    g.AddEdge(r, v).AddEdge(r, s).AddEdge(s, w).AddEdge(w, t).AddEdge(w, x).AddEdge(x, t).AddEdge(x, u).AddEdge(t, u).AddEdge(x, y).AddEdge(y, u);
    cout << g << endl;

    g.PrintShortestPath(s, u);

    return 0;
}