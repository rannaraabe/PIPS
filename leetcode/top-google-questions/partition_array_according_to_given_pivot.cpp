/*
Difficulty: Medium;

You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

- Every element less than pivot appears before every element greater than pivot.
- Every element equal to pivot appears in between the elements less than and greater than pivot.
- The relative order of the elements less than pivot and the elements greater than pivot is maintained.
    - More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. For elements less than pivot, if i < j and nums[i] < pivot and nums[j] < pivot, then pi < pj. Similarly for elements greater than pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.

Return nums after the rearrangement.

Constraints:
1 <= nums.length <= 10^5
-10^6 <= nums[i] <= 10^6
pivot equals to an element of nums.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    // O(1) de memória extra sem preservar a ordem
    int pivots = 0;
    int last = nums.size()-1;

    for(int i=0; i<last; i++){
        while(nums[i] == pivot) {
            pivots++;
            swap(nums[i], nums[last]);
            last--;
        }
    }

    for(int i=0; i<last; i++){
        while(nums[i] > pivot){
            swap(nums[i], nums[last]);
            last--;
        }
    }

    last = nums.size()-1;
    for(int i=0; i<last; i++){
        if(nums[i] > pivot){
            swap(nums[i], nums[last]);
            last--;
        }
    }

    return nums;

    // O(n) de memória extra preservando a ordem
    vector<int> less;
    vector<int> greater;
    int pivots;
    
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == pivot) pivots++;
        else if(nums[i] < pivot) less.push_back(nums[i]);
        else if(nums[i] > pivot) greater.push_back(nums[i]);
    }
    
    vector<int> ans;
    for(auto i : less) ans.push_back(i);
    for(int i=0; i<pivots; i++) ans.push_back(pivot);
    for(auto i : greater) ans.push_back(i);
    
    return ans;
}