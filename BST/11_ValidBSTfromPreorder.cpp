/*
You are given a preorder traversal A, of a Binary Search Tree.

Find if it is a valid preorder traversal of a BST.

Note: Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.
*/
#include <bits/stdc++.h>
using namespace std;

void build(int &i, int min, int max, vector<int> A)
{
    if (i >= A.size())
        return;
    if (A[i] > min && A[i] < max)
    {
        int rootData = A[i++];
        build(i, min, rootData, A);
        build(i, rootData, max, A);
    }
}

int solve(vector<int> &A)
{
    int min = INT_MIN, max = INT_MAX;
    int i = 0;
    build(i, min, max, A);
    return i == A.size();
}