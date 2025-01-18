/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

#include <bits/stdc++.h>
using namespace std;

int solveUsingRec(string &a, string &b, int i, int j)
{
    // base case
    if (i == a.length())
        return b.length() - j;
    if (j == b.length())
        return a.length() - i;

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 0 + solveUsingRec(a, b, i + 1, j + 1);
    }
    else
    {
        int replace = 1 + solveUsingRec(a, b, i + 1, j + 1);
        int insert = 1 + solveUsingRec(a, b, i, j + 1);
        int remove = 1 + solveUsingRec(a, b, i + 1, j);
        ans = min(insert, min(replace, remove));
    }
    return ans;
}
int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == a.length())
        return b.length() - j;
    if (j == b.length())
        return a.length() - i;

    // check ans already
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 0 + solveUsingMem(a, b, i + 1, j + 1, dp);
    }
    else
    {
        int replace = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
        int insert = 1 + solveUsingMem(a, b, i, j + 1, dp);
        int remove = 1 + solveUsingMem(a, b, i + 1, j, dp);
        ans = min(insert, min(replace, remove));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveUsingTabSO(string a, string b)
{
    // vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,-1));
    vector<int> curr(a.length() + 1, 0);
    vector<int> next(a.length() + 1, 0);

    // for(int col=0; col<=b.length(); col++){
    //     dp[a.length()][col] = b.length()-col;
    // }
    for (int row = 0; row <= a.length(); row++)
    {
        next[row] = a.length() - row;
    }
    // colm wise
    for (int j = b.length() - 1; j >= 0; j--)
    {
        // har naye colm ke last dabbe mei ans store kro
        curr[a.length()] = b.length() - j;
        for (int i = a.length() - 1; i >= 0; i--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 0 + next[i + 1];
            }
            else
            {
                int replace = 1 + next[i + 1];
                int insert = 1 + next[i];
                int remove = 1 + curr[i + 1];
                ans = min(insert, min(replace, remove));
            }
            curr[i] = ans;
        }
        // shift
        next = curr;
    }
    return next[0];
}
int minDistance(string word1, string word2)
{
    int i = 0, j = 0;
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
    int ans = solveUsingMem(word1, word2, i, j, dp);
    return ans;
}