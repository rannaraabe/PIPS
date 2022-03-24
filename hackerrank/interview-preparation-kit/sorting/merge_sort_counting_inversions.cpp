/*
Difficulty: Hard;

In an array, arr, the elements at indices i and j (where i<j) form an inversion if arr[i] > arr[j]. In other words, inverted elements arr[i] and arr[j] are considered to be "out of order". To correct an inversion, we can swap adjacent elements.

Constraints:
1 <= d <= 15
1 <= n <= 10^5
1 <= arr[i] <= 10^7
*/

#include <bits/stdc++.h>
using namespace std; 

long mergeSort(vector<int> &a, int low, int high){
    int n = high - low;
    if (n <= 1) return 0;

    int mid = low + n / 2;

    int swapsLeft = mergeSort(a, low, mid);
    int swapsRight = mergeSort(a, mid, high);
    long swaps = 0;

    int temp[n];
    int i = low;
    int j = mid;
    for (int k = 0; k < n; k++){
        if (i == mid){
            temp[k] = a[j++];
        }
        else if (j == high){
            temp[k] = a[i++];
        }
        else if (a[i] > a[j]){
            temp[k] = a[j++];
            swaps += mid - i;
        }
        else{
            temp[k] = a[i++];
        }
    }

    for (int k = 0; k < n; k++){
        a[low + k] = temp[k];
    }

    return swapsLeft + swapsRight + swaps;
}

long countInversions(vector<int> a) {
    return mergeSort(a, 0, a.size());
}