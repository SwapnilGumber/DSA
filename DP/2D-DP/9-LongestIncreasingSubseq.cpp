// Given an integer array nums, return the length of the longest strictly increasing subsequence

#include <bits/stdc++.h>
using namespace std;

int solveUsingRec(vector<int> &nums, int curr, int prev)
{
    // base case
    if (curr >= nums.size())
        return 0;

    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + solveUsingRec(nums, curr + 1, curr);
    }
    int exclude = 0 + solveUsingRec(nums, curr + 1, prev);
    int ans = max(include, exclude);
    return ans;
}
int solveUsingMem(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    // base case
    if (curr >= nums.size())
        return 0;

    // already stored
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + solveUsingMem(nums, curr + 1, curr, dp);
    }
    int exclude = 0 + solveUsingMem(nums, curr + 1, prev, dp);
    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}
int solveUsingTab(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                include = 1 + dp[curr + 1][curr + 1];
            }
            int exclude = 0 + dp[curr + 1][prev + 1];
            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}
int solveUsingTabSO(vector<int> &nums)
{
    int n = nums.size();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                include = 1 + nextRow[curr + 1];
            }
            int exclude = 0 + nextRow[prev + 1];
            currRow[prev + 1] = max(include, exclude);
        }
        // shift
        nextRow = currRow;
    }
    return nextRow[0];
}
int solveUsingBS(vector<int> &nums)
{
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            // just bada number
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            // replace
            ans[index] = nums[i];
        }
    }
    return ans.size();
}
int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;
    int prev = -1;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // int ans = solveUsingMem(nums,curr,prev,dp);
    int ans = solveUsingTabSO(nums);
    return ans;
}