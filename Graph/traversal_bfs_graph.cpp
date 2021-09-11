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

    public:
        vector<int> search(int v, vector<int> adj[])
        {
            vector<int> bfs;
            vector<int> vis(v + 1, 0);

            for (int i = 1; i <= v; i++)
            {
                if (!vis[i])
                {
                    queue<int> q;
                    q.push(i);
                    vis[i] = 1;

                    while (!q.empty())
                    {
                        int node = q.front();
                        q.pop();
                        bfs.push_back(node);

                        for (auto it : adj[node])
                        {
                            if (!vis[it])
                            {
                                q.push(it);
                                vis[it]=1;
                            }
                        }
                    }
                }
            }
            return bfs;
        }
};

int main()
{
    int m, n;
    cin >> m >> n;
    solution s;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> a;

    a = s.search(n,adj);

    for(auto i: a){
        cout<<i<<" ";
    }
    return 0;
}