
/*
Difficulty: Easy;

The absolute difference is the positive difference between two values a and b, is written |a-b| or |b-a| and they are equal.
If a=3 and b=2, |3-2| = |2-3| = 1. Given an array of integers, find the minimum absolute difference between any two elements in the array.

Constraints:
2 <= n <= 10^5
-10^9 <= arr[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

int minimumAbsoluteDifference(vector<int> arr) {
    int ans = INT_MAX;
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<arr.size()-1; i++){
        int left = i, right = i+1;
        int diff = abs(arr[left]-arr[right]);
        ans = min(diff, ans);
    }
    
    return ans;
}

