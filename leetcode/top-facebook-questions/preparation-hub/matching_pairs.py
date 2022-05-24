# Difficulty: -;

# Given two strings s and t of length N, find the maximum number of possible matching pairs in strings s and t after swapping exactly two characters within s.
# A swap is switching s[i] and s[j], where s[i] and s[j] denotes the character that is present at the ith and jth index of s, respectively. The matching pairs of the two strings are defined as the number of indices for which s[i] and t[i] are equal.

# Note: This means you must swap two characters at different indices.

# Constraints:
# s and t are strings of length N
# N is between 2 and 1,000,000


import math

def matchingPairs(string s, string t)
  if(s == t):
    if(len(set(s)) != len(s)):
      return len(s)
    return len(s)-2

  match_pair = {}
  matches = 0
  find_match = False

  for i in range(len(s)):
    if(s[i]==s[t]):
      matches = matches+1
      continue

    match_pair[s[i]] = t[i]
    if(s[i] in match_pair):
      if(match_pair[s[i]] == t[i]):
        find_match = True
    
  if find_match:
    return matches+2

  return matches+1 

# complexity time: O(n)