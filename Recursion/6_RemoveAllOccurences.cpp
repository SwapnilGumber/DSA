/* Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.
*/

#include <bits/stdc++.h>
using namespace std;

void removeOcc(string &s, string part)
{
    // find part of string
    int found = s.find(part);
    // remove part from s
    if (found != string::npos)
    {
        string leftpart = s.substr(0, found);
        string rightpart = s.substr(found + part.size(), s.size());

        s = leftpart + rightpart;

        // call again function for s
        removeOcc(s, part);
    }
    else
        return;
}
string removeOccurrences(string s, string part)
{
    removeOcc(s, part);
    return s;
}