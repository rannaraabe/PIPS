/*
Difficulty: Medium;

Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid.
A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form).
The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.

Idea:
The idea used here is simple, we check every cell. If cell has first character, then we one by one try all 8 directions from that cell for a match.
Implementation is interesting though. We use two arrays x[] and y[] to find next move in all 8 directions. 

Constraints:
1 <= n <= m <= 100
1 <= word.size() <= 10
*/

// This is a GeeksForGeeks solution: https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/amp/
#include <bits/stdc++.h>
using namespace std; 

// For searching in all directions
int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

bool search2D(char *grid, int row, int col, string word, int R, int C) {
    // If first character of word doesn't match with given starting point in grid.
    if (*(grid+row*C+col) != word[0])
        return false;

    int len = word.length();
 
    for (int dir = 0; dir < 8; dir++) {
        // Initialize starting point for current direction
        int k, rd = row + x[dir], cd = col + y[dir];
        // First character is already checked, match remaining characters
        for (k = 1; k < len; k++) {
            // If out of bound break
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
            // If not matched,  break
            if (*(grid+rd*C+cd) != word[k])
                break;
            // Moving in particular direction
            rd += x[dir], cd += y[dir];
        }
        // If all character matched, then value of k be equal to length of word
        if (k == len)
            return true;
    }

    return false;
}
 
// Searches given word in a given matrix in all 8 directions
void patternSearch(char *grid, string word, int R, int C){
    // Consider every point as starting point and search given word
    for (int row = 0; row < R; row++){
        for (int col = 0; col < C; col++){
            if (search2D(grid, row, col, word, R, C))
                cout << "pattern found at " << row << ", " << col << endl;
        }

    }
}