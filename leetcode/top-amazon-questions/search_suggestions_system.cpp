/*
Difficulty: Medium;

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

Constraints:
1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 10^4
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> ans(searchWord.size(), vector<string>{});
    sort(products.begin(), products.end());
    
    for(auto s : products) {
        for(int i=0; i<searchWord.size(); i++){
            if(s[i] != searchWord[i])
                break;
            
            if(s[i] == searchWord[i] && ans[i].size() < 3)
                ans[i].push_back(s);
        }
    }
    
    return ans;
}