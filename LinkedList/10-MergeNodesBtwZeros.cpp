/*
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeNodes(ListNode *head)
{
    ListNode *curr = head;
    ListNode *newHead = NULL;
    ListNode *tail = NULL;

    int sum = 0;
    while (curr)
    {
        if (curr->val == 0)
        {
            if (sum > 0)
            {
                ListNode *newNode = new ListNode(sum);
                if (!newHead)
                {
                    newHead = newNode;
                    tail = newNode;
                }
                else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
                sum = 0;
            }
        }
        else
        {
            sum += curr->val;
        }
        curr = curr->next;
    }
    return newHead;
}