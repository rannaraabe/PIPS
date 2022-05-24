/*
Difficulty: -;

You likely know that different currencies have coins and bills of different denominations. In some currencies, it's actually impossible to receive change for a given amount of money. For example, Canada has given up the 1-cent penny. If you're owed 94 cents in Canada, a shopkeeper will graciously supply you with 95 cents instead since there exists a 5-cent coin.
Given a list of the available denominations, determine if it's possible to receive exact change for an amount of money targetMoney. Both the denominations and target amount will be given in generic units of that currency.

Constraints:
1 ≤ |denominations| ≤ 100
1 ≤ denominations[i] ≤ 10,000
1 ≤ targetMoney ≤ 1,000,000
*/

#include <bits/stdc++.h>
using namespace std;

bool canGetExactChange(int targetMoney, vector<int>& denominations){
  if(targetMoney < 0) return false;
  if (targetMoney == 0) return true;
  
  for(int i=0; i<denominations.size(); i++){
    if(canGetExactChange(targetMoney-denominations[i], denominations)) return true;
  }
  
  return false;
}
