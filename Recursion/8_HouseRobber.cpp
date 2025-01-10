/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from
robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken
into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int i)
{
    // base case
    if (i >= nums.size())
    {
        return 0;
    }
    // recursive realtion
    int include = nums[i] + helper(nums, i + 2);
    int exclude = 0 + helper(nums, i + 1);
    int ans = max(include, exclude);
    return ans;
}
int rob(vector<int> &nums)
{
    int index = 0;
    int ans = helper(nums, index);
    return ans;
}