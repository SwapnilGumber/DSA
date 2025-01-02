/*
 Given a string S  and a character X, the task is to find the last index (0 based indexing) of X in string S.
 If no index found then the answer will be -1.
*/

#include <bits/stdc++.h>
using namespace std;

int findLastIndex(string s, char target, int index)
{
    if (index < 0)
        return -1;
    if (s[index] == target)
        return index;
    return findLastIndex(s, target, index - 1);
}
int LastIndex(string s, char p)
{
    // complete the function here
    int i = s.size() - 1;
    return findLastIndex(s, p, i);
}