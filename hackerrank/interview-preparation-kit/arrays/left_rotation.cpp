/*
Difficulty: Easy;

A left rotation operation on an array shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1,2,3,4,5], then the array would become [3,4,5,1,2]. Note that the lowest index item moves to the highest index in a rotation. This is called a circular array.
Given an array a of n integers and a number, d, perform d left rotations on the array. Return the updated array to be printed as a single line of space-separated integers.

Constraints:
1 <= n <= 10^5
1 <= d <= n
1 <= a[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std; 

// Solution 1
vector<int> rotLeft(vector<int> a, int d) {
    if(d == a.size()) return a;
    
    queue<int> q;
    for(int i : a){
        q.push(i);
    }
    
    for(int i=0; i<d; i++){
        int aux = q.front();
        q.pop();
        q.push(aux);
    }
    
    vector<int> result;
    while(!q.empty()){
        result.push_back(q.front());
        q.pop();
    }    
    return result;
}

// Solution 2
vector<int> rotLeft(vector<int> a, int d) {
    if(d == a.size()) return a;
    vector<int> b(a.size());

    for(int i=0; i<a.size(); i++){
          b[(i-d+a.size())%a.size()] = a[i];
    }
    return b;
}