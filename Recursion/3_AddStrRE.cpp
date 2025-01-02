// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

#include <bits/stdc++.h>
using namespace std;

string addRE(string num1, string num2, int p1, int p2, int carry)
{
    // base case
    if (p1 < 0 && p2 < 0)
    {
        if (carry != 0)
        {
            return string(1, carry + '0');
        }
        return "";
    }
    // ek case
    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
    int csum = n1 + n2 + carry;
    int digit = csum % 10;
    carry = csum / 10;
    string ans = "";
    ans.push_back(digit + '0');
    // baki recursion
    ans += addRE(num1, num2, p1 - 1, p2 - 1, carry);
    return ans;
}
string addStrings(string num1, string num2)
{
    string ans = addRE(num1, num2, num1.size() - 1, num2.size() - 1, 0);
    reverse(ans.begin(), ans.end());
    return ans;
}