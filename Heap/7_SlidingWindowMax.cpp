/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> maxHeap; // pair{value,index}
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            maxHeap.push({nums[i], i});
        }
        ans.push_back(maxHeap.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            maxHeap.push({nums[i], i});
            auto &top = maxHeap.top();
            while (top.second <= i - k)
            {
                maxHeap.pop();
            }
            ans.push_back(maxHeap.top().first);
        }
        return ans;
    }
};