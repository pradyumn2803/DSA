#include <bits/stdc++.h>
using namespace std;

// time complexity =O(N+E)
// space complexity is O(N)

class solution
{
public:
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, int &timer, vector<int> &vis, vector<int> adj[], vector<int> &is_art)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
            {
                continue;
            }
            if (!vis[it])
            {
                dfs(it, node, tin, low, timer, vis, adj, is_art);
                low[node] = min(low[node], low[it]);
                child++;
                if (low[it] >= tin[node] && parent != -1)
                {
                    is_art[node] = 1;
                }
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (parent == -1 && child > 1)
        {
            is_art[node] = 1;
        }
    }
};

int main()
{
    solution s;
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(n + 1, -1);
    vector<int> low(n + 1, -1);
    vector<int> vis(n + 1, 0);
    vector<int> is_art(n + 1, 0);
    int timer = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            s.dfs(i, -1, tin, low, timer, vis, adj, is_art);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (is_art[i] == 1)
        {
            cout << i << endl;
        }
    }

    return 0;
}