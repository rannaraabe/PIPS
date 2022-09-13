/*
Difficulty: Medium;
Phone Interview

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Constraints:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if(strs.empty()) return {};
    
    map<string, vector<string>> m;
    for(auto s : strs){
        string aux = s;
        sort(aux.begin(), aux.end());
        m[aux].push_back(s);
    }
    
    vector<vector<string>> ans;
    for(auto it=m.begin(); it != m.end(); it++){
        ans.push_back(it->second);
    }
    
    return ans;
}