#include <bits/stdc++.h>
using namespace std;

/*
        1
       / \
      2   3
         / \
        4   6
       /     \
      5       7
     /         \
    9           8

time complexity=O(N)
space complexity=O(N)

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

bool isleaf(struct node *n)
{
    return (!n->left) && (!n->right);
}

void left(struct node *n, vector<int> &v)
{
    struct node *cur = n->left;
    while (cur)
    {
        if (!(isleaf(cur)))
            v.push_back(cur->data);
        if ((cur->left))
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void right(struct node *n, vector<int> &v)
{
    struct node *cur = n->right;
    vector<int> temp;
    while (cur)
    {
        if (!(isleaf(cur)))
            temp.push_back(cur->data);
        if ((cur->right))
            cur = cur->right;
        else
            cur = cur->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        v.push_back(temp[i]);
    }
}

void leaf(struct node *n, vector<int> &v)
{
    if (isleaf(n))
    {
        v.push_back(n->data);
        return;
    }
    if (n->left)
        leaf(n->left, v);
    if (n->right)
        leaf(n->right, v);
}

void boundary_traversal(struct node *n)
{
    vector<int> v;
    if (!n)
        return;
    if (!(isleaf(n)))
        v.push_back(n->data);
    left(n, v);
    leaf(n, v);
    right(n, v);

    for (auto iter : v)
    {
        cout << iter << " ";
    }
    cout << endl;
}

int main()
{
    struct node *n = new node(1);
    n->left = new node(2);
    n->right = new node(3);
    n->right->left = new node(4);
    n->right->left->left = new node(5);
    n->right->left->left->left = new node(9);
    n->right->right = new node(6);
    n->right->right->right = new node(7);
    n->right->right->right->right = new node(8);

    boundary_traversal(n);
    return 0;
}