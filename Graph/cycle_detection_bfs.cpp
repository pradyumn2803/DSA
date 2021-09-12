#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// time complexity is O(N+E)
// where N-no. of nodes,E- travelling through adkacent nodes
// Space complexity is O(N+E)+O(N)+O(N)
// space for adjacency list , queue , vis array

class solution
{
    bool check_cycle(int node, vector<int> adj[], vector<int> &vis)
    {

        queue<pair<int, int>> q;
        vis[node] = true;
        q.push({node, -1});

        while (!q.empty())
        {
            int vis_node = q.front().first;
            int prev = q.front().second;
            q.pop();

            for (auto iter : adj[vis_node])
            {
                if (!vis[iter])
                {
                    vis[iter] = true;
                    q.push({iter, vis_node});
                }
                else if (iter != prev)
                {
                    return true;
                }
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
                if (check_cycle(i, adj, vis))
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