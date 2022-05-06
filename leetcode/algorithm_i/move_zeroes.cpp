/*
Difficulty: Easy;

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note: that you must do this in-place without making a copy of the array.

Constraints:
1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std; 

void moveZeroes(vector<int>& nums) {
    for(int i=nums.size()-1; i>=0; i--){
        if(nums[i]==0){
            for(int j=i; j<nums.size()-1; j++){
                swap(nums[j], nums[j+1]);
            }
        } else continue;
    }
}

// 0 1 0 3 12
// 0 1 3 12 0
// 1 3 12 0 0


// outro caso:
// 0 0 1
// 0 1 0
// 1 0 0