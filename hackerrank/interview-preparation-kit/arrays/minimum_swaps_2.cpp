/*
Difficulty: Medium;

You are given an unordered array consisting of consecutive integers ∈ [1, 2, 3, ..., n] without any duplicates. You are allowed to swap any two elements. Find the minimum number of swaps required to sort the array in ascending order.

arr = [1, 2, 3, 4, 5, 6]
Perform the following steps:
i   arr                     swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]

It took 5 swaps to sort the array.

Constraints:
1 <= n <= 10^5
1 <= arr[i] <= n
*/

#include <bits/stdc++.h>
using namespace std; 

int minimumSwaps(vector<int> arr) {
    int min = 0;
    for(int i=0; i<arr.size(); i++){
        while(arr[i] != i+1){
            swap(arr[i], arr[arr[i]-1]);
            min++;
        }
    }
    return min;
}