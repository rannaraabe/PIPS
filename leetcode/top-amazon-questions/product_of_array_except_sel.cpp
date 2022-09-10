/*
Difficulty: Medium;
Phone Interview

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Constraints:
2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> pref(nums.size());
    vector<int> suf(nums.size());
    
    pref[0] = 1;
    for(int i=1; i<nums.size(); i++){
        pref[i] = pref[i-1]*nums[i-1];
    }
    
    suf[nums.size()-1] = 1;
    for(int i=nums.size()-2; i>=0; i--){
        suf[i] = suf[i+1]*nums[i+1];
    }
    
    vector<int> ans(nums.size());
    for(int i=0; i<nums.size(); i++){
        ans[i] = suf[i]*pref[i];
    }
    
    return ans;
}