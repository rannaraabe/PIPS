/*
Difficulty: Easy;

There is a large pile of socks that must be paired by color. Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.

Constraints:
1 <= n <= 100
1 <= ar[i] <= 100 where 0 <= 1 < n
*/

#include <bits/stdc++.h>
using namespace std; 

int sockMerchant(int n, vector<int> ar) {
    int count = 0;
    map <int, int> m;

    for(int i=0; i<n; i++)
        m[ar[i]]++;   
        
    for(auto a : m)
        count += a.second/2;
    
    return count;
}