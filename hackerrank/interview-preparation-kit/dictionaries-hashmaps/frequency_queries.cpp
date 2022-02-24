/*
Difficulty: Medium;

You are given q queries. Each query is of the form two integers described below:
- 1x: Insert x in your data structure.
- 2y: Delete one occurence of y from your data structure, if present.
- 3z: Check if any integer is present whose frequency is exactly z. If yes, print 1 else 0.

The queries are given in the form of a 2-D array queries of size q where queries[i][0] contains the operation, and queries[i][1] contains the data element.

Constraints:
1 <= q <= 10^5
1 <= x, y, z <= 10^9
All queries[i][0] ∈ {1,2,3} 
1 <= queries[i][1] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std; 

vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> freq;
    map<int, int> freqfreq;
    vector<int> ans = {};
    
    for(vector<int> v : queries){
        if(v[0]==1){
            freqfreq[freq[v[1]]]--;            
            freq[v[1]]++; 
            freqfreq[freq[v[1]]]++;
        }
            
        else if(v[0]==2) {
            if(freq.find(v[1]) != freq.end()){
                if(freq[v[1]] > 0){
                    freqfreq[freq[v[1]]]--;
                    freq[v[1]]--;
                    freqfreq[freq[v[1]]]++;                    
                }
            } 
        }
        
        else if(v[0] == 3){
            if(freqfreq.find(v[1]) != freqfreq.end()) {
                if(freqfreq[v[1]] > 0)
                    ans.push_back(1);
                else 
                    ans.push_back(0);
            } else {
                ans.push_back(0);                
            }
        } 
    }
    
    return ans;
}
