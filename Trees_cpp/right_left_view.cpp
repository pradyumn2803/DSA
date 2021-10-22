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

void right_view(struct node *n, int level, vector<int> &v)
{
    if (n == NULL)
        return;
    if (level == v.size())
        v.push_back(n->data);
    right_view(n->right, level + 1, v);
    right_view(n->left, level + 1, v);
}

void left_view(struct node *n, int level, vector<int> &v)
{
    if (n == NULL)
        return;
    if (level == v.size())
        v.push_back(n->data);
    left_view(n->left, level + 1, v);
    left_view(n->right, level + 1, v);
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

    vector<int> res, res1;
    right_view(n, 0, res);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    left_view(n, 0, res1);
    for (auto i : res1)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}