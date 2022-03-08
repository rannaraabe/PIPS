/*
Difficulty: Easy;

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    int ans = 0;

    if(nums.back() < target) return nums.size();
    
    while(left <= right){
        int pivot = left+(right-left)/2;
        
        if(nums[pivot] == target){
            return pivot;
        }
        if(nums[pivot] > target){
            right = pivot-1;
            ans = pivot;
        } else {
            left = pivot+1;
        }
    }
    
    return ans;
}