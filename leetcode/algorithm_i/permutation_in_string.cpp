/*
Difficulty: Medium;

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Constraints:
1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        else if(s1 == s2) return true;
        
        map<int, int> m_s1;
        map<int, int> m_s2;
        for(int i=0; i<s1.size(); i++){
            m_s1[s1[i]-'a']++;
            m_s2[s2[i]-'a']++;
        }
        
        int count = 0;
        for(int i=0; i<26; i++){
            if(m_s1[i] == m_s2[i]) count++;
        }
    
        for(int i=0; i<=s2.size()-s1.size(); i++){
            int r = s2[i+s1.size()]-'a', l = s2[i]-'a';
            if(count == 26) return true;
            
            m_s2[r]++;
            if(m_s2[r] == m_s1[r]) count++;
            else if(m_s2[r] == m_s1[r]+1) count--;
            m_s2[l]--;
            if(m_s2[l] == m_s1[l]) count++;
            else if(m_s2[l] == m_s1[l]-1) count--;
        }        
        return count==26;
    }