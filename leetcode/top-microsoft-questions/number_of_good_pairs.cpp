/*
Difficulty: Easy;
On-site Interview

Given an array of integers nums, return the number of good pairs.
A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i; j<nums.size(); j++){
            if(nums[i] == nums[j] && i<j){
                ans++;
            }
        }
    }
    return ans;
}