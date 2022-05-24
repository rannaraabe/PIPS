/*
Difficulty: -;

We keep track of the revenue Facebook makes every day, and we want to know on what days Facebook hits certain revenue milestones. Given an array of the revenue on each day, and an array of milestones Facebook wants to reach, return an array containing the days on which Facebook reached every milestone.

Constraints:
revenues is a length-N array representing how much revenue FB made on each day (from day 1 to day N).
milestones is a length-K array of total revenue milestones.
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int target, vector<int> &prefixSum){
  int left = 0, right = prefixSum.size()-1;
  int possible = -1;
  
  while(left <= right){
    int mid = left+(right-left)/2;
    
    if(prefixSum[mid] < target){
      left = mid+1;
    } else {
      right = mid-1;
      possible = mid;
    }
  }
  
  return possible; // cara mais a esq que respeita ser >=
}

vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
  vector<int> prefixSum = {};
  int prefix = 0;
  for(int i=0; i<revenues.size(); i++){
    prefixSum.push_back(revenues[i]+prefix);
    prefix = prefixSum[i];
  }
  
  vector<int> ans = {};
  for(int i=0; i<milestones.size(); i++){
    ans.push_back(binarySearch(milestones[i], prefixSum)+1);
  }
  
  return ans;
}

// complexity time: O(n logn)