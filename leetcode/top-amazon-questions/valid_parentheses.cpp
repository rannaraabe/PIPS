/*
Difficulty: Easy;
Phone Interview

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.
 
Constraints:
1 <= s.length <= 10^s4
s consists of parentheses only '()[]{}'.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    if(s.size() == 0 || s.size() == 1){
        return false;
    }
    
    stack<char> brackets;
    map<char, char> m;
    m[')'] = '(';
    m['}'] = '{';
    m[']'] = '[';
    
    for(auto c : s){
        if(c == '(' || c == '{' || c == '['){
            brackets.push(c);
        } else {
            if(brackets.size() == 0) return false;
            if(m[c] == brackets.top()){
                brackets.pop();
            } else {
                return false;
            }
        }
    }
    
    if(brackets.size()){
        return false;
    }
    
    return true;
}