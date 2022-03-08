/*
Difficulty: Easy;

Mark and Jane are very happy after having their first child. Their son loves toys, so Mark wants to buy some. There are a number of different toys lying in front of him, tagged with their prices. Mark has only a certain amount to spend, and he wants to maximize the number of toys he buys with this money. Given a list of toy prices and an amount to spend, determine the maximum number of gifts he can buy.
Note: Each toy can be purchased only once.

Example: prices = [1, 2, 3, 4], k = 7
The budget is 7 units of currency. He can buy items that cost [1, 2, 3] for 6, or [3, 4] for 7 units. The maximum is 3 items.

Constraints:
1 <= n <= 10^5
1 <= k <= 10^9
1 <= prices[i] <= 10^9
A toy can't be bought multiple times.
*/

#include <bits/stdc++.h>
using namespace std; 

int maximumToys(vector<int> prices, int k) {
    int maxToys = 0;
    sort(prices.begin(), prices.end());
    
    for(int i=0; i<prices.size(); i++){
        if(prices[i] <= k){
            maxToys++;
            k -= prices[i];
        } else {
            break;
        }
    }
    
    return maxToys;
}