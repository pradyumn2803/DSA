#include <bits/stdc++.h>
using namespace std;

// time complexity=O(N+E)
// space complexity=O(N+E)+O(N)+O(N)
// big o of n+e is for adj matrix

class solution
{
public:
    void short_dist(int n, vector<int> adj[], int s)
    {
        int distance[n];
        for (int i = 0; i < n; i++)
        {
            distance[i] = INT_MAX;
        }

        distance[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {

            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (distance[node] + 1 < distance[it])
                {
                    distance[it] = distance[node] + 1;
                    q.push(it);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << distance[i] << " ";
        }
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
        adj[v].push_back(u);
    }
    int src;
    cout << "Enter the source :";
    cin >> src;

    s.short_dist(n, adj, src);
    return 0;
}