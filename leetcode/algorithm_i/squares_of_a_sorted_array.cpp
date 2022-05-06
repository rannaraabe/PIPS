/*
Difficulty: Easy;

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.
*/

#include <bits/stdc++.h>
using namespace std; 

vector<int> sortedSquares(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    vector<int> ans = {};
    
    while(left <= right){
        if(abs(nums[left]) > abs(nums[right])){
            ans.push_back(nums[left]*nums[left]);
            left++;
        } else {
            ans.push_back(nums[right]*nums[right]);
            right--;
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}