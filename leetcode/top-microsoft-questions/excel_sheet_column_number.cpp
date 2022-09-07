/*
Difficulty: Easy;
Phone Interview

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

Constraints:
1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"]
*/

#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle) {
    int ans = 0;
    for(auto c : columnTitle){
        int num = c-'A'+1;
        ans = ans*26 + num;
    }
    
    return ans;
}