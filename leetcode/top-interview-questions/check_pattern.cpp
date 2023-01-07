/*
Difficulty: Medium;

Given an input string and a pattern, check if characters in the input string follows the same order as determined by characters present in the pattern.
Assume there won’t be any duplicate characters in the pattern.

Ideia:
For every pair (x, y) of consecutive characters in the pattern string, we find the last occurrence of x and first occurrence of y in the input string.
If last occurrence of character x is after first occurrence of character y for any pair, we return false.
Checking for every pair of consecutive characters in the pattern string will suffice.
*/

#include <bits/stdc++.h>
using namespace std; 

bool checkPattern(string str, string pattern) { // O(n)
    map<char, int> m;
    int order = 1;
    for(int i=0; i<pattern.size(); i++){
        m[pattern[i]] = order;
        order++;
    }

    int last_order = -1;
    for(int i=0; i<str.size(); i++){
        if(m.find(str[i]) != m.end()){
            if(m[str[i]] < last_order) return false;
            last_order = m[str[i]];
        }
    }

    return true;
}
