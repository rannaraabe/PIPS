/*
Difficulty: Medium;

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <bits/stdc++.h>
using namespace std; 

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // if(l1->val == 0 && l1->next == NULL && l2->val == 0 && l2->next == NULL){
    //     return new ListNode(0);
    // }
    return recursive(l1, l2, 0);
}
    
ListNode* recursive(ListNode* l1, ListNode* l2, int b){
    int v1 = getVal(l1);
    int v2 = getVal(l2);
    
    if(!l1 && !l2 && b==0) return NULL;
    
    ListNode* next1 = getNext(l1);
    ListNode* next2 = getNext(l2);
    
    ListNode* s = new ListNode();
    s->next = recursive(next1, next2, (v1+v2+b)/10);
    s->val = (v1+v2+b)%10;
    
    return s;   
}

int getVal(ListNode* l){
    if(l == NULL) return 0;
    return l->val;
}

ListNode* getNext(ListNode* l){
    if(l == NULL) return NULL;
    return l->next;
}