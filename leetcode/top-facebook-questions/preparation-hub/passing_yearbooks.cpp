
/*
Difficulty: -;

There are n students, numbered from 1 to n, each with their own yearbook. They would like to pass their yearbooks around and get them signed by other students.
You're given a list of n integers arr[1..n], which is guaranteed to be a permutation of 1..n (in other words, it includes the integers from 1 to n exactly once each, in some order). The meaning of this list is described below.
Initially, each student is holding their own yearbook. The students will then repeat the following two steps each minute: Each student i will first sign the yearbook that they're currently holding (which may either belong to themselves or to another student), and then they'll pass it to student arr[i-1]. It's possible that arr[i-1] = i for any given i, in which case student i will pass their yearbook back to themselves. Once a student has received their own yearbook back, they will hold on to it and no longer participate in the passing process.
It's guaranteed that, for any possible valid input, each student will eventually receive their own yearbook back and will never end up holding more than one yearbook at a time.
You must compute a list of n integers output, whose element at i-1 is equal to the number of signatures that will be present in student i's yearbook once they receive it back.

Constraints:
n is in the range [1, 100,000].
Each value arr[i] is in the range [1, n], and all values in arr[i] are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> findSignatureCounts(vector <int> arr) {
  int n = arr.size();
  vector<int> ans(n,0);
  
  for(int i=1; i<=n; i++){
    int bookOwner = i;
    int curr = i;
    do {
      ans[bookOwner-1] += 1;
      curr = arr[curr-1];
    } while(curr != bookOwner);
  }
  
  return ans;
}

// complexity time: O(n)