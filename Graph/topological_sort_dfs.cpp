#include <bits/stdc++.h>
using namespace std;

//time complexity=O(N+E)
//space complexity=O(N)+O(N)+O(N)
// topological sort is only possible for directed acyclic graph(DAG)
//a topolocial sort means sorting the nodes in a way like if there exists 
// two sets u and v such that u->v then u will always come before v.
//it is not possible for undirected graoh since u->v also means v->u
//it is also not possible for directed cyclic graph since the u->v law violates

class solution
{
    void sort_dfs(int i, vector<int> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[i] = 1;
        for (auto iter : adj[i])
        {
            if (!vis[iter])
            {
                sort_dfs(iter, adj, vis, st);
            }
        }
        st.push(i);
    }

public:
    vector<int> topo_sort(int n, vector<int> adj[])
    {
        vector<int> vis(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                sort_dfs(i, adj, vis, st);
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
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