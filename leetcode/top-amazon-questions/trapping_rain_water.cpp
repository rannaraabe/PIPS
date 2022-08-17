/*
Difficulty: Hard;

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Constraints:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    if(height.size() == 1) return 0;
    
    stack<int> s;
    s.push(height.back());
    for(int i=height.size()-2; i>=0; i--){
        if(height[i] >= s.top()) s.push(height[i]);
    }   
    
    int maxBar = 0, ans = 0;
    for(int i=0; i<height.size(); i++){
        if(height[i] > maxBar){
            maxBar = height[i];
        }
        
        if(height[i] == s.top()){
            s.pop();
        } else {
            ans += min(maxBar, s.top())-height[i];
        }
    }
    
    return ans;
}