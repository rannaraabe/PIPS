/*
Difficulty: -;

Given a list of n integers arr[0..(n-1)], determine the number of different pairs of elements within it which sum to k.
If an integer appears in the list multiple times, each copy is considered to be different; that is, two pairs are considered different if one pair includes at least one array index which the other doesn't, even if they include the same values.

Constraints:
n is in the range [1, 100,000].
Each value arr[i] is in the range [1, 1,000,000,000].
k is in the range [1, 1,000,000,000].
*/

#include <bits/stdc++.h>
using namespace std;

int numberOfWays(vector<int>& arr, int k) {
  if(arr.size() == 0) return 0;
  
  map<int, int> freq;
  for(auto i : arr){
    freq[i]++;
  }
  
  int pairs = 0;
  for(int i=0; i<arr.size(); i++){
    pairs += freq[k - arr[i]];
    if(arr[i] == k-arr[i]){
      pairs--;
    }    
  }
  
  return pairs/2;
}

// complexity time: O(n)