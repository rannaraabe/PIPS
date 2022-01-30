/*
Difficulty: Hard;

Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.

n = 10
queries = [[1,5,3],[4,8,7],[6,9,1]]
Queries are interpreted as follows:
    a b k
    1 5 3
    4 8 7
    6 9 1
Add the values of k between the indices a and b inclusive:
index->	 1 2 3 4 5 6 7 8 9 10
	[0,0,0,0,0,0,0,0,0,0]
	[3,3,3,3,3,0,0,0,0,0]
	[3,3,3,10,10,7,7,7,0,0]
	[3,3,3,10,10,8,8,8,1,0]
The largest value is 10 after all operations are performed.

Constraints:
3 <= n <= 10^7
1 <= m <= 2*10^5
1 <= a <= b <= n
0 <= k <= 10^9
*/

#include <bits/stdc++.h>
using namespace std; 

long arrayManipulation(int n, vector<vector<int>> queries) {
    // (1, {begin, 3}), (5, {end, 3})
    // 1 begin
    // 0 end
    
    long maior = INT_MIN;
    long valorAtual = 0;
    
    //1, {begin, 3}
    vector<pair<int, pair<int, int>>> sweep;  

    for(long i=0; i<queries.size(); i++){
        sweep.push_back({queries[i][0], {1, queries[i][2]}});
        sweep.push_back({queries[i][1]+1, {0, queries[i][2]}});
    }
    
    sort(sweep.begin(), sweep.end());
    
    for(long i=0; i<sweep.size(); i++){
        if(sweep[i].second.first == 1){            
            valorAtual+=sweep[i].second.second;
            maior = max(valorAtual, maior);
        } else {
            valorAtual-=sweep[i].second.second;
        } 
    }
    return maior;
}