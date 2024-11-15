/* Given a Binary Search Tree that contains unique positive integer values greater than 0.
The task is find if the BST contains a dead end. Here Dead End means a leaf node, at which
no other integer can be inserted.*/
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
    bool checkDeadEnd(Node *root, int min, int max)
    {
        if (!root)
            return false;

        // If the node is a leaf node and min == max, it's a dead end
        if (!root->left && !root->right)
        {
            if (min == max)
                return true;
            return false;
        }

        // Recur for the left and right subtrees
        return checkDeadEnd(root->left, min, root->data - 1) ||
               checkDeadEnd(root->right, root->data + 1, max);
    }

public:
    bool isDeadEnd(Node *root)
    {
        // Start with the minimum and maximum allowed values in the BST
        return checkDeadEnd(root, 1, INT_MAX);
    }
};
