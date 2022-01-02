// Count subsequence whose sum is k
// time complexity = O(2^N)
// space complexity = O(N) 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
int arr[10000001];

int Print_subsequence(int index, int n, int arr[], int sum, int k)
{
    // if the array index contains only positive integers add this code to reduce time complexity
    if (sum > k)
        return 0;
    if (index == n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }
    sum += arr[index];
    int l = Print_subsequence(index + 1, n, arr, sum, k);
    sum -= arr[index];
    int r = Print_subsequence(index + 1, n, arr, sum, k);
    return l + r;
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
    cout << Print_subsequence(0, n, arr, 0, k);
    return 0;
}