/*
Difficulty: Medium;

Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.

Constraints:
1 <= q <= 10
2 <= length of s <= 100
s contains only lowercase letters in the range ascii[a-z].
*/

#include <bits/stdc++.h>
using namespace std; 

typedef map<char, int> freqTable;

int sherlockAndAnagrams(string s) {
    map<freqTable, int> freq;
    int ans = 0;
    
    for(int i = 0; i < s.size(); i++){
        freqTable ft;
        for(int j = i; j<s.size(); j++){
            ft[s[j]]++;
            freq[ft]++;
        }
    }
    
    for(pair<map<char, int>, int> i : freq){
        ans += (i.second*(i.second-1))/2;
    }
    
    return ans;
}
