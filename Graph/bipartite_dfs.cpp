#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class solution
{
    bool check_bipartite(int i, vector<int> adj[], int colour[])
    {
        if (colour[i] == -1)
        {
            colour[i] = 1;
        }
        for (auto iter : adj[i])
        {
            if (colour[iter] == -1)
            {
                colour[iter] = 1 - colour[iter];
                if (!check_bipartite(iter, adj, colour))
                {
                    return false;
                }
                else if (colour[iter] == colour[i])
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
        int colour[n + 1];
        memset(colour, -1, sizeof(colour));
        for (int i = 1; i <= n; i++)
        {
            if (!check_bipartite(i, adj, colour))
            {
                return false;
            }
        }
        return true;
    }
};

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