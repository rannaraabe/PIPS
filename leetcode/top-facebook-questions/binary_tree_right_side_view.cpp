/*
Difficulty: Medium;

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void rightView(TreeNode* root, vector<int> &ans, int level){
    if(root == nullptr) return;
    
    if(ans.size() == level){
        ans.push_back(root->val);
    }
    
    rightView(root->right, ans, level+1);
    rightView(root->left, ans, level+1);
}

vector<int> rightSideView(TreeNode* root) {
    if(root == nullptr) return {};
    
    vector<int> ans = {};
    int level = 0;
    rightView(root, ans, level);
    
    return ans;
}