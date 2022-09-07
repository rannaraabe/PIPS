
/*
Difficulty: Medium;

You will be given a list of integers, arr, and a single integer k. You must create an array of length k from elements of arr such that its unfairness is minimized. Call that array arr'.

Unfairness of an array is calculated as: max(arr') - min(arr')
Where:
- max denotes the largest integer in arr'
- min denotes the smallest integer in arr'

Constraints:
2 <= n <= 10^5
2 <= k <= n
0 <= arr[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

int maxMin(int k, vector<int> arr) {
    // [1 4 7 2] k=2
    // arr' = [2 1] = 1
    
    // [1 2 4 7] 
    // 1 2 = 1
    // 2 4 = 2
    // 4 7 = 3
    
    int min = INT_MAX;
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<=arr.size()-k; i++){
        if(arr[i+k-1] - arr[i] < min){
            min = arr[i+k-1] - arr[i];
        }   
    }
    
    return min;
}
