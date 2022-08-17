/*
Difficulty: Hard;

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s_1 -> s_2 -> ... -> s_k such that:

Every adjacent pair of words differs by a single letter.
Every s_i for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
s_k == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {        
    // BFS: the idea is simpy to start from the beginWord, then visit its neighbors, then the non-visited neighbors of its neighbors until we arrive at the endWord
    // I connect with someone who has a different letter than me
    
    set<string> words, todo;
    queue<string> q;
    int ans = 0;
    
    for(auto s : wordList){
        words.insert(s);
    }
    
    todo.insert(beginWord);
    q.push(beginWord);
    
    while(!q.empty()){
        int n = q.size();
        ans++;
        for(int i=0; i<n; i++){
            string s = q.front();
            if(s == endWord) return ans;
            q.pop();
            
            string aux;
            for(int j=0; j<s.size(); j++){
                aux = s;
                for(int k='a'; k<='z'; k++){
                    aux[j] = k;
                    
                    if(words.count(aux) && !todo.count(aux)){
                        q.push(aux);
                        todo.insert(aux);
                    }
                }
            }
        }
    }
    
    return 0;
}