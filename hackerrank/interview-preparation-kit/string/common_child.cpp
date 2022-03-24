/*
Difficulty: Medium;

A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string. Letters cannot be rearranged. Given two strings of equal length, what's the longest string that can be constructed such that it is a child of both?

Constraints:
1 <= |s1|,|s2| <= 5000 where |s| means "the length of s"
All characters are upper case in the range ascii[A-Z].
*/

#include <bits/stdc++.h>
using namespace std;

int commonChild(string s1, string s2) {
    vector<vector<int>> mat(s1.size()+1, vector<int>(s2.size()+1, 0));

    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if(s1[i] == s2[j])  
                mat[i+1][j+1] = mat[i][j]+1;
            else 
                mat[i+1][j+1] = max(mat[i+1][j], mat[i][j+1]);
        }
    }

    return mat[s1.size()][s2.size()];
}