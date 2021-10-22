/*
time complexity-O(N)*logN
space complexity-O(N)
*/
#include <bits/stdc++.h>
using namespace std;

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

class solution
{
public:
    vector<vector<int>> verticalTraversal(struct node *n)
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<node *, pair<int, int>>> todo;
        todo.push({n, {0, 0}});
        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            node *node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->data);
            if (node->left)
            {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main()
{

    return 0;
}
