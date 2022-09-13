/*
Difficulty: Medium;
Phone Interview 

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n/2;
    
    while(left != right){
        int mid = left+(right-left)/2;
        
        if(nums[mid*2] == nums[1+mid*2]){
            left = mid+1;
        } else {
            right = mid;
        }
    }
    
    return nums[2*right];
}