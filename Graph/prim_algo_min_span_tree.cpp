#include <bits/stdc++.h>
using namespace std;

// time complexity =O(NlogN)
// space complexity = O(N)+O(N)+O(N)+O(N)+O(N+E)

class solution
{
public:
    void prim(int n, vector<pair<int, int>> adj[])
    {
        int parent[n + 1], mst[n + 1], key[n + 1];
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            mst[i] = false;
            key[i] = INT_MAX;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[0] = 0;
        parent[0] = -1;
        pq.push({0, 0});

        for (int i = 0; i < n - 1; i++)
        {
            int u = pq.top().second;
            pq.pop();

            mst[u] = true;
            for (auto i : adj[u])
            {
                int wt = i.second;
                int v = i.first;
                if (key[v] > wt && mst[v] == false)
                {
                    parent[v] = u;
                    key[v] = wt;
                    pq.push({key[v], v});
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            cout << parent[i] << "-"<<i<<endl;
        }
    }
};

int main()
{
    solution s;

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];

    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    s.prim(n, adj);
    return 0;
}