/*
Difficulty: Hard;

The appeal of a string is the number of distinct characters found in the string.

For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.
Given a string s, return the total appeal of all of its substrings.

A substring is a contiguous sequence of characters within a string.

Constraints:
1 <= s.length <= 10^5
s consists of uppercase English letters only.
*/

#include <bits/stdc++.h>
using namespace std;

long long appealSum(string s) {
    int n = s.size();
    vector<int> prev(n);
    vector<int> prevPos(256, -1);
    
    for(int i=0; i<n; i++){
        prev[i] = prevPos[s[i]];
        prevPos[s[i]] = i;
    }
    
    long long ans = 0;
    for(long long i=0; i<n; i++){
        ans += (n-i)*(i-prev[i]);
    }
    
    return ans;
}