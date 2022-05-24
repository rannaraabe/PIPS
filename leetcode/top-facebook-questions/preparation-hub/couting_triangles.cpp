/*
Difficulty: -;

Given a list of N triangles with integer side lengths, determine how many different triangles there are. Two triangles are considered to be the same if they can both be placed on the plane such that their vertices occupy exactly the same three points.

Constraints:
In some languages, arr is an Nx3 array where arr[i] is a length-3 array that contains the side lengths of the ith triangle. In other languages, arr is a list of structs/objects that each represent a single triangle with side lengths a, b, and c.
It's guaranteed that all triplets of side lengths represent real triangles.
All side lengths are in the range [1, 1,000,000,000]
1 <= N <= 1,000,000
*/

#include <bits/stdc++.h>
using namespace std;

struct sides{
  long long a;
  long long b;
  long long c;
};

int countDistinctTriangles(vector<sides> arr) {
  map<vector<long long>, int> freq;
  
  for(int i=0; i<arr.size(); i++){
    vector<long long> tri = {arr[i].a, arr[i].b, arr[i].c};
    sort(tri.begin(), tri.end());
    freq[tri]++;
  }
  
  return freq.size();
}

// complexity time: O(n)
