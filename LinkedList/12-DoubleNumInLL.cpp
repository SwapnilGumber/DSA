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

void solve(ListNode *head, int &carry)
{
    if (!head)
        return;
    solve(head->next, carry);

    // 1 case
    int product = 2 * (head->val) + carry;
    head->val = product % 10;
    carry = product / 10;
}
ListNode *doubleIt(ListNode *head)
{
    int carry = 0;
    solve(head, carry);
    if (carry)
    {
        ListNode *newNode = new ListNode(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}