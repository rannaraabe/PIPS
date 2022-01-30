/*
Difficulty: Easy;

Harold is a kidnapper who wrote a ransom note, but now he is worried it will be traced back to him through his handwriting. He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note. The words in his note are case-sensitive and he must use only whole words available in the magazine. He cannot use substrings or concatenation to create the words he needs.
Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.

Constraints:
1 <= n,m <= 30000
1 <= lengthsofmagazine[i]andnote[i] <= 5
Each word consists of English alphabetic letters
*/

#include <bits/stdc++.h>
using namespace std; 

void checkMagazine(vector<string> magazine, vector<string> note) {
    map<string, int> freq;
    for(auto s : magazine){
        freq[s]++;
    }

    for(auto s : note){
        if(freq[s]!=0){
            freq[s]--;
        } else {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}