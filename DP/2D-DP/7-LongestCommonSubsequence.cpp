#include <bits/stdc++.h>
using namespace std;

int solveUsingRec(string text1, int i, string text2, int j)
{
    if (i >= text1.size() || j >= text2.size())
    {
        return 0;
    }
    int ans = 0;
    if (text1[i] == text2[j])
    {
        ans = 1 + solveUsingRec(text1, i + 1, text2, j + 1);
    }
    else
    {
        ans = 0 + max(solveUsingRec(text1, i + 1, text2, j),
                      solveUsingRec(text1, i, text2, j + 1));
    }
    return ans;
}
int longestCommonSubsequence(string text1, string text2)
{
    int i = 0, j = 0;
    int ans = solveUsingRec(text1, i, text2, j);
    return ans;
}
// Using memoization
int solveUsingMemo(string &text1, int i, string &text2, int j, vector<vector<int>> &dp)
{
    // base case
    if (i >= text1.size() || j >= text2.size())
    {
        return 0;
    }
    // check for ans
    if (dp[i][j] != (-1))
        return dp[i][j];
    int ans = 0;
    if (text1[i] == text2[j])
    {
        ans = 1 + solveUsingMemo(text1, i + 1, text2, j + 1, dp);
    }
    else
    {
        ans = 0 + max(solveUsingMemo(text1, i + 1, text2, j, dp),
                      solveUsingMemo(text1, i, text2, j + 1, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int longestCommonSubsequence(string text1, string text2)
{
    int i = 0, j = 0;
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
    int ans = solveUsingMemo(text1, i, text2, j, dp);
    return ans;
}
// Using Tabulation
int solveUsingTab(string text1, string text2)
{
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    for (int i = text1.length() - 1; i >= 0; i--)
    {
        for (int j = text2.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = 0 + max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int longestCommonSubsequence(string text1, string text2)
{
    int ans = solveUsingTab(text1, text2);
    return ans;
}
// space optimization
int solveUsingTabSO(string text1, string text2)
{
    vector<int> curr(text1.length() + 1, 0);
    vector<int> next(text1.length() + 1, 0);

    for (int j = text2.length() - 1; j >= 0; j--)
    {
        for (int i = text1.length() - 1; i >= 0; i--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + next[i + 1];
            }
            else
            {
                ans = 0 + max(curr[i + 1], next[i]);
            }
            curr[i] = ans;
        }
        // shifting
        next = curr;
    }
    return curr[0];
}
int longestCommonSubsequence(string text1, string text2)
{
    int ans = solveUsingTabSO(text1, text2);
    return ans;
}