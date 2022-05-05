/*
Difficulty: Easy;

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Constraints:
1 <= s.length <= 5*10^4
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

#include <bits/stdc++.h>
using namespace std; 

void reverse(string &s, int l, int h){
    while(l <= h){
        swap(s[l], s[h]);
        l++;
        h--;
    }
}

string reverseWords(string s) {
    int start = 0;
    for(int end=0; end<s.length(); end++){
        if(s[end] == ' '){
            reverse(s, start, end-1);
            start = end+1;
        }
    }
    
    reverse(s, start, s.length()-1);
    return s;
}