/*
Difficulty: Easy;

Given two strings, determine if they share a common substring. A substring may be as small as one character.

Constraints:
s1 and s2 consist of characters in the range ascii[a-z].
1 <= p <= 10
1 <= |s1|,|s2| <= 10^5
*/

#include <bits/stdc++.h>
using namespace std; 

string twoStrings(string s1, string s2) {
    map<char, bool> contains;
    for(char c : s1) contains[c] = true;
    
    for(char c : s2)
        if(contains[c]) return "YES";    
    return "NO";
}