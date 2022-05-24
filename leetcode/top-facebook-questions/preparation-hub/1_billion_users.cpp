/*
Difficulty: -;

We have N different apps with different user growth rates. At a given time t, measured in days, the number of users using an app is g^t (for simplicity we'll allow fractional users), where g is the growth rate for that app. These apps will all be launched at the same time and no user ever uses more than one of the apps. We want to know how many total users there are when you add together the number of users from each app.
After how many full days will we have 1 billion total users across the N apps?

Constraints:
1.0 < growthRate < 2.0 for all growth rates
1 <= N <= 1,000
*/

#include <bits/stdc++.h>
using namespace std;

int getBillionUsersDay(vector <float> growthRates) {
  int start = 1, end = 2000;
  float target = 1000000000;
  
  while(start < end){
    int mid = start+(end-start)/2;
    
    float total = 0;
    for(float g : growthRates){
      total += pow(g, mid);
    }
    
    if(total == target){
      return total;
    } else if(total < target){
      start = mid+1;
    } else{
      end = mid;
    }
  }
  
  return end;
}
// complexity time: O(log n)