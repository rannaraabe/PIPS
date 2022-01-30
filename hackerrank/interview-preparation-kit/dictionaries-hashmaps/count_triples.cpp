/*
Difficulty: Medium;

You are given an array and you need to find number of tripets of indices (i,j,k) such that the elements at those indices are in geometric progression for a given common ratio r and i<j<k.

Constraints:
1 <= n <= 10^5
1 <= r <= 10^9
1 <= arr[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std; 

long long countTriplets(vector<long> arr, long r) {
    map <int, long long> pref;
    map <int, long long> suff;
    long long ans = 0;
    
    for(auto i : arr){
        suff[i]++;
    }
    
    for(int i=0; i<arr.size(); i++){
        suff[arr[i]]--;
        if(arr[i]%r == 0){
            ans += pref[arr[i]/r]*suff[arr[i]*r];
        }
        pref[arr[i]]++;
    }
    
    return ans;
}
