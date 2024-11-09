/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// brute
TreeNode *helper(vector<int> &preorder, int &index, int bound)
{
    if (index == preorder.size() || preorder[index] > bound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[index]);
    index++;

    root->left = helper(preorder, index, root->val);
    root->right = helper(preorder, index, bound);

    return root;
}
TreeNode *bstFromPreorder1(vector<int> &preorder)
{
    int index = 0;
    return helper(preorder, index, INT_MAX);
}

// inorder(sort preorder) + preorder -> bst

// optimized
TreeNode *build(int &i, int min, int max, vector<int> &preorder)
{
    if (i >= preorder.size())
        return NULL;
    TreeNode *root = NULL;
    if (preorder[i] < max && preorder[i] > min)
    {
        root = new TreeNode(preorder[i++]);
        root->left = build(i, min, root->val, preorder);
        root->right = build(i, root->val, max, preorder);
    }
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int min = INT_MIN, max = INT_MAX;
    int i = 0;
    return build(i, min, max, preorder);
}