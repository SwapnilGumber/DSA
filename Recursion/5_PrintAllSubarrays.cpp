/*Given an array, arr[], generate all possible subarrays using recursion and return them as a vector of vectors.
The subarrays must be returned in the following order:
      1. Subarrays starting from the first element, followed by subarrays starting from the second element, and so on.
      2. For each starting index, subarrays should be in increasing length.*/
#include <bits/stdc++.h>
using namespace std;

void generateSubarrays(int start, int end, vector<int> &arr, vector<vector<int>> &result)
{
    // base case
    if (start == arr.size())
        return;
    if (end == arr.size())
    {
        generateSubarrays(start + 1, start + 1, arr, result);
        return;
    }
    // one case
    vector<int> subarray(arr.begin() + start, arr.begin() + end + 1);
    result.push_back(subarray);
    // recursive calls
    generateSubarrays(start, end + 1, arr, result);
}
vector<vector<int>> getSubArrays(vector<int> &arr)
{
    // code here
    vector<vector<int>> result;
    generateSubarrays(0, 0, arr, result);
    return result;
}
