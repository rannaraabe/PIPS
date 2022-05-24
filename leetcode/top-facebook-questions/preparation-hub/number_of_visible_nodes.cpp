/*
Difficulty: -;

There is a binary tree with N nodes. You are viewing the tree from its left side and can see only the leftmost nodes at each level. Return the number of visible nodes.
Note: You can see only the leftmost nodes, but that doesn't mean they have to be left nodes. The leftmost node at a level could be a right node.

Constraints:
The root node of a tree, where the number of nodes is between 1 and 1000, and the value of each node is between 0 and 1,000,000,000
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data; 
  Node* left ; 
  Node* right; 
  Node() {
    data = 0; 
    left = NULL; 
    right = NULL; 
  }
  Node(int data) {
    this->data = data; 
    this->left = NULL; 
    this->right = NULL; 
  }
};

void dfs(Node* root, int &visibleNodes, int level){
  if(root == nullptr) return;
  
  if(visibleNodes == level){
    visibleNodes++;
  }
  
  dfs(root->right, visibleNodes, level+1);
  dfs(root->left, visibleNodes, level+1);
}

int visibleNodes(Node* root) {
  if(root == nullptr) return 0;
  
  int visibleNodes = 0;
  dfs(root, visibleNodes, 0);
  return visibleNodes;
}
