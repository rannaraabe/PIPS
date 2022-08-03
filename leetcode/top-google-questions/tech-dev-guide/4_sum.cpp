/*
Difficulty: Medium;

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Constraints:
1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if(nums.empty()) 
        return {};
    
    vector<vector<int>> ans = {};
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            
            // preciso encontrar exatamente target_curr
            int target_curr = target-nums[i]-nums[j];
            
            int l = j+1, r = nums.size()-1;
            while(l < r){
                int target_sum = nums[l]+nums[r];
                if(target_sum < target_curr){
                    l++;
                } else if(target_sum > target_curr){
                    r--;
                } else {    // sum == curr
                    int left = nums[l]; 
                    int right = nums[r];
                    ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                    
                    // para não dar tle, preciso loop:
                    while(l < r && nums[l] == left)
                        l++;
                    while(r < l && nums[r] == right)
                        r++;
                }
            }
            
            // sequencia de numeros repetidos eu só preciso ver 1x
            // assim nao repito a resposta no ans
            while(j+1 < nums.size() && nums[j] == nums[j+1]) 
                j++;
        }
        while(i+1 < nums.size() && nums[i] == nums[i+1])
            i++;
    }
    return ans;
}