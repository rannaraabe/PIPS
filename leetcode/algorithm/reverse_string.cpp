/*
Difficulty: Easy;

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Constraints:
1 <= s.length <= 10^5
s[i] is a printable ascii character
*/

#include <bits/stdc++.h>
using namespace std; 

void reverseString(vector<char>& s) {
    for(int i=0; i<s.size()/2; i++){
        swap(s[i], s[(s.size()-1)-i]);
    }
}