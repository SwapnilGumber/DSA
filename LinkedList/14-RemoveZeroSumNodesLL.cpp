/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of ListNode objects.)
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

class Solution
{
public:
    void sanitizeMap(ListNode *curr, unordered_map<int, ListNode *> &mp, int csum)
    {
        int temp = csum;
        while (true)
        {
            temp += curr->val;
            if (temp == csum)
                break;
            mp.erase(temp);
            curr = curr->next;
        }
    }
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        if ((!head) || (!head->next && head->val == 0))
            return 0;
        unordered_map<int, ListNode *> mp;
        auto it = head;
        int csum = 0;
        while (it)
        {
            csum += it->val;
            if (csum == 0)
            {
                head = it->next;
                mp.clear();
            }
            else if (mp.find(csum) != mp.end())
            {
                sanitizeMap(mp[csum]->next, mp, csum);
                mp[csum]->next = it->next;
            }
            else
            {
                mp[csum] = it;
            }
            it = it->next;
        }
        return head;
    }
};