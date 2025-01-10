/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself.
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/

#include <bits/stdc++.h>
using namespace std;

int perfectSqHelper(int n)
{
    if (n == 0)
        return 1;
    int i = 1, end = sqrt(n), ans = INT_MAX;
    while (i <= end)
    {
        int perfectSq = i * i;
        int numOfPerfectSq = 1 + perfectSqHelper(n - perfectSq);
        ans = min(ans, numOfPerfectSq);
        i++;
    }
    return ans;
}
int numSquares(int n)
{
    return perfectSqHelper(n) - 1;
}