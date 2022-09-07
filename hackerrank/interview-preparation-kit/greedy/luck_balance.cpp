
/*
Difficulty: Easy;

Lena is preparing for an important coding competition that is preceded by a number of sequential preliminary contests. Initially, her luck balance is 0. She believes in "saving luck", and wants to check her theory. Each contest is described by two integers, L[i] and T[i]:
L[i] is the amount of luck associated with a contest. If Lena wins the contest, her luck balance will decrease by L[i]; if she loses it, her luck balance will increase by L[i].
T[i] denotes the contest's importance rating. It's equal to 1 if the contest is important, and it's equal to 0 if it's unimportant.
If Lena loses no more than k important contests, what is the maximum amount of luck she can have after competing in all the preliminary contests? This value may be negative.

Constraints:
1 <= n <= 100
0 <= k <= N
1 <= L[i] <= 10^4
T[i] ∈ {0, 1}
*/

#include <bits/stdc++.h>
using namespace std;

int luckBalance(int k, vector<vector<int>> contests) {
    vector<pair<int, int>> l;
    for(int i=0; i<contests.size(); i++)
        l.push_back(make_pair(contests[i][0], contests[i][1])); 
    
    sort(l.begin(), l.end());
    
    int luck = 0, num_contests = 0;
    for (int i=l.size()-1; i>=0; i--) {
        if(l[i].second == 0)
            luck += l[i].first;
        else {
            if (num_contests < k){
                luck += l[i].first;
                num_contests++;
            } else luck -= l[i].first;
        }
    }
    
    return luck;
}
