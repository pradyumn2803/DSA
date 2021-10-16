#include <bits/stdc++.h>
using namespace std;

/*
                1
              /  \
             3    4
            / \  / \
           6  7 3  2

time complexity--->O(N)
space complexity--->O(N)
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

void zig_zag(struct node *n)
{
    vector<vector<int>> ans;
    if (n == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(n);
    int flag = 0;
    while (!q.empty())
    {
        vector<int> level;
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            struct node *nn = q.front();
            q.pop();
            if (nn->left != NULL)
            {
                q.push(nn->left);
            }
            if (nn->right != NULL)
            {
                q.push(nn->right);
            }
            level.push_back(nn->data);
        }
        if(flag%2!=0){
            reverse(level.begin(),level.end());
        }
        flag++;
        ans.push_back(level);
    }

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
}

int main()
{
    struct node *n = new node(1);
    n->left = new node(3);
    n->right = new node(4);
    n->left->left = new node(6);
    n->left->right = new node(7);
    n->right->left = new node(3);
    n->right->right = new node(2);
    

    zig_zag(n);
    return 0;
}