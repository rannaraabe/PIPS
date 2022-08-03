/*
Difficulty: Medium;

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(int v, vector<vector<int>> &adj, vector<int> &vis){
    if(adj[v].empty()) return 1;
    if(vis[v]) return vis[v];
    
    // maximo n passos
    int ans = 1;
    for(auto n : adj[v]){
        ans = max(ans, dfs(n, adj, vis)+1);
    }
    vis[v] = ans;
    return ans;
}


bool match(string &a, string &b){
    if(a.size() != b.size()+1) return false;
    
    int pref = 0, suf = 0;
    for(int i=0; i<b.size(); i++){
        if(a[i]==b[i]) {
            pref++;
        } else {
            break;
        }
    }
    
    for(int i=b.size()-1; i>=pref; i--){
        if(a[i+1]==b[i]) {
            suf++;
        } else {
            break;
        }
    }       
    
    return pref+suf == a.size()-1;
}

int longestStrChain(vector<string>& words) {
    vector<vector<int>> adj(words.size());
    for(int i=0; i<words.size(); i++){
        for(int j=0; j<words.size(); j++){
            if(match(words[i], words[j])){
                adj[i].push_back(j);
                // cout << "words[i] " << words[i] << " , words[j] = " << words[j] << endl;
            }
        }
    }
    
    int ans = 0;
    vector<int> vis(words.size(), 0);
    for(int i=0; i<words.size(); i++){
        if(!vis[i]){
            // n dfs's
            ans = max(ans, dfs(i, adj, vis));
        }
    }        
    return ans;
}