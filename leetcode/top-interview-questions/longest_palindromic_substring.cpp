/*
Difficulty: Medium;

Given a string s, return the longest palindromic substring in s.

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <bits/stdc++.h>
using namespace std; 

string longestPalindrome(string s) {
    string palin = ""; 
    int len = 0;
    
    for(int mid=0; mid<s.length(); mid++){
        for(int x=0; mid-x>=0 && mid+x<s.length(); x++){
            if(s[mid-x] != s[mid+x]) break;
            
            int tam =2*x+1;
            if(tam>len){
                len = tam;
                palin = s.substr(mid-x, tam);
            }
        }
    }
    
    for(int mid=0; mid<s.length()-1; mid++){
        for(int x=1; mid-x+1>=0 && mid+x<s.length(); x++){
            if(s[mid-x+1] != s[mid+x]) break;
            
            int tam =2*x;
            if(tam>len){
                len = tam;
                palin = s.substr(mid-x+1, tam);
            }
        }
    }
    
    return palin;
}