#include <bits/stdc++.h>
using namespace std;

/*
            1
           / \
          2   5
         / \ / \
        3  4 6  7
       /
      9

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
int recursive(struct node *n);
bool is_balanced(struct node *n)
{
    return recursive(n) != -1;
}

int recursive(struct node *n)
{

    if (n == NULL)
        return 0;
    int lh = recursive(n->left);
    if (lh == -1)
        return -1;
    int rh = recursive(n->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

int main()
{
    struct node *n = new node(1);
    n->left = new node(2);
    n->right = new node(5);
    n->left->left = new node(3);
    n->left->right = new node(4);
    n->right->left = new node(6);
    n->right->right = new node(7);
    n->left->left->left = new node(9);
    // n->left->left->left->right = new node(2);

    cout << is_balanced(n);
    return 0;
}