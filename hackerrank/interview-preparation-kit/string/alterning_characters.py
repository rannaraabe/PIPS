# Difficulty: Easy;

# You are given a string containing characters A and B only. Your task is to change it into a string such that there are no matching adjacent characters. To do this, you are allowed to delete zero or more characters in the string.
# Your task is to find the minimum number of required deletions.

# Constraints:
# 1 <= q <= 10
# 1 <= length of s <= 10^5
# Each string s will consist only of characters A and B.

import math
import os
import random
import re
import sys

def alternatingCharacters(s):
    prev = s[0]
    ans = 0
    
    for i in range(1, len(s)):
        if prev == s[i]:
            ans += 1
        else:
            prev = s[i]
            
    return ans