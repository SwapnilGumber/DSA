/*
Given a Binary Search Tree of size N, find the Median of its Node values.
*/

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

int findNodes(Node *root)
{
    int count = 0;
    Node *curr = root;
    while (curr)
    {
        // left Node is NULL then visit it and go right
        if (curr->left == NULL)
        {
            count++;
            curr = curr->right;
        }
        // left is not NULL
        else
        {
            // find inorder predecessor
            // 1 left then right right .....
            Node *pred = curr->left;
            // to avoid loop between curr and pred with no child
            while (pred->right != curr && pred->right)
                pred = pred->right;
            // if pred right is NULL then go left after link from pred to curr
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            // left is already visited, Go right after visiting curr while removing link
            else
            {
                pred->right = NULL;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}
// Morris Traversal
float helper(Node *root, int n)
{
    int i = 0;
    int odd1 = (n + 1) / 2, oddVal = -1;
    // even  = n/2 + (n/2 +1) / 2
    // odd = (n+1)/2
    int even1 = (n) / 2, even1Val = -1;
    int even2 = n / 2 + 1, even2Val = -1;
    Node *curr = root;
    while (curr)
    {
        // left Node is NULL then visit it and go right
        if (curr->left == NULL)
        {
            i++;
            if (i == odd1)
                oddVal = curr->data;
            if (i == even1)
                even1Val = curr->data;
            if (i == even2)
                even2Val = curr->data;
            curr = curr->right;
        }
        // left is not NULL
        else
        {
            // find inorder predecessor
            // 1 left then right right .....
            Node *pred = curr->left;
            // to avoid loop between curr and pred with no child
            while (pred->right != curr && pred->right)
                pred = pred->right;
            // if pred right is NULL then go left after link from pred to curr
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            // left is already visited, Go right after visiting curr while removing link
            else
            {
                pred->right = NULL;
                i++;
                if (i == odd1)
                    oddVal = curr->data;
                if (i == even1)
                    even1Val = curr->data;
                if (i == even2)
                    even2Val = curr->data;
                curr = curr->right;
            }
        }
    }
    float median = 0;
    if ((n & 1) == 0)
    {
        // even
        median = (even1Val + even2Val) / 2.0;
    }
    else
    {
        // odd
        median = oddVal;
    }
    return median;
}
float findMedian(struct Node *root)
{
    // Code here
    int n = findNodes(root);
    return helper(root, n);
}