/*
Difficulty: Medium;

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> vertice;
map<vertice, int> cc; // vertice, idx

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == '1'){
                if(cc.find({i, j}) == cc.end()){
                    dfs({i, j}, count++, grid);
                }
            }
        }
    }
    
    return count;
}

void dfs(vertice v, int idx, vector<vector<char>>& grid){
    if(cc.find(v) != cc.end()) return;
    cc[v] = idx;
    
    for(int di=-1; di<=1; di++){
        for(int dj=-1; dj<=1; dj++){
            if(di && dj) continue;
            if(!di && !dj) continue;
            int i = v.first;
            int j = v.second;
            if(i+di < grid.size() && j+dj < grid[0].size() && i+di >= 0 && j+dj >= 0 && grid[i+di][j+dj] == '1'){
                dfs({i+di, j+dj}, idx, grid);
            }
        }
    }
    
    // -1-1 -10 1-1
    // 0-1  00  01
    // 1-1  10  11
}
