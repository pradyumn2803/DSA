#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
int arr[10000001];

void Subsequence(int i, vector<int> &ds, int arr[], int n)
{
    if (i == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }
    Subsequence(i + 1, ds, arr, n);
    ds.push_back(arr[i]);
    Subsequence(i + 1, ds, arr, n);
    ds.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ds;
    Subsequence(0, ds, arr, n);
    return 0;
}