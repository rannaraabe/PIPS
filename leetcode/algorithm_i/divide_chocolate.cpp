/*
Difficulty: Hard;

You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.
You want to share the chocolate with your k friends so you start cutting the chocolate bar into k + 1 pieces using k cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.
Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

Constraints:
0 <= k < sweetness.length <= 10^4
1 <= sweetness[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std; 

int maximizeSweetness(vector<int>& sweetness, int k) {
    int left = 0, right = 1e9;
    int ans = 0;
    
    while(left <= right){
        int p = left+(right-left)/2;
        
        if(isPossible(sweetness, p, k)){
            ans = p;
            left = p+1;
        } else {
            right = p-1;
        }
    }
    
    return ans;
}

bool isPossible(vector<int>& v, int x, int k){
    int sum = 0, pieces = 0;
    
    for(int i=0; i<v.size(); i++){
        sum += v[i];
        if(sum >= x) {
            sum = 0;
            pieces++;
        }
    }
    
    return pieces >= k+1;
}