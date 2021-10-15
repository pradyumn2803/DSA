#include <bits/stdc++.h>
using namespace std;
/*
        -10
        /  \
       9   20
          /  \
         15  7

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

bool same(struct node *n, struct node *p)
{
    if (n == NULL || p == NULL)
        return n == p;
    return (n->data == p->data) && (same(n->left, p->left)) && (same(n->right, p->right));
}

int main()
{
    struct node *n = new node(-10);
    n->left = new node(9);
    n->right = new node(20);
    n->right->left = new node(15);
    n->right->right = new node(7);

    struct node *p = new node(-10);
    p->left = new node(9);
    p->right = new node(20);
    p->right->left = new node(15);
    p->right->right = new node(7);

    bool c = same(n, p);
    if (c)
        cout << "Same" << endl;
    else
        cout << "not Same" << endl;
    return 0;
}