/*
Difficulty: Easy;

The height of a binary tree is the number of edges between the tree's root and its furthest leaf.

Constraints:
1 <= node.data[i] <= 20
1 <= n <= 20
*/

#include <bits/stdc++.h>
using namespace std; 

struct Node {
    int data;
    Node* left;
    Node* right;
};

int height(Node* root) {
    int h = 0;
    if(root->left!=NULL)
        h = 1+height(root->left);
        
    if(root->right!=NULL)
        h = 1+height(root->right);
    
    return h;
}