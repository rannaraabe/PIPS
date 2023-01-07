/*
Difficulty: Medium;

It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Return the maximum number of ice cream bars the boy can buy with coins coins.

Note: The boy can buy the ice cream bars in any order.

Constraints:
costs.length == n
1 <= n <= 10^5
1 <= costs[i] <= 10^5
1 <= coins <= 10^8
*/

#include <bits/stdc++.h>
using namespace std; 

int maxIceCream(vector<int>& costs, int coins) { // O(costs.size())
    sort(costs.begin(), costs.end());   // O(n)
    if(costs[0] > coins) return 0;
    
    for(int i = 0; i<costs.size(); i++){ // O(n)
        coins -= costs[i];
        // 6 5 3 0 
        if(coins < 0)
            return i;
    }

    return costs.size();   
}