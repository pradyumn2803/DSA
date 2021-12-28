#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
string arr;

// time cmplexity=O(N/2)
// Auxilliary Space Cokmplexity= stack space=O(N/2)

void reverse_arr(int i, int n, string arr)
{
    if (i >= (n / 2))
    {
        cout << "YES";
        return;
    }
    if (arr[i] != arr[n - i - 1])
    {
        cout << "NO";
        return;
    }
    reverse_arr(i + 1, n, arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string arr;
    cin >> arr;
    reverse_arr(0, arr.length(), arr);
    return 0;
}