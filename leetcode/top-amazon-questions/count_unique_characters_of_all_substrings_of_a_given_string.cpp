/*
Difficulty: Hard;

Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

Constraints:
1 <= s.length <= 10^5
s consists of uppercase English letters only.
*/

#include <bits/stdc++.h>
using namespace std;

int uniqueLetterString(string s) {
    int n = s.size();
    vector<int> prev(n);
    vector<int> next(n);
    vector<int> prevPos(256, -1);
    vector<int> nextPos(256, n);
    
    for(int i=0; i<n; i++){
        prev[i] = prevPos[s[i]];
        prevPos[s[i]] = i;
    }
    
    for(int i=n-1; i>=0; i--){
        next[i] = nextPos[s[i]];
        nextPos[s[i]] = i;
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += (next[i]-i)*(i-prev[i]);
    }
    
    return ans;
}