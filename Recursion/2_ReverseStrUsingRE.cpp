// Write a function that reverses a string. The input string is given as an array of characters s.

#include <bits/stdc++.h>
using namespace std;

void reverseStr(vector<char> &s, int start, int end)
{
    if (start > end)
        return;
    swap(s[start], s[end]);
    reverseStr(s, start + 1, end - 1);
}
void reverseString(vector<char> &s)
{
    reverseStr(s, 0, s.size() - 1);
}