/*
You are a professional robber planning to rob houses along a street. Each house has a certain
amount of money stashed, the only constraint stopping you from robbing each of them is that
adjacent houses have security systems connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the
maximum amount of money you can rob tonight without alerting the police.
*/

#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int i, vector<int> &dp)
{
    // base case
    if (i >= nums.size())
    {
        return 0;
    }
    // if alreadys exists
    if (dp[i] != -1)
        return dp[i];
    // recursive relation
    int include = nums[i] + helper(nums, i + 2, dp);
    int exclude = 0 + helper(nums, i + 1, dp);
    dp[i] = max(include, exclude);
    return dp[i];
}
// top-down approach
int rob(vector<int> &nums)
{
    int index = 0, n = nums.size();
    vector<int> dp(n + 1, -1);
    int ans = helper(nums, index, dp);
    return ans;
}
// tabulation method
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    // step-1
    vector<int> dp(n + 1, 0);
    // step-2
    dp[n - 1] = nums[n - 1];
    for (int index = n - 2; index >= 0; index--)
    {
        int include = nums[index] + dp[index + 2];
        int exclude = 0 + dp[index + 1];
        dp[index] = max(include, exclude);
    }
    return dp[0];
}
// space optimisation method
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    // everything that replaces dp array
    int prev = nums[n - 1];
    int next = 0;
    int curr;
    for (int index = n - 2; index >= 0; index--)
    {
        // replace dp array
        int include = nums[index] + next;
        int exclude = 0 + prev;
        curr = max(include, exclude);
        // update
        next = prev;
        prev = curr;
    }
    return prev;
}