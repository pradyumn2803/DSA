// fibonacci

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int main()
{
    // Memoization

    // tc=O(N) SC=O(N)
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solve(n, dp);

    // Tabulation

    // Approach 1:
    // tc=O(N) SC=O(N)
    vector<int> dp1(n + 1, -1);
    dp1[0] = 0;
    dp1[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    }
    cout << dp1[n];

    // Approach 2:
    // tc=O(N) SC=O(1)
    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    cout << prev << endl;
    return 0;
}