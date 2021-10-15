#include <bits/stdc++.h>
using namespace std;
/*
        -10
        /  \
       9   20
          /  \
         15  7

time complexity=O(height of tree)
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
int maxpathsum(struct node *n, int &maximum);
int find_max_sum(struct node *n)
{
    int maximum = INT_MIN;
    maxpathsum(n, maximum);
    return maximum;
}
int maxpathsum(struct node *n, int &maximum)
{
    if (n == NULL)
        return 0;
    int left_max = max(0, maxpathsum(n->left, maximum));
    int right_max = max(0, maxpathsum(n->right, maximum));
    maximum = max(left_max + right_max + n->data, maximum);
    return n->data + max(left_max, right_max);
}

int main()
{
    struct node *n = new node(-10);
    n->left = new node(9);
    n->right = new node(20);
    n->right->left = new node(15);
    n->right->right = new node(7);

    int maxi = find_max_sum(n);
    cout << "Maximum path sum is " << maxi << endl;
    return 0;
}