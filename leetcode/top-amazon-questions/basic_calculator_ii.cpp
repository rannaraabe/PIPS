/*
Difficulty: Medium;

Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2^31, 2^31 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Constraints:
1 <= s.length <= 3 * 10^5
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 2^31 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    s += '+';
    stack<int> stk; 
    
    long long int ans = 0, curr = 0;
    char sign = '+'; 
    
    for(auto c : s){
        if(isdigit(c))
            curr = curr*10 + (c-'0');
        else if(c == ' ')
            continue;
        else {                
            if(sign == '+')
                stk.push(curr);
            else if(sign == '-')
                stk.push(curr*(-1));
            else if(sign == '*'){
                int num = stk.top(); stk.pop();  
                stk.push(num*curr);
            } else if(sign == '/'){
                int num = stk.top();stk.pop(); 
                stk.push(num/curr);
            }
            
            curr = 0; 
            sign = c; 
        }
        
    }
    
    while(stk.size()){
        ans += stk.top(); stk.pop();
    }
        
    return ans;        
}