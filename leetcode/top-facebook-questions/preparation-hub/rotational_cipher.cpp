
/*
Difficulty: -;

One simple way to encrypt a string is to "rotate" every alphanumeric character by a certain amount. Rotating a character means replacing it with another character that is a certain number of steps away in normal alphabetic or numerical order.
For example, if the string "Zebra-493?" is rotated 3 places, the resulting string is "Cheud-726?". Every alphabetic character is replaced with the character 3 letters higher (wrapping around from Z to A), and every numeric character replaced with the character 3 digits higher (wrapping around from 9 to 0). Note that the non-alphanumeric characters remain unchanged.

Given a string and a rotation factor, return an encrypted string.

Constraints:
1 <= |input| <= 1,000,000
0 <= rotationFactor <= 1,000,000
*/

#include <bits/stdc++.h>
using namespace std;

string rotationalCipher(string input, int rotationFactor) {
  if(rotationFactor == 0) return input;
  char aux;
  for(auto &c : input){
    // if c is an alphabetic char
    if(isalpha(c)){  
      aux = isupper(c) ? 'A' : 'a';
      c = aux + (c - aux + rotationFactor)%26;
    }
    // if c is a digit
    if(isdigit(c)){  
      c = '0' + (c - '0' + rotationFactor)%10;
    }
  }
  
  return input;
}

// complexity time: O(n)