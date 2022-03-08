/*
Difficulty: Easy;

Given an array of integers, sort the array in ascending order using the Bubble Sort algorithm above. Once sorted, print the following three lines:

1. Array is sorted in numSwaps swaps., where  is the number of swaps that took place.
2. First Element: firstElement, where  is the first element in the sorted array.
3. Last Element: lastElement, where  is the last element in the sorted array.

Constraints:
2 <= n <= 600
1 <= a[i] <= 2*10^6
*/

#include <bits/stdc++.h>
using namespace std; 

void countSwaps(vector<int> a) {
    int numSwaps = 0;
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.size()-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                numSwaps++;
            }
        }
    }
    int firstElement = a[0];
    int lastElement = a[a.size()-1];
    
    cout << "Array is sorted in " << numSwaps << " swaps." << endl;
    cout << "First Element: " << firstElement << endl;
    cout << "Last Element: " << lastElement << endl;
}