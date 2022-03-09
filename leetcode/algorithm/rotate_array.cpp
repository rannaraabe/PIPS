/*
Difficulty: Medium;

Given an array, rotate the array to the right by k steps, where k is non-negative.

Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5
*/

#include <bits/stdc++.h>
using namespace std; 

void rotate(vector<int>& nums, int k) {
    vector<int> v = nums;
    for(int i=0; i<nums.size(); i++){
        nums[(i+k)%nums.size()] = v[i];
    }
}

// 0 1 2 3 4 5 6 
// 1 2 3 4 5 6 7
    
// 0+3%7 = 3%7 = 3 
// 1+3%7 = 4%7 = 4 
// 2+3%7 = 5%7 = 5
// 3+3%7 = 6%7 = 6 
// 4+3%7 = 7%7 = 0 
// 5+3%7 = 8%7 = 1 
// 6+3%7 = 9%7 = 2 

// 0 1 2 3 4 5 6
// 5 6 7 1 2 3 4