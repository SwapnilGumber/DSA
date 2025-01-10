/*
You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll
the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it
modulo 109 + 7.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, int target)
{
    // base case
    if (target <= 0)
        return 0;
    if (n == 0 && target != 0)
        return 0;
    if (target == 0 && n != 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;

    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans += solve(n - 1, k, target - i);
    }
    return ans;
}
int numRollsToTarget(int n, int k, int target)
{
    return solve(n, k, target);
}