#include <iostream>
using namespace std;
int main()
{
    int m, n, i; // n are the number of nodes and m are the edges(in this case number of lines)
    cin >> m >> n;

    //declaring adjacency matrix of size n+1 since counting of matrix starts from 0
    int adj[n + 1][n + 1];

    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // if it is an undirected graph
    }

    return 0;
}