/*
Difficulty: Medium;

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

Constraints:
m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], newColor < 216
0 <= sr < m
0 <= sc < n
*/

#include <bits/stdc++.h>
using namespace std; 

void dfs(vector<vector<int>>& image, int sr, int sc, int color, int newColor){
    if(image[sr][sc] == color){
        image[sr][sc] = newColor;
        
        if(sr >= 1){
            dfs(image, sr-1, sc, color, newColor);
        }
        
        if(sc >= 1){
            dfs(image, sr, sc-1, color, newColor);
        }
        
        if(sr+1 < image.size()){
            dfs(image, sr+1, sc, color, newColor);
        }
        
        if(sc+1 < image[0].size()){
            dfs(image, sr, sc+1, color, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int color = image[sr][sc];
    if(color != newColor){
        dfs(image, sr, sc, color, newColor);
    }
    
    return image;
}