#include <bits/stdc++.h>
using namespace std;

// delete n nodes after m nodes
//   The input list will have at least one element
//   Node is defined as

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *linkdelete(Node *head, int n, int m)
    {
        // code here
        Node *curr = head;
        while (curr)
        {
            for (int i = 1; i < m && curr; i++)
                curr = curr->next;
            if (!curr)
                break;
            Node *temp = curr->next;
            for (int i = 0; i < n && temp; i++)
            {
                Node *to_delete = temp;
                temp = temp->next;
                delete to_delete;
            }
            curr->next = temp;
            curr = temp;
        }
        return head;
    }
};