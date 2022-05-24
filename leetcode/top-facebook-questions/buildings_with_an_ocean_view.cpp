// MOCK

#include <bits/stdc++.h>
using namespace std;

vector<int> seeOcean(vector<int> buildings){

    stack<pair<int, int>> s;    // height, idx
    for(int i=0; i<buildings.size(); i++){
        while(!s.empty() && s.top().first <= buildings[i]){
            s.pop();
        }
        s.push({buildings[i], i});
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top().second);
        s.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}