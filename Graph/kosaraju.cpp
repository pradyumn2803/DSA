#include <bits/stdc++.h>
using namespace std;

// time complexity=O(N+E)
// space complexity=O(N+E) +O(N) +O(N)

void dfs(int node, stack<int> &st, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!(vis[it]))
        {
            dfs(it, st, adj, vis);
        }
    }
    st.push(node);
}

void rev_dfs(int node, vector<int> tran[], vector<int> &vis)
{
    cout << node << " ";
    vis[node] = 1;
    for (auto iter : tran[node])
    {
        if (!vis[iter])
        {
            rev_dfs(iter, tran, vis);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, adj, vis);
        }
    }

    vector<int> transpose[n];

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!vis[node])
        {
            cout << "SCC: ";
            rev_dfs(node, transpose, vis);
            cout << endl;
        }
    }

    return 0;
}