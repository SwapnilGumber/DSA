/*
You are given a 0-indexed integer array nums consisting of 3 * n elements.

You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

The first n elements belonging to the first part and their sum is sumfirst.
The next n elements belonging to the second part and their sum is sumsecond.
The difference in sums of the two parts is denoted as sumfirst - sumsecond.

For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
Return the minimum difference possible between the sums of the two parts after the removal of n elements.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define ll long long
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;
        vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);
        // prefix = sum of first n elements from left , suffix from right
        ll sum = 0;
        priority_queue<ll> maxHeap;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxHeap.push(nums[i]);
            // pop out max elements
            if (maxHeap.size() > n)
            {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n)
                prefix[i] = sum;
        }
        sum = 0;
        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            sum += nums[i];
            minHeap.push(nums[i]);
            // pop out max elements
            if (minHeap.size() > n)
            {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n)
                suffix[i] = sum;
        }
        ll ans = LONG_LONG_MAX;
        for (int i = n - 1; i < 2 * n; i++)
        {
            ans = min(ans, prefix[i] - suffix[i + 1]);
        }
        return ans;
    }
};