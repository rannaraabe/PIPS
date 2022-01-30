/*
Difficulty: Hard;

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Constraints:
1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std; 

void c_left(vector<int>& heights, int l[]){
    stack<pair<int, int>> s;
    s.push({0, -1});    // value, index
    
    for(int i=0; i<heights.size(); i++){
        if(heights[i] > s.top().first){
            l[i] = s.top().second;
            s.push({heights[i], i});
        } else {
            while(!s.empty() && heights[i] <= s.top().first) {
                s.pop();
            }
            
            l[i] = s.empty() ? -1 : s.top().second;
            s.push({heights[i], i});
        }
    }
}

void c_right(vector<int> heights, int r[]){
    reverse(heights.begin(), heights.end());
    c_left(heights, r);
    
    for(int i=0; i<heights.size(); i++){
        r[i] = heights.size()-r[i]-1;
    }
    
    reverse(r, r+heights.size());
}

int largestRectangleArea(vector<int>& heights) {
    // pelo menos 1 retangulo vai estar completo na area
    
    int r[heights.size()];
    int l[heights.size()];
    
    c_left(heights, l);
    c_right(heights, r);
    
    int best=0;
    for(int i=0; i<heights.size(); i++){
        int area = (r[i]-l[i]-1)*heights[i];
        best = max(area, best);
    }
    
    return best;
}
