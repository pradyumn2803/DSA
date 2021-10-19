#include <bits/stdc++.h>
using namespace std;
class DSU
{
private:
    vector<int> parent, size, rank;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size.push_back(1);
            rank.push_back(0);
        }
    }

public:
    int findparent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }

public:
    void unionsize(int m, int n)
    {
        int u = findparent(m);
        int v = findparent(n);

        if (u == v)
        {
            return;
        }
        else if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else if (size[u] > size[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
        else if (size[u] == size[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }

public:
    void unionrank(int m, int n)
    {
        int u = findparent(m);
        int v = findparent(n);

        if (u == v)
        {
            return;
        }
        else if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }
};

int main()
{

    return 0;
}