/*
Difficulty: Medium;

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Constraints:
1 <= words.length <= 500
1 <= words[i] <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
*/

#include <bits/stdc++.h>
using namespace std; 

// Using vector
static bool comp(pair<int,string> A, pair<int,string> B){
    if(A.first > B.first)
        return true;
    else if(A.first == B.first)
        return A.second < B.second;
    return false;
}

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freq;
    for(int i=0; i<words.size(); i++)
        freq[words[i]]++;
    
    vector<pair<int, string>> bag;
    for(auto a : freq)
        bag.push_back({a.second, a.first});
    
    vector<string> ans = {};
    sort(bag.begin(), bag.end(), comp);
    
    for(int i=0; i<k; i++)
        ans.push_back(bag[i].second);
    
    return ans;
} 

// ================================

// Usign priority_queue: O(nlog(k))
struct Comp{
    bool operator()(pair<int, string> A, pair<int, string> B){
        if(A.first > B.first) return true;
        else if(A.first == B.first) return A.second < B.second;
        return false;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> freq;
    for(auto s : words) // O(n)
        freq[s]++;
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> pq;
    for(auto p : freq){
        pq.push({p.second, p.first});
        if(pq.size() > k) pq.pop();
    }

    vector<string> ans = {};
    while(!pq.empty()){ // O(k)
        ans.insert(ans.begin(), pq.top().second);
        pq.pop();
    }

    return ans;
}