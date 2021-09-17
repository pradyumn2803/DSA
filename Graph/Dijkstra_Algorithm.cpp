#include <bits/stdc++.h>
using namespace std;

// time complexity = O(NlogN)
// space complexity = O(N)+O(N)+O(N+E)

class solution
{

public:
    void bfs(int n, int s, vector<pair<int, int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int prev = pq.top().second;
            pq.pop();

            for (auto iter : adj[prev])
            {
                if (dist[prev] + iter.second < dist[iter.first])
                {
                    dist[iter.first] = dist[prev] + iter.second;
                    pq.push({dist[iter.first], iter.first});
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<dist[i]<<" ";
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

    s.bfs(n, 1, adj);

    return 0;
}

