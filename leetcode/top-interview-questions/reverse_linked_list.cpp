/*
Difficulty: Easy;

Given the head of a singly linked list, reverse the list, and return the reversed list.

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
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

ListNode* reverseList(ListNode* head) {
    ListNode* new_head = NULL;
    while(head != NULL){
        ListNode* node = new ListNode(head->val, new_head);
        new_head = node;
        head = head->next;
    }
    return new_head;
}