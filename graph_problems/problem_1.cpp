// You are given a array arr = {2,5,10} suppose and a start point and an end point (both are integer values)
// You are asked to compute minimum steps required to reach from start to end by multiplying the start value
//with the elements of array.
//Input-
// 2 100
// 2 5 10
// Output-
// 2
//logic- 2*10 = 20 --->1st step
//20 * 5 = 100 ----->second step

#include <bits/stdc++.h>
using namespace std;
//tc-->O(end-start+1)

int solve(int start,int end,int arr[1000],int n){
    vector<int> vis(end+1,0);
    vis[start]=1;
    queue<pair<int,int>> q;
    q.push({start,0});

    while (!q.empty())
    {
        int node=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(node==end) return steps;
        for (int i = 0; i < n; i++)
        {
            int m=node*arr[i];
            while (m<=end && !vis[m])
            {
                q.push({m,steps+1});
                vis[m]=1;
            }
            
        }
        
    }
    
    return -1;
}

int main()
{
    int start = 2;
    int end = 100;
    int arr[10]={2,5,10};
    int n=3;
    cout<<solve(start,end,arr,n);
    return 0;
}