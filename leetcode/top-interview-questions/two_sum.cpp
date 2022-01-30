/*
Difficulty: Easy;

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Constraints:
2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.
*/

#include <bits/stdc++.h>
using namespace std; 

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> asn;
    unordered_map<int, int> m;
    
    for(int i=0; i<nums.size(); i++){
        if(m.find(target-nums[i]) != m.end()){
            asn.push_back(i);
            asn.push_back(m[target-nums[i]]);
            return asn;
        }
        m[nums[i]] = i;
    }
    
    return asn;
}