/*
Difficulty: Easy;

Given an integer n, return any array containing n unique integers such that they add up to 0.

Constraints:
1 <= n <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n) {
    vector<int> ans;
    if(n%2==1) ans.push_back(0);
    
    if(n>=2) {
        n/=2;
        for(int i=1; i<=n; i++){
            ans.push_back(i);
            ans.push_back(i*(-1));
        }
    }

    return ans;
}