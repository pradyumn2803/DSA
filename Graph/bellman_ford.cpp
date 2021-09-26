#include <bits/stdc++.h>
using namespace std;

// tiime complexity=O(N-1)XO(E)
// space complexity=O(N)

struct node
{
    int u, v, wt;

    node(int e1, int e2, int w)
    {
        u = e1;
        v = e2;
        wt = w;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;

    vector<int> dist(n, 1000000);
    dist[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto iter : edges)
        {
            if (dist[iter.u] + iter.wt < dist[iter.v])
            {
                dist[iter.v] = dist[iter.u] + iter.wt;
            }
        }
    }

    int f = 1;
    for (auto iter : edges)
    {
        if (dist[iter.u] + iter.wt < dist[iter.v])
        {
            cout << "Negative edges !!" << endl;
            f = 0;
            break;
        }
    }

    if (f)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }

    return 0;
}