/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
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

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *even_head = head->next;
    ListNode *even_tail = even_head;
    ListNode *odd_head = head;
    ListNode *odd_tail = odd_head;

    while (even_tail != NULL || even_tail->next != NULL || odd_tail->next != NULL)
    {
        odd_tail->next = even_tail->next;
        odd_tail = odd_tail->next;
        even_tail->next = odd_tail->next;
        even_tail = even_tail->next;
    }
    odd_tail->next = even_head;

    return odd_head;
}