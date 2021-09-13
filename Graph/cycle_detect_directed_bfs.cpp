#include <bits/stdc++.h>
using namespace std;

// time complexity is O(N+E)
// space complexity is O(N)+O(N)+O(N)

class solution
{
public:
    bool is_cycle(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (auto iter : adj[i])
            {
                indegree[iter]++;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> c;
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            c.push_back(node);
            count++;

            for (auto iter : adj[node])
            {
                indegree[iter]--;
                if (indegree[iter] == 0)
                {
                    q.push(iter);
                }
            }
        }
        if (count == n)
        {
            return false;
        }
        return true;
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