// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

// 1) CBT & 2) MaxHeap

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

    int NodeCount(struct Node *root)
    {
        if (root == NULL)
            return 0;
        int l = NodeCount(root->left);
        int r = NodeCount(root->right);
        return 1 + l + r;
    }
    bool isCBT(int &n, int i, struct Node *root)
    {
        if (!root)
            return true;
        if (i > n)
            return false;
        return isCBT(n, 2 * i, root->left) && isCBT(n, 2 * i + 1, root->right);
    }
    bool ismaxHeap(struct Node *root)
    {
        if (!root)
            return true;
        bool ans = false;
        if (!root->left && !root->right)
            ans = true;
        else if (root->left && !root->right)
        {
            ans = root->data > root->left->data;
        }
        else
        {
            ans = (root->data > root->right->data) && (root->data > root->left->data);
        }
        return ans && ismaxHeap(root->left) && ismaxHeap(root->right);
    }
    // maxheap property root and its children all should follow
public:
    bool isHeap(struct Node *tree)
    {
        // code here
        int n = NodeCount(tree);
        int i = 1;
        return isCBT(n, i, tree) && ismaxHeap(tree);
    }
};