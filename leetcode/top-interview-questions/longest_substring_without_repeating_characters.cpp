/*
Difficulty: Medium;

Given a string s, find the length of the longest substring without repeating characters.

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std; 

int lengthOfLongestSubstring(string s) {
    int k = 0, maior = 0;
    
    for(int i=0; i<s.size(); i++){
        for(int j=k; j<i; j++){
            if(s[j]==s[i]) k = j+1;
        }
        maior = max(maior, i+1-k);
    }
    
    return maior;
}