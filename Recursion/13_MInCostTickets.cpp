/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

#include <bits/stdc++.h>
using namespace std;
int mincostHelper(vector<int> &days, vector<int> &costs, int i)
{
    // base
    if (i >= days.size())
        return 0;
    // one case
    // 1 day pass
    int cost1 = costs[0] + mincostHelper(days, costs, i + 1);
    // 7 day pass
    int passEndday = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndday)
        j++;
    int cost7 = costs[1] + mincostHelper(days, costs, j);
    // 30 day pass
    passEndday = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndday)
        j++;
    int cost30 = costs[2] + mincostHelper(days, costs, j);

    return min(cost1, min(cost7, cost30));
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return mincostHelper(days, costs, 0);
}
