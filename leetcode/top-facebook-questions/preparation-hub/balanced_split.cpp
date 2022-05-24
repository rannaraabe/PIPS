/*
Difficulty: -;

Given an array of integers (which may include repeated integers), determine if there's a way to split the array into two subsequences A and B such that the sum of the integers in both arrays is the same, and all of the integers in A are strictly smaller than all of the integers in B.
Note: Strictly smaller denotes that every integer in A must be less than, and not equal to, every integer in B.

Constraints:
All integers in array are in the range [0, 1,000,000,000].
*/

#include <bits/stdc++.h>
using namespace std;

bool balancedSplitExists(vector<int>& arr){
  if(arr.size() == 0) return false;
  
  sort(arr.begin(), arr.end());
  bool split = false; 
  
  int left = 0, right = 0;
  int i = 0, j = arr.size()-1;
  while(i <= j){
    right += arr[j];
    j--;
    
    while(i <= j && left <= right){
      left += arr[i];
      i++;
    }
  }
  
  if(left == right && arr[i-1] < arr[j+1]) split = true;
  
  return split;
}

// complexity time: O(n^2)