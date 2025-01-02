// check if a string is a valid palindrome

#include <bits/stdc++.h>
using namespace std;

bool palindormRE(string s, int start, int end)
{
    if (start > end)
        return true;
    if (s[start] != s[end])
        return false;
    return palindormRE(s, start + 1, end - 1);
}
bool isPalindrome(string &s)
{
    // code here
    return palindormRE(s, 0, s.size() - 1);
}