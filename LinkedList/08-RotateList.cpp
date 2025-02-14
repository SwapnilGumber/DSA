// Given the head of a linked list, rotate the list to the right by k places.

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

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || k == 0)
    {
        return head;
    }
    ListNode *temp = head;
    ListNode *prev = temp;
    int length = 1;
    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
        length++;
    }
    k = k % length;
    if (k == 0)
        return head;
    prev->next = NULL;
    temp->next = head;
    return rotateRight(temp, k - 1);
}