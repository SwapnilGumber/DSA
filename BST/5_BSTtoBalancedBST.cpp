/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values.
If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
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

TreeNode *buildBalanced(vector<int> &nodes, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    TreeNode *node = new TreeNode(nodes[mid]);
    node->left = buildBalanced(nodes, start, mid - 1);
    node->right = buildBalanced(nodes, mid, end);
    return node;
}
void inorder(TreeNode *root, vector<int> &nodes)
{
    if (root == NULL)
        return;
    inorder(root->left, nodes);
    nodes.push_back(root->val);
    inorder(root->right, nodes);
}
TreeNode *balanceBST(TreeNode *root)
{
    vector<int> nodes;
    inorder(root, nodes);
    return buildBalanced(nodes, 0, nodes.size() - 1);
}
