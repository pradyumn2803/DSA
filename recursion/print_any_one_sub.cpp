// Print any one subsequence whose sum is k
// time complexity = O(2^N)*O(N)
// space complexity = O(N)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
int arr[10000001];

bool Print_subsequence(int index, int n, vector<int> &ds, int arr[], int sum, int k)
{
    if (index == n)
    {
        if (sum == k)
        {
            for (auto i : ds)
            {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    ds.push_back(arr[index]);
    sum += arr[index];
    if (Print_subsequence(index + 1, n, ds, arr, sum, k) == true)
        return true;
    sum -= arr[index];
    ds.pop_back();
    if (Print_subsequence(index + 1, n, ds, arr, sum, k) == true)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    vector<int> ds;
    Print_subsequence(0, n, ds, arr, 0, k);
    return 0;
}