
/*
Difficulty: -;

You are given an array arr of N integers. For each index i, you are required to determine the number of contiguous subarrays that fulfill the following conditions:
- The value at index i must be the maximum element in the contiguous subarrays, and
- These contiguous subarrays must either start from or end on index i.

Constraints:
Array arr is a non-empty list of unique integers that range between 1 to 1,000,000,000
Size N is between 1 and 1,000,000
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> countSubarrays(vector <int> arr) {
  int n = arr.size();
  vector<int> ans(n, 0);
  
  for(int i=0; i<n; i++){
    int frontCount = 0, backCount = 0;
    
    for(int front=i; front<n-1; front++){
      if(arr[front+1] > arr[i]) break;
      frontCount++;
    }
    
    for(int back=i; back>0; back--){
      if(arr[back-1] > arr[i]) break;
      backCount++;
    } 
      
    ans[i] += frontCount+backCount+1;    
  }
  
  return ans;
}

// complexity time: O(n^2)?