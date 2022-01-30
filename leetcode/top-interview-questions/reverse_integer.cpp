/*
Difficulty: Medium;

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Constraints:
-2^31 <= x <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std; 

int reverse(int x) {
    int aux = x;
    int reverse = 0;
    
    while(aux!=0){
        if(willOverflow(reverse)) return 0;
        reverse = reverse*10 + aux%10;
        aux/=10;           
    }
    
    return reverse;
}

bool willOverflow(int n){
    if(n > INT_MAX/10 || n < INT_MIN/10) return true;
    return false;
}