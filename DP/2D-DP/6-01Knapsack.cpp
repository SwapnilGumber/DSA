/*
Given N items where each item has some weight and profit associated with it and also
given a bag with capacity W, [i.e., the bag can hold at most W weight in it].
The task is to put the items into the bag such that the sum of profits associated
with them is the maximum possible.

Note: The constraint here is we can either put an item completely into the bag or
cannot put it at all [It is not possible to put a part of an item into the bag].
*/

#include <bits/stdc++.h>
using namespace std;

// 0/1 Knapsack Problem --->> 2D DP
int solveUsingRec(int capacity, int wt[], int profit[], int index, int n)
{
    // base case
    if (index == n)
    {
        return 0;
    }
    // inc/exc
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingRec(capacity - wt[index], wt, profit, index + 1, n);
    }
    int exclude = 0 + solveUsingRec(capacity, wt, profit, index + 1, n);
    int ans = max(include, exclude);
    return ans;
}
// top-down approach
int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>> &dp)
{
    // base case
    if (index >= n)
    {
        return 0;
    }
    // alreadys exist
    if (dp[capacity][index] != -1)
        return dp[capacity][index];

    // inc/exc
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingMem(capacity - wt[index], wt, profit, index + 1, n, dp);
    }
    int exclude = 0 + solveUsingMem(capacity, wt, profit, index + 1, n, dp);
    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}
// bottom-up approach
int solveUsingTab(int capacity, int wt[], int profit[], int n)
{
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

    for (int row = 0; row <= capacity; row++)
    {
        dp[row][n] = 0;
    }

    for (int i = 0; i <= capacity; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            // inc/exc
            int include = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + dp[i - wt[j]][j + 1];
            }
            int exclude = 0 + dp[i][j + 1];
            dp[i][j] = max(include, exclude);
        }
    }

    return dp[capacity][0];
}
int spaceOptimize(int capacity, int wt[], int profit[], int n)
{
    vector<int> next(capacity + 1, 0);
    vector<int> curr(capacity + 1, -1);

    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = 0; i <= capacity; i++)
        {
            // inc/exc
            int include = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + next[i - wt[j]];
            }
            int exclude = 0 + next[i];
            curr[i] = max(include, exclude);
        }
        // shifting
        next = curr;
    }

    return curr[capacity];
}

// single 1D array
int spaceOptimize1(int capacity, int wt[], int profit[], int n)
{
    vector<int> next(capacity + 1, 0);
    // vector<int> curr(capacity+1,-1);

    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = capacity; i >= 0; i--)
        {
            // inc/exc
            int include = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + next[i - wt[j]];
            }
            int exclude = 0 + next[i];
            next[i] = max(include, exclude);
        }
    }

    return next[capacity];
}