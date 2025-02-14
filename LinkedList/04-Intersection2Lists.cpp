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

int LengthOfLL(ListNode *head)
{
    int length = 0;
    ListNode *temp = head;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *travel1 = headA;
    ListNode *travel2 = headB;
    int l1 = LengthOfLL(headA);
    int l2 = LengthOfLL(headB);
    while (l1 != l2)
    {
        if (travel1 == travel2)
            return travel1;
        if (l1 > l2)
        {
            travel1 = travel1->next;
            l1--;
        }
        if (l1 < l2)
        {
            travel2 = travel2->next;
            l2--;
        }
    }
    while (travel1 && travel2)
    {
        if (travel1 == travel2)
            return travel1;
        travel1 = travel1->next;
        travel2 = travel2->next;
    }
    return nullptr;
}