/*
Difficulty: Medium;
Phone Interview 

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
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

vector<vector<int>> ans;
vector<vector<int>> levelOrder(TreeNode* root) {
    build(root, 0);
    return ans;
}

void build(TreeNode* root, int depth){
    if(root == nullptr) return;
    if(ans.size() == depth){
        ans.push_back(vector<int>());
    }
    
    ans[depth].push_back(root->val);
    build(root->left, depth+1);
    build(root->right, depth+1);
}