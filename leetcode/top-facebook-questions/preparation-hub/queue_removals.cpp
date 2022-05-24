/*
Difficulty: -;

You're given a list of n integers arr, which represent elements in a queue (in order from front to back). You're also given an integer x, and must perform x iterations of the following 3-step process:
1. Pop x elements from the front of queue (or, if it contains fewer than x elements, pop all of them)
2. Of the elements that were popped, find the one with the largest value (if there are multiple such elements, take the one which had been popped the earliest), and remove it
3. For each one of the remaining elements that were popped (in the order they had been popped), decrement its value by 1 if it's positive (otherwise, if its value is 0, then it's left unchanged), and then add it back to the queue

Compute a list of x integers output, the ith of which is the 1-based index in the original array of the element which had been removed in step 2 during the ith iteration.

Constraints:
x is in the range [1, 316].
n is in the range [x, x*x].
Each value arr[i] is in the range [1, x]
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> findPositions(vector <int> arr, int x) {
  queue<pair<int, int>> q, qRemaining;
  for(int i=0; i<arr.size(); i++){
    q.push({arr[i], i+1});
  }
  
  vector<int> ans;  
  for(int i=0; i<x; i++){
    int elementsPop = min(x, (int)q.size());
    pair<int, int> max = {-1, 0};
    for(int j=0; j<elementsPop; j++){
      auto value = q.front();
      if(value.first > max.first){
        max = value;
      }
      qRemaining.push(value);
      q.pop();
    }
    
    ans.push_back(max.second);
    
    while(!qRemaining.empty()){
      auto value = qRemaining.front();
      qRemaining.pop();
      
      if(value != max){ // não adiciono o maior valor, passo 2
        if(value.first > 0) value.first--;
        q.push(value);    
      }
    }
  }
  
  return ans;
}