
/*
Difficulty: Medium;

A group of friends want to buy a bouquet of flowers. The florist wants to maximize his number of new customers and the money he makes.
To do this, he decides he'll multiply the price of each flower by the number of that customer's previously purchased flowers plus 1.
The first flower will be original price, (0+1) x original price, the next will be (1+1) x original price and so on.
Given the size of the group of friends, the number of flowers they want to purchase and the original prices of the flowers, determine the minimum cost to purchase all of the flowers. The number of flowers they want equals the length of the c array.

Constraints:
1 <= n,k <= 100
1 <= c[i] <= 10^6
answer < 2^31
0 <= i < n
*/

#include <bits/stdc++.h>
using namespace std;

int getMinimumCost(int k, vector<int> c) {
    // price_flower * prev_purchased_flowers+1
    // [1 2 3 4] k=3
    
    // 2 * 1+1 = 4
    // 1 * 1+1 = 2
    
    // min_cost = 3+4+4+2 = 13
    
    int min_cost = 0, purchased = 0, round = 0;
    sort(c.begin(), c.end());
    
    for(int i=c.size()-1; i>=0; i--){
        min_cost += c[i]*(1+round);
        if((purchased+1)%k == 0) round++;
        purchased++;
    }
    
    return min_cost;
}
