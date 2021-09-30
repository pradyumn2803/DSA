#include <bits/stdc++.h>
using namespace std;

//space complexity  for in pre post i.e dfs=O(N)
//time complexity  for in pre post i.e dfs=O(N)
//space complexity  for bfs=O(N)
//time complexity  for bfs=O(N)

/*

                1
              /  \
             3    4
            / \  / \
           6  7 3  2

*/

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

vector<vector<int>> levelorder(struct node *n)
{
    vector<vector<int>> ans;
    queue<node *> q;
    if (n == NULL)
    {
        return ans;
    }
    q.push(n);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *nn = q.front();
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
        ans.push_back(level);
    }
    return ans;
}

void inorder(struct node *n)
{
    if (n == NULL)
    {
        return;
    }
    inorder(n->left);
    cout << n->data << " ";
    inorder(n->right);
}

void preorder(struct node *n)
{
    if (n == NULL)
    {
        return;
    }
    cout << n->data << " ";
    preorder(n->left);
    preorder(n->right);
}

void postorder(struct node *n)
{
    if (n == NULL)
    {
        return;
    }
    postorder(n->left);
    postorder(n->right);
    cout << n->data << " ";
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

    inorder(n);
    cout << endl;
    preorder(n);
    cout << endl;
    postorder(n);
    cout << endl;
    vector<vector<int>> d(100);
    d = levelorder(n);

    for (auto it : d)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
    }

    return 0;
}