/*
You are given an integer array coins representing coins of different denominations and an integer
amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money
cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

#include <bits/stdc++.h>
using namespace std;

int UsingTab(vector<int> &coins, int amount)
{
    // step-1 (initialize)
    int n = amount;
    vector<int> dp(n + 1, INT_MAX);
    // step-2 (base case analyse)
    dp[0] = 0;
    // step-3 (realtion)
    for (int value = 1; value <= n; value++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (value - coins[i] >= 0)
            {
                int RecKaAns = dp[value - coins[i]];
                if (RecKaAns != INT_MAX)
                {
                    int ans = 1 + RecKaAns;
                    mini = min(ans, mini);
                }
            }
        }
        dp[value] = mini;
    }
    return dp[amount];
}
int coinChange(vector<int> &coins, int amount)
{
    int ans = UsingTab(coins, amount);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

int UsingRec(vector<int> &coins, int amount)
{
    // base case
    if (amount == 0)
        return 0;
    // recursive relation
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        // ans using ith coin
        if (amount - coins[i] >= 0)
        {
            int RecKaAns = UsingRec(coins, amount - coins[i]);
            if (RecKaAns != INT_MAX)
            {
                int ans = 1 + RecKaAns;
                mini = min(ans, mini);
            }
        }
    }
    return mini;
}
int UsingMemo(vector<int> &coins, int amount, vector<int> &dp)
{
    // base case
    if (amount == 0)
        return 0;
    // already exist
    if (dp[amount] != -1)
        return dp[amount];
    // recursive relation
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        // ans using ith coin
        if (amount - coins[i] >= 0)
        {
            int RecKaAns = UsingMemo(coins, amount - coins[i], dp);
            if (RecKaAns != INT_MAX)
            {
                int ans = 1 + RecKaAns;
                mini = min(ans, mini);
            }
        }
    }
    dp[amount] = mini;
    return dp[amount];
}
int coinChange(vector<int> &coins, int amount)
{
    int n = amount;
    vector<int> dp(n + 1, -1);
    int ans = UsingMemo(coins, amount, dp);
    if (ans == INT_MAX)
        return -1;
    return ans;
}