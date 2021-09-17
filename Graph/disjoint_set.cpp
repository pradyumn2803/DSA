#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int r[100000];

// time complexity=O(4a(alpha)) which is constant
// space complexity=O(2N)

void makeset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        r[i] = 0;
    }
}

int findpar(int node)
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = findpar(parent[node]);
}

void union_set(int u, int v)
{
    u = findpar(u);
    v = findpar(v);

    if (r[u] > r[v])
    {
        parent[v] = u;
    }

    else if (r[u] < r[v])
    {
        parent[u] = v;
    }

    else
    {
        parent[u] = v;
        r[v]++;
    }
}

int main()
{
    int n;
    cin >> n;
    makeset(n);

    int m;
    cin >> m;

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        union_set(u, v);
    }

    if (findpar(2) == findpar(3))
    {
        cout << "They belong to the same set" << endl;
    }

    else
    {
        cout << "They donot belong to the same set" << endl;
    }

    return 0;
}