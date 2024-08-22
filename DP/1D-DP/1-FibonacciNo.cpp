#include <bits/stdc++.h>
using namespace std;

// fibonacci
int fibUsingRec(int n)
{
    // base case
    if (n == 1 || n == 0)
        return n;
    // rec realtion
    return fibUsingRec(n - 1) + fibUsingRec(n - 2);
}
// top-down approach
int solveUsingMem(int n, vector<int> &dp)
{
    // base case
    if (n == 0 || n == 1)
        return n;

    // if ans already exits then  return ans
    if (dp[n] != -1)
        return dp[n];

    // store and return using dp array
    dp[n] = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);
    return dp[n];
}
// bottom-up approach
int solveUsingTab(int n)
{
    // create dp array
    vector<int> dp(n + 1, -1);
    // analyse base case and fill dp array
    dp[0] = 0;
    if (n == 0)
        return 0; // extra case
    dp[1] = 1;
    // fill remaining dp array
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// space optimization
int solveUsingTabSpace(int n)
{
    int prev = 0;
    if (n == 0 || n == 1)
        return n;
    int curr = 1;
    int ans;
    for (int i = 2; i <= n; i++)
    {
        ans = prev + curr;
        prev = curr;
        curr = ans;
    }
    return ans;
}
