#include <bits/stdc++.h>
using namespace std;

//time complexity= O(N+E)+O(N+E)
// space complexity=O(N)+O(N)
// auxillary space complexity=O(N)

class solution
{
    void topo(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                topo(it.first, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    void short_path(int s, int n, vector<pair<int, int>> adj[])
    {
        //finding topo sort using dfs and pushing it in stack to find the shortest path

        stack<int> st;
        // int vis[n];
        // memset(vis,0,sizeof(vis));
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                topo(i, adj, vis, st);
            }
        }

        vector<int>dist(n,INT_MAX);
        dist[s]=0;

        while (!st.empty())
        {
            int node= st.top();
            st.pop();

            if(dist[node]!=INT_MAX){
                for(auto iter: adj[node]){
                    if(dist[iter.first]>dist[node]+iter.second){
                        dist[iter.first]=dist[node]+iter.second;
                    }
                }
            }

        }
        for (int i = 0; i < n; i++)
        {
            if(dist[i]==INT_MAX){
                cout<<"INFINITY"<<" ";
            }
            else{
                cout<<dist[i]<<" ";
            }
        }
           
    }
};

int main()
{
    solution s;
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    s.short_path(0, n, adj);

    return 0;
}