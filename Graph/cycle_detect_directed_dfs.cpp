#include <bits/stdc++.h>
using namespace std;

// time complexity=O(N+E)
// space complexity=O(N+E)+O(N)+O(N)

class solution
{
    bool check_cycle(int node, int n, vector<int> adj[], int vis[], int dfsvis[])
    {
        vis[node] = 1;
        dfsvis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (check_cycle(it, n, adj, vis, dfsvis))
                {
                    return true;
                }
            }
            else if (dfsvis[it] == 1)
            {
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }

public:
    bool is_cycle(int n, vector<int> adj[])
    {
        int vis[n + 1], dfsvis[n + 1];
        memset(vis, 0, sizeof(vis));
        memset(dfsvis, 0, sizeof(dfsvis));

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (check_cycle(i, n, adj, vis, dfsvis))
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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (s.is_cycle(n, adj))
    {
        cout << "It contains a cycle" << endl;
    }

    else
    {
        cout << "it doesnot contain a cycle" << endl;
    }
    return 0;
}