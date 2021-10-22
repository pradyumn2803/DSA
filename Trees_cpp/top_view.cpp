#include <bits/stdc++.h>
using namespace std;
/*

        1
       / \
      2   3
     / \   \
    4  5    7
      /
     6

time complexity-O(N)
space complexity-O(N)
*/
struct node
{
    int data;
    struct node *left;
    struct node *right;

    node()
    {
        data = 0;
        left = right = NULL;
    }

    node(int d)
    {
        data = d;
        left = right = NULL;
    }

    node(int d, node *l, node *r)
    {
        data = d;
        left = l;
        right = r;
    }
};

void top_view(struct node *n)
{
    vector<int> ans;
    if (n == NULL)
        return;
    queue<pair<node *, int>> q;
    map<int, int> m;
    q.push({n, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        node *node = it.first;
        int line = it.second;
        if (m.find(line) == m.end())
            m[line] = node->data;

        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }

        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    struct node *n = new node(1);
    n->left = new node(2);
    n->right = new node(3);
    n->left->left = new node(4);
    n->left->right = new node(5);
    n->right->right = new node(7);
    n->left->right->left = new node(6);

    top_view(n);
    return 0;
}