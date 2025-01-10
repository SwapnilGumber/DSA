/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

#include <bits/stdc++.h>
using namespace std;

bool isMatchHelper(string s, int si, string p, int pi)
{
    // base
    if (si == s.size() && pi == p.size())
        return true;
    if (si == s.size() && pi < p.size())
    {
        while (pi < p.size())
        {
            if (p[pi] != '*')
                return false;
            pi++;
        }
        return true;
    }
    // one case
    // single character matching
    if (s[si] == p[pi] || '?' == p[pi])
    {
        return isMatchHelper(s, si + 1, p, pi + 1);
    }
    // multi
    if (p[pi] == '*')
    {
        // A) treat * as null
        bool caseA = isMatchHelper(s, si, p, pi + 1);
        // B) consume character
        bool caseB = isMatchHelper(s, si + 1, p, pi);

        return caseA || caseB;
    }
    return false;
}
bool isMatch(string s, string p)
{
    int si = 0, pi = 0; // ptr for s string and p string
    return isMatchHelper(s, si, p, pi);
}