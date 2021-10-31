#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define tc ll t;cin>>t;while(t--);
int arr[100005];

void solve(int n){
    if(n<1){return;}
    // cout<<n<<" ";
    solve(n-1);
    cout<<n<<" ";
}

int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}