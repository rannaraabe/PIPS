/*
Difficulty: -;

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool recursivePalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            j--;
            i++;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1, removed = 0;
        while(i < j){
            if(s[i] != s[j])
                return recursivePalindrome(s, i+1, j) || recursivePalindrome(s, i, j-1);
            j--;
            i++;
        }
        
        return true;
    }