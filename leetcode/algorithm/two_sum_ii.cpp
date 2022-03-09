/*
Difficulty: Medium;

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Constraints:
2 <= numbers.length <= 3 * 10^4
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
*/

#include <bits/stdc++.h>
using namespace std; 

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    int left = 0, right = numbers.size()-1;
    
    while(left <= right){
        if(numbers[left]+numbers[right] == target){
            ans.push_back(left+1);
            ans.push_back(right+1);
            break;
        }
        if(numbers[left]+numbers[right] > target){
            right--;
        } else {
            left++;
        }
    }
    
    return ans;
}
