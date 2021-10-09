#include<bits/stdc++.h>
using namespace std;

/*
            1
           / \
          2   5
         / \ / \
        3  4 6  7
       /
      9
*/

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(){
        data=0;
        left=right=NULL;
    }

    node(int d){
        data=d;
        left=right=NULL;
    }

    node(int d,node* l,node* r){
        data=d;
        left=l;
        right=r;
    }
};

int recursive(struct node *n){

    if(n==NULL) return 0;
    int lh=recursive(n->left);
    int rh=recursive(n->right);

    return 1+max(lh,rh);
}

int level_order(struct node *n)
{
    int count=0;
    queue<node *> q;
    if (n == NULL)
    {
        return 0;
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
        count++;
    }
    return count;
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

    cout<<"By recursion "<<recursive(n)<<endl;//tc-->O(N) sc--->O(N)
    cout<<"By level-order "<<level_order(n)<<endl;//tc-->O(N) sc--->O(N)
    return 0;
}