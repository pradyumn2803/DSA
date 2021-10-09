#include <bits/stdc++.h>
using namespace std;
/*
            1
           / \
          2   5
         / \ / \
        3  4 6  7
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

void pre_post_inorder_traversal(struct node *n) //tc-->O(N) sc-->O(N)
{
    stack<pair<node *, int>> st;
    vector<int> pre, post, in;
    st.push({n, 1});
    if (n == NULL)
        return;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is a part of pre
        // increment 1 to 2
        // push the left side of the tree
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        // this is a part of post
        // increment 2 to 3
        // push the right side of the tree
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
    for(auto iter: pre){
        cout<<iter<<" ";
    }
    cout<<endl;
    for(auto iter: in){
        cout<<iter<<" ";
    }
    cout<<endl;
    for(auto iter: post){
        cout<<iter<<" ";
    }
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

    pre_post_inorder_traversal(n);
    return 0;
}