/*
You are given an m x n integer matrix grid​​​.
A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​.
The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell.
Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:

Return the biggest three distinct rhombus sums in the grid in descending order.
If there are less than three distinct values, return all of them.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkbounds(vector<vector<int>> &grid, vector<pair<int, int>> &v)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (auto pt : v)
        {
            if (pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n)
                return false;
        }
        return true;
    }
    bool getAllVertices(vector<vector<int>> &grid, vector<pair<int, int>> &v, pair<int, int> c, int delta)
    {
        pair<int, int> A(c.first - delta, c.second);
        pair<int, int> B(c.first, c.second + delta);
        pair<int, int> C(c.first + delta, c.second);
        pair<int, int> D(c.first, c.second - delta);
        v[0] = A, v[1] = B, v[2] = C, v[3] = D;
        if (checkbounds(grid, v))
            return true;
        else
            return false;
    }
    void getAllSum(vector<vector<int>> &grid, int &cx, int &cy, priority_queue<int> &pq)
    {
        // push RH sum of RH with area 0
        pq.push(grid[cx][cy]);
        vector<pair<int, int>> v(4);
        int delta = 1;
        while (getAllVertices(grid, v, {cx, cy}, delta))
        {
            pair<int, int> &A = v[0];
            pair<int, int> &B = v[1];
            pair<int, int> &C = v[2];
            pair<int, int> &D = v[3];
            int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] +
                       grid[D.first][D.second];

            // cells between AB
            for (int i = 1; i < delta; ++i)
            {
                csum += grid[A.first + i][A.second + i];
            }
            // between BC
            for (int i = 1; i < delta; ++i)
            {
                csum += grid[B.first + i][B.second - i];
            }
            // between CD
            for (int i = 1; i < delta; ++i)
            {
                csum += grid[C.first - i][C.second - i];
            }
            // between DA
            for (int i = 1; i < delta; ++i)
            {
                csum += grid[D.first - i][D.second + i];
            }
            pq.push(csum);
            ++delta;
        }
    }
    bool canpush(vector<int> ans, int top)
    {
        for (auto val : ans)
        {
            if (val == top)
                return false;
        }
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        vector<int> ans;
        priority_queue<int> pq; // set se bhi ho skta h
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                getAllSum(grid, i, j, pq);
            }
        }
        while (!pq.empty() && ans.size() < 3)
        {
            int top = pq.top();
            pq.pop();
            if (canpush(ans, top))
            {
                ans.push_back(top);
            }
        }
        return ans;
    }
};