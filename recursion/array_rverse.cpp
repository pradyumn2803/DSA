#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
int arr[10000001];

void reverse_arr(int i, int n, int arr[])
{
    if (i >= (n / 2))
        return;
    swap(arr[i], arr[n - i - 1]);
    reverse_arr(i + 1, n, arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverse_arr(0, n, arr);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}