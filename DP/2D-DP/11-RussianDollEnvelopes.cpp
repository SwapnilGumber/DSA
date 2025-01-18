/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.
*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &curr, vector<int> &prev)
{
    // curr -> bada dibba , prev -> chota dibba
    if (prev[0] < curr[0] && prev[1] < curr[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solveUsingTabSO(vector<vector<int>> &envelopes)
{
    int n = envelopes.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        // ulta chal rhe hum
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || check(envelopes[curr], envelopes[prev]))
            {
                include = 1 + nextRow[curr + 1];
            }
            int exclude = 0 + nextRow[prev + 1];
            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    // // rotation not allowed -> individual sorting not allowed
    // sort(envelopes.begin(), envelopes.end());
    // int ans = solveUsingTabSO(envelopes);
    // return ans;

    sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
         {
             if (a[0] == b[0])
             {
                 return a[1] > b[1]; // Descending order for heights
             }
             return a[0] < b[0]; // Ascending order for widths
         });

    vector<int> heights;
    for (const auto &envelope : envelopes)
    {
        heights.push_back(envelope[1]);
    }

    vector<int> lis;
    for (int h : heights)
    {
        auto it = lower_bound(lis.begin(), lis.end(), h);
        if (it == lis.end())
        {
            lis.push_back(h);
        }
        else
        {
            *it = h;
        }
    }
    return lis.size();
}