/*
Difficulty: Medium;

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Constraints:
1 <= k <= points.length <= 10^4
-10^4 < xi, yi < 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// Solution using min_heap
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>, vector<vector<int>>, comp> pq(points.begin(), points.end());
    vector<vector<int>> ans;
    
    // O(n*k*logn)
    // O(n) building a min heap for all the points
    // O(k*logn) fetching the top K points from the heap 
    for(int i=0; i<k; i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
}

struct comp{
    bool operator()(vector<int>& a, vector<int>& b){
        return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
    }
};