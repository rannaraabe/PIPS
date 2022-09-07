/*
Difficulty: Medium;
Phone Interview

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[0].size(); ++j){
            if(dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;    
}

bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index) {
    if(index == word.size()) return true; // end condition
    if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) return false; // boundary of matrix 
    if(board[i][j] != word[index]) return false; // don't match
    
    board[i][j] = '*'; 
    bool ret =  dfs(board, word, i+1, j, index+1) || dfs(board, word, i-1, j, index+1) || dfs(board, word, i, j-1, index+1) || dfs(board, word, i, j+1, index+1);
    
    board[i][j] = word[index];
    return ret;
}