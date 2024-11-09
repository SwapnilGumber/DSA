/* There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key.
If either predecessor or successor is not found, then set it to NULL. */
// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Your code goes here
        Node *curr = root;
        while (curr)
        {
            if (curr->key > key)
            {
                suc = curr;
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        curr = root;
        while (curr)
        {
            if (curr->key < key)
            {
                pre = curr;
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
    }
};