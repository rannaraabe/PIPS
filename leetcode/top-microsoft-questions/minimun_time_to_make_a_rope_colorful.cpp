/*
Difficulty: Medium;
On-site Interview

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
Return the minimum time Bob needs to make the rope colorful.

Constraints:
n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int>& neededTime) {
    int ans = 0, i = 0, j = 0;
    
    while(i<neededTime.size() && j<neededTime.size()){
        int currTotal = 0, currMax = 0;
        while(j<neededTime.size() && colors[i] == colors[j]){
            currTotal += neededTime[j];
            currMax = max(neededTime[j], currMax);
            j++;
        }
        ans += currTotal-currMax;
        i = j;
    }
    
    return ans;
}