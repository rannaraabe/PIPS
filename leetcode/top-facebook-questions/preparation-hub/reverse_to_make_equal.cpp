
/*
Difficulty: -;

Given two arrays A and B of length N, determine if there is a way to make A equal to B by reversing any subarrays from array B any number of times.

Constraints:
All integers in array are in the range [0, 1,000,000,000]
*/

#include <bits/stdc++.h>
using namespace std;

bool areTheyEqual(vector<int>& array_a, vector<int>& array_b){
  sort(array_a.begin(), array_a.end());
  sort(array_b.begin(), array_b.end());
  
  for(int i=0; i<array_a.size(); i++){
    if(array_a[i] != array_b[i]) return false;
  }
  
  return true;
}

// complexity time: O(n)