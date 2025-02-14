#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    // Function which returns the  root of the flattened linked list.
    Node *mergeTwoList(Node *a, Node *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;

        Node *result;
        if (a->data < b->data)
        {
            result = a;
            result->bottom = mergeTwoList(a->bottom, b);
        }
        else
        {
            result = b;
            result->bottom = mergeTwoList(a, b->bottom);
        }
        return result;
    }
    Node *flatten(Node *root)
    {
        // Your code here
        if (!root || !root->next)
            return root;
        root->next = flatten(root->next);
        root = mergeTwoList(root, root->next);

        return root;
    }
};