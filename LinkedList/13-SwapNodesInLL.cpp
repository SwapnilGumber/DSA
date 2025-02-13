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

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int length = 0;
        ListNode *curr = head;
        ListNode *start = head;
        ListNode *last = head;
        while (curr)
        {
            length++;
            curr = curr->next;
        }
        for (int i = 1; i < k; i++)
        {
            start = start->next;
        }
        for (int i = 1; i <= length - k; i++)
        {
            last = last->next;
        }
        swap(start->val, last->val);
        return head;
    }
};

// Try Swap using changing Links

// using link swapping
int Len(ListNode *head)
{
    if (!head)
        return 0;
    return 1 + Len(head->next);
}
ListNode *swapNodes(ListNode *head, int k)
{
    // case-1
    if (!head || !head->next)
        return head;
    int len = Len(head);
    int lpos = k;
    int rpos = len - k + 1;

    if (rpos < lpos)
        swap(lpos, rpos);

    // case-2
    if (lpos == rpos)
        return head;

    // case-3
    if (len == 2)
    {
        ListNode *nextNode = head->next;
        nextNode->next = head;
        head->next = NULL;
        head = nextNode;
        return head;
    }

    // case-4
    if (lpos == 1)
    {
        ListNode *lp = 0;
        ListNode *ln = head;
        ListNode *rp = head;
        for (int i = 0; i < rpos - 2; i++)
        {
            rp = rp->next;
        }
        ListNode *rn = rp->next;
        ListNode *rsave = rn->next;
        // swapping
        rn->next = ln->next;
        rp->next = ln;
        ln->next = rsave;
        head = rn;
        return head;
    }

    int noOfNodeBtwRnL = rpos - lpos - 1;
    // case-5
    if (noOfNodeBtwRnL == 0)
    {
        // ln and rn are adjacents
        ListNode *lp = head;
        for (int i = 0; i < lpos - 2; i++)
            lp = lp->next;
        ListNode *ln = lp->next;

        ListNode *rp = head;
        for (int i = 0; i < rpos - 2; i++)
            rp = rp->next;
        ListNode *rn = rp->next;
        ListNode *rsave = rn->next;

        // swapping
        lp->next = rp->next;
        rn->next = rp;
        rp->next = rsave;
        return head;
    }
    else
    {
        // case-6
        // noOfNodeBtwRnL >= 1
        // ln and rn are adjacent nodes
        ListNode *lp = head;
        for (int i = 0; i < lpos - 2; i++)
            lp = lp->next;
        ListNode *ln = lp->next;

        ListNode *rp = head;
        for (int i = 0; i < rpos - 2; i++)
            rp = rp->next;
        ListNode *rn = rp->next;
        ListNode *rsave = rn->next;

        // swapping
        lp->next = rn;
        rn->next = ln->next;
        rp->next = ln;
        ln->next = rsave;
        return head;
    }
}