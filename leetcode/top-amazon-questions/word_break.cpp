/*
Difficulty: Medium;

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Constraints:
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[256] = {nullptr};
    bool end = false;
};

void insert(TrieNode* node, string& str, int index=0){
    if(index == str.size()) return;
    if(node->children[str[index]] == nullptr) node->children[str[index]] = new TrieNode();    
    if(index+1 == str.size()) node->children[str[index]]->end = true; 

    insert(node->children[str[index]], str, index+1);
}

bool contains(TrieNode* node, string str, int index=0){
    if(index == str.size()) return node->end; // fui até o final e encontrei
    if(node->children[str[index]] == nullptr) return false; // não consigo mais andar
    
    return contains(node->children[str[index]], str, index+1);
}

TrieNode* root;
map<pair<TrieNode*, int>, bool> pd; // {estado}, resultado

// se é possível quebrar s em strings do wordDict
bool solve(TrieNode* node, string& str, int index){
    if(pd.count({node, index})) return pd[{node, index}];
    
    if(index == str.size()) return node->end;
    
    bool b1 = false, b2 = false;
    if(node->children[str[index]] != nullptr) {
        b1 = solve(node->children[str[index]], str, index+1);
    }
    
    if(node->end && root->children[str[index]]){
        b2 = solve(root->children[str[index]], str, index+1);
    }
    
    pd[{node, index}] = b1 || b2;
    return b1 || b2;
}

// 10^4 nós
// 300 indexes
bool wordBreak(string s, vector<string>& wordDict) {
    TrieNode* trie = new TrieNode();
    root = trie;
    
    for(auto word : wordDict){
        insert(trie, word);
    }
    
    return solve(trie, s, 0);
}