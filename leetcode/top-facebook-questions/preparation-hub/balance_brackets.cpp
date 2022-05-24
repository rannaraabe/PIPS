/*
Difficulty: -;

A bracket is any of the following characters: (, ), {, }, [, or ].
We consider two brackets to be matching if the first bracket is an open-bracket, e.g., (, {, or [, and the second bracket is a close-bracket of the same type. That means ( and ), [ and ], and { and } are the only pairs of matching brackets.

Furthermore, a sequence of brackets is said to be balanced if the following conditions are met:
1.The sequence is empty, or
2.The sequence is composed of two or more non-empty sequences, all of which are balanced, or
3.The first and last brackets of the sequence are matching, and the portion of the sequence without the first and last elements is balanced.

You are given a string of brackets. Your task is to determine whether each sequence of brackets is balanced. If a string is balanced, return true, otherwise, return false

Constraints:
String s with length between 1 and 1000
*/

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
  stack<char> brackets;
  for(char c : s){
    if(c == '(' || c == '{' || c == '['){
      brackets.push(c);
    } else {
      if(brackets.empty()) return false;
      else if((c == ')' && brackets.top() == '(') ||
         (c == '}' && brackets.top() == '{' ) ||
         (c == ']' && brackets.top() == '[')){
        brackets.pop();
      } else {
        return false;
      }
    }
  }
  
  if(!brackets.empty()) return false;
  
  return true;
}