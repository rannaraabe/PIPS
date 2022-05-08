/*
Difficulty: Medium;

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋^th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 
Constraints:
The number of nodes in the list is in the range [1, 10^5].
1 <= Node.val <= 10^5
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

ListNode* deleteMiddle(ListNode* head) {
    ListNode* faster = head;
    ListNode* slower = head;
    ListNode* prev = nullptr;
    
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    
    while(faster != nullptr && faster->next != nullptr){
        faster = faster->next->next;
        prev = slower;
        slower = slower->next;
    }
    
    prev->next = slower->next;
    delete slower;        
    
    return head;
}