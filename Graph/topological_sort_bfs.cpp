#include <bits/stdc++.h>
using namespace std;

// time complexity=O(N+E)
// space complexity=O(N)+O(N)+O(N)

class solution
{
public:
    vector<int> topo_sort(int n, vector<int> adj[])
    {
        vector<int> indegree(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for (auto iter : adj[i])
            {
                indegree[iter]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
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

    vector<int> topo;
    topo = s.topo_sort(n, adj);

    cout << endl;
    cout << "Sorted :" << endl;
    for (auto iter : topo)
    {
        cout << iter << " ";
    }
    return 0;
}