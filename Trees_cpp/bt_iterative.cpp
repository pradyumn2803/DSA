#include <bits/stdc++.h>
using namespace std;

//space complexity for each traversal techniques = O(N)
//time complexity  for each traversal techniques = O(N)

/*

                1
              /  \
             2    7
            / \   
           3  4  
             / \
            5   6
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

void inorder(struct node *n)
{
    stack<node *> s;
    node *e = n;
    vector<int> v;
    while (1)
    {
        if (e != NULL)
        {
            s.push(e);
            e = e->left;
        }
        else
        {
            if (s.empty() == true)
            {
                break;
            }
            e = s.top();
            s.pop();
            v.push_back(e->data);
            e = e->right;
        }
    }
    for (auto iter : v)
    {
        cout << iter << " ";
    }
}

void preorder(struct node *n)
{
    vector<int> v;
    stack<node *> s;
    if (n == NULL)
        return;
    s.push(n);
    while (!s.empty())
    {
        n = s.top();
        s.pop();
        v.push_back(n->data);
        if (n->right != NULL)
        {
            s.push(n->right);
        }
        if (n->left != NULL)
        {
            s.push(n->left);
        }
    }
    for (auto iter : v)
    {
        cout << iter << " ";
    }
}

void postorder(struct node *n) // 2 stack tc-->O(N)  sc--->O(2N)
{
    vector<int> v;
    stack<node *> s1, s2;
    s1.push(n);
    if (n == NULL)
    {
        return;
    }
    while (!s1.empty())
    {
        n = s1.top();
        s1.pop();
        s2.push(n);

        if (n->left != NULL)
        {
            s1.push(n->left);
        }
        if (n->right != NULL)
        {
            s1.push(n->right);
        }
    }
    while (!s2.empty())
    {
        v.push_back(s2.top()->data);
        s2.pop();
    }

    for (auto iter : v)
    {
        cout << iter << " ";
    }
}

void postorder1(struct node *n) // 1 stack
{
    vector<int> v;
    stack<node *> s;
    node *cur = n;
    if (n == NULL)
    {
        return;
    }
    while (cur != NULL || !s.empty())
    {
        if (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        else
        {
            node *temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                v.push_back(temp->data);
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    v.push_back(temp->data);
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
    for (auto iter : v)
    {
        cout << iter << " ";
    }
}

int main()
{
    struct node *n = new node(1);
    n->left = new node(2);
    n->right = new node(7);
    n->left->left = new node(3);
    n->left->right = new node(4);
    n->left->right->left = new node(5);
    n->left->right->right = new node(6);

    inorder(n);
    cout << endl;
    preorder(n);
    cout << endl;
    postorder(n); // 2 stacks
    cout << endl;
    postorder1(n); // 1 stacks
    cout << endl;

    return 0;
}