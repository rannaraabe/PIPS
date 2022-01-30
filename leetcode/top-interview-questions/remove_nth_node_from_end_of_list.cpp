/*
Difficulty: Medium;

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

#include <bits/stdc++.h>
using namespace std; 

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = walkN(head, n);
    ListNode* slow = head;
    
    if(fast==nullptr){
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }
    
    while(fast->next!=nullptr){           
        slow = slow->next;
        fast = fast->next;
    }
    
    ListNode* node = slow->next;
    slow->next = slow->next->next;
    delete node;
    
    return head;
}

ListNode* walkN(ListNode* head, int n){
    int cont = 0;
    while(head!=nullptr){
        if(cont == n){
            return head;
        }
        cont++;
        head = head->next;
    }
    return nullptr;
}