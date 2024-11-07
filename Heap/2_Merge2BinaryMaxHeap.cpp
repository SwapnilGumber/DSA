// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
//  1) concatenate 2) heapify
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
    // 0-index based
    void heapify(vector<int> &v, int i, int n)
    {
        while (true)
        {
            int left = 2 * i + 1, right = 2 * i + 2;
            int swapindex = i;
            if (left < n && v[left] > v[swapindex])
            {
                swapindex = left;
            }
            if (right < n && v[right] > v[swapindex])
            {
                swapindex = right;
            }
            if (swapindex == i)
                break;
            swap(v[i], v[swapindex]);
            i = swapindex;
        }
    }

public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // your code here
        // merge 2 vectors
        vector<int> c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());
        // heapify c
        for (int i = (c.size() / 2) - 1; i >= 0; i--)
        {
            heapify(c, i, c.size());
        }
        return c;
    }
};