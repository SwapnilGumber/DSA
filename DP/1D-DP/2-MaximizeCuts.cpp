/*
Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way
that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.

After performing all the cut operations, your total number of cut
segments must be maximum. Return the maximum number of cut segments possible.
*/

#include <bits/stdc++.h>
using namespace std;

// maximise the cuts
int solveUsingRec(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    int opt1 = 1 + solveUsingRec(n - x, x, y, z);
    int opt2 = 1 + solveUsingRec(n - y, x, y, z);
    int opt3 = 1 + solveUsingRec(n - z, x, y, z);

    return max(opt1, max(opt2, opt3));
}
int solveUsingMemo(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    // if ans already exist return
    if (dp[n] != INT_MIN)
        return dp[n];

    int opt1 = 1 + solveUsingMemo(n - x, x, y, z, dp);
    int opt2 = 1 + solveUsingMemo(n - y, x, y, z, dp);
    int opt3 = 1 + solveUsingMemo(n - z, x, y, z, dp);

    // store and return using dp array
    dp[n] = max(opt1, max(opt2, opt3));
    return dp[n];
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    // create dp array
    vector<int> dp(n + 1, INT_MIN);
    int ans = solveUsingMemo(n, x, y, z, dp);
    return ans;
}