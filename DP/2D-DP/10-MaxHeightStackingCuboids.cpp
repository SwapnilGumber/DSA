/*
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.
*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &curr, vector<int> &prev)
{
    // curr -> bada dibba , prev -> chota dibba
    if (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solveUsingTabSO(vector<vector<int>> &cuboids)
{
    int n = cuboids.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        // ulta chal rhe hum
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || check(cuboids[curr], cuboids[prev]))
            {
                include = cuboids[curr][2] + nextRow[curr + 1];
            }
            int exclude = 0 + nextRow[prev + 1];
            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}
int maxHeight(vector<vector<int>> &cuboids)
{
    // biggest dimension as height
    for (auto &cuboid : cuboids)
    {
        sort(cuboid.begin(), cuboid.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int ans = solveUsingTabSO(cuboids);
    return ans;
}