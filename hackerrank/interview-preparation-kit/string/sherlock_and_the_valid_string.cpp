/*
Difficulty: Medium;

Sherlock considers a string to be valid if all characters of the string appear the same number of times. It is also valid if he can remove just 1 character at 1 index in the string, and the remaining characters will occur the same number of times.
Given a string s, determine if it is valid. If so, return YES, otherwise return NO.

Constraints:
1 <= |s| <= 10^5
Each character s[i] ∈ ascii[a-z].
*/

#include <bits/stdc++.h>
using namespace std; 

string isValid(string s) {
    // aaaabbcc
    // a:4 b:2 c:2
    // 4:1 2:2
    
    // aabbcd
    // a:2 b:2 c:1 d:1
    // 2:2 1:2
    
    if(s.size() <= 1) return "YES";
    
    map<char, int> freq;
    for(int i=0; i<s.size(); i++) freq[s[i]]++;
    
    map<int, int> freqfreq;
    for(auto it=freq.begin(); it != freq.end(); it++)
        freqfreq[it->second]++;
    
    int max = 0, balance = 0;
    for(auto it=freqfreq.begin(); it != freqfreq.end(); it++){
        if(it->second > max){
            max = it->second;
            balance = it->first;
        }
    }    
    
    int ans = 0, count = 0;
    for(auto it = freq.begin(); it != freq.end(); it++){
        if(it->second == 1 || it->second == balance-1 || it->second == balance+1){
            ans++; //count of character 1 more or less than balance factor
        } else if(abs(it->second-balance) > 0)
            count++; //count of character that can't be balanced
    }
    
    if(ans <=1 && count == 0) return "YES";
    return "NO";
}