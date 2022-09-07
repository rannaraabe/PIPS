/*
Difficulty: Easy;

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

Constraints:
1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<int>&a, vector<int>&b){
    return a[1] > b[1];    
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), comp);      
        
    int ans = 0;
    for(int i=0; i<boxTypes.size(); i++){
        if(truckSize-boxTypes[i][0] < 0){
            ans += truckSize*boxTypes[i][1];
            break;
        }
        
        ans += boxTypes[i][0]*boxTypes[i][1];
        truckSize -= boxTypes[i][0];
    }
    
    return ans;
}