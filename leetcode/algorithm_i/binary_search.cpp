/*
Difficulty: Easy;

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Constraints:
1 <= nums.length <= 10^4
-10^4 < nums[i], target < 10^4
All the integers in nums are unique.
nums is sorted in ascending order.
*/

#include <bits/stdc++.h>
using namespace std; 

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    
    while(left <= right){
        int index = (left+right)/2;
        
        if(nums[index] == target){
            return index;
        }
        if(nums[index] > target){
            right = index-1;
        } else {
            left = index+1;
        }
    }
    return -1;
}
