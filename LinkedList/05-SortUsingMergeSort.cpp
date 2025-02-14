#include<bits/stdc++.h>
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

Node *mergeTwoLists(Node *list1, Node *list2)
    {
        Node *head = new Node(0);
        Node *curr = head;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->data <= list2->data)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1 != NULL)
            curr->next = list1;
        if (list2 != NULL)
            curr->next = list2;
    
        return head->next;
    }
    Node* split(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        Node* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head || !head->next) return head;
        Node* mid = split(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);
        return mergeTwoLists(left,right);
    }