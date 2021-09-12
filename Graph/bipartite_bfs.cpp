#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// time complexity is O(N+E)
// where N-no. of nodes,E- travelling through adkacent nodes
// Space complexity is O(N+E)+O(N)+O(N)
// space for adjacency list , queue , vis array

class solution
{
    bool check_bipartite(int i, vector<int> adj[], int* colour)
    {
        queue<int> q;
        colour[i] = 1;
        q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (colour[it] == -1)
                {
                    colour[it] = 1 - colour[node];
                    q.push(it);
                }
                else if (colour[it] == colour[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool is_bipartite(int n, vector<int> adj[])
    {
        // vector<int> colour(n+1,0);
        int colour[n + 1];
        memset(colour, -1, sizeof(colour));
        for (int i = 1; i <= n; i++)
        {
            if (colour[i] == -1)
            {
                if (!check_bipartite(i, adj, colour))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

using namespace std;
int main()
{
    solution s;
    int m, n;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool c = s.is_bipartite(n, adj);
    if (c)
    {
        cout << "one of the components of the graph is bipartite" << endl;
    }
    else
    {
        cout << "none of the components are bipartite" << endl;
    }
    return 0;
}