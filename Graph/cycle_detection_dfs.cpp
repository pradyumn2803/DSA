#include <iostream>
#include <vector>
using namespace std;

// time complexity is O(N+E)
// where N-no. of nodes,E- travelling through adkacent nodes
// Space complexity is O(N+E)+O(N)+O(N) 

class solution
{
    bool check_for_cycle(int node, int prev, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = true;
        for (auto iter : adj[node])
        {
            if (!vis[iter])
            {
                if (check_for_cycle(iter, node, adj, vis))
                {
                    return true;
                }
            }
            else if (iter != prev)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool cycle_detection(int n, vector<int> adj[])
    {
        vector<int> vis(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (check_for_cycle(i, -1, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    solution s;
    int m, n;
    cin >> m >> n;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool c = s.cycle_detection(n, adj);
    if (c)
    {
        cout << "one of the components of the graph has a cycle" << endl;
    }
    else
    {
        cout << "no cycle detected" << endl;
    }
    return 0;
}