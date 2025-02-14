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

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    vector<int> ans = {-1, -1}; // minDist, maxDist
    ListNode *prev = head;
    ListNode *curr = head->next;
    ListNode *nextNode = head->next->next;
    if ((!head) || (!curr) || (!nextNode))
        return ans;

    vector<int> cp;
    int i = 2;
    while (nextNode)
    {
        if ((prev->val < curr->val && curr->val > nextNode->val) || (prev->val > curr->val && curr->val < nextNode->val))
        {
            cp.push_back(i);
        }
        i++;
        prev = curr;
        curr = nextNode;
        nextNode = nextNode->next;
    }
    int n = cp.size();
    if (n < 2)
        return ans;

    int minDist = INT_MAX;
    ans[1] = cp[n - 1] - cp[0];
    for (int i = 0; i < n - 1; i++)
    {
        minDist = min(minDist, cp[i + 1] - cp[i]);
    }
    ans[0] = minDist;
    return ans;
}