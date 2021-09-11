#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m, n, i;
    cin >> m >> n;
    // vector<int> adj[n+1]; if weights of the edges are not given
    vector<pair<int, int>> adj[n + 1]; //if weights of the edges are given

    for (i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        //  logic:
        // we create an vector adjacent array and push_back values according the edges each node
        // share with the other.
        // time complexity : O(N+2E)+2E -> E is the number of edges.and their respective weights
        // still better because it is less than n*n.
        // if weights are not there then time complexity is O(N+2E)
        // if no weights are given:
        // adj[u].push_back(v);
        // adj[v].push_back(u);

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // if it is an undirected graph
    }

    return 0;
}