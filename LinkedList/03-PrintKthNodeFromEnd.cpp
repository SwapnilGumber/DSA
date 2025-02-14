#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to find the data of kth node from the end of a linked list.
class Solution
{
public:
    int lengthNode(Node *head)
    {
        Node *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    int getKthFromLast(Node *head, int k)
    {
        // Your code here
        int length = lengthNode(head);
        if (k > length)
            return -1;
        int kstart = length - k;
        Node *ans = head;
        while (kstart--)
        {
            ans = ans->next;
        }
        return ans->data;
    }
};