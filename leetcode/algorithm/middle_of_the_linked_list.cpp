/*
Difficulty: Easy;

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std; 


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* faster = head;
    ListNode* slower = head;
    
    while(faster != nullptr && faster->next != nullptr){
        faster = faster->next->next;
        slower = slower->next;
    }
    return slower;
}    