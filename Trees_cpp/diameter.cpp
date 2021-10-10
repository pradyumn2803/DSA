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
int height(struct node *n, int &dia);
int diameter(struct node *n)
{
    int dia = 0;
    height(n, dia);
    return dia;
}
int height(struct node *n, int &dia)
{
    if (n == NULL)
        return 0;
    int lh = height(n->left, dia);
    int rh = height(n->right, dia);
    dia = max(lh + rh, dia);
    return 1 + max(lh, rh);
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

    cout << "Diameter of the graph is " << diameter(n) << endl;
    return 0;
}