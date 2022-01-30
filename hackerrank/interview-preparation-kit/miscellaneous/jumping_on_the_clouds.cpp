/*
Difficulty: Easy;

There is a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. The player can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus 1 or 2. The player must avoid the thunderheads. Determine the minimum number of jumps it will take to jump from the starting postion to the last cloud. It is always possible to win the game.
For each game, you will get an array of clouds numbered 0 if they are safe or 1 if they must be avoided.

Constraints:
2 <= n <= 100
c[i] ∈ {0,1}
c[0] = c[n-1] = 0
*/

#include <bits/stdc++.h>
using namespace std; 

int jumpingOnClouds(vector<int> c) {
    int min = 0;
    for(int i=0; i<c.size(); i++){
        if(i<c.size()-2){
            if(c[i+2] == 0){
                i+=1;
            }
        }
        min++;
    }
    return min-1;
}