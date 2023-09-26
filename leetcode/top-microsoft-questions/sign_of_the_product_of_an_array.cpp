/*
Difficulty: Easy;

There is a function signFunc(x) that returns:
1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.

You are given an integer array nums. Let product be the product of all values in the array nums. Return signFunc(product).

Constraints:
1 <= nums.length <= 1000
-100 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

int arraySign(vector<int>& nums) {
    int product = 0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0) return 0;
        if(nums[i] < 0) product++;
    }
    
    if(product%2 != 0) return -1;

    return 1;
}