/*
Given a fence with n posts and k colors, find out the number of ways of
painting the fence such that at most 2 adjacent posts have the same color.
*/

#include <bits/stdc++.h>
using namespace std;

// Painting Fence Algorithm using Recursion
int solveUsingRec(int n, int k)
{
    // base case
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    int ans = (solveUsingRec(n - 1, k) + solveUsingRec(n - 2, k)) * (k - 1);
    return ans;
}
// top-down approach
int solveUsingMemo(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    // already exists
    if (dp[n] != -1)
        return dp[n];

    dp[n] = (solveUsingMemo(n - 1, k, dp) + solveUsingMemo(n - 2, k, dp)) * (k - 1);
    return dp[n];
}
// bottom-up approach
int solveUsingTabulation(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n];
}
// space optimization
int spaceOptimized(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    int prev2 = k;
    int prev1 = k * k;
    int curr = -1;

    for (int i = 3; i <= n; i++)
    {
        curr = (prev2 + prev1) * (k - 1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
