# Difficulty: Medium;

# A string is said to be a special string if either of two conditions is met:
# All of the characters are the same, e.g. aaa.
# All characters except the middle one are the same, e.g. aadaa.

# A special substring is any substring of a string which meets one of those criteria. Given a string, determine how many special substrings can be formed from it.

# Constraints:
# 1 <= n <= 10^6
# Each character of the string is a lowercase English letter, ascii[a-z].

import math
import os
import random
import re
import sys

def substrCount(n, s):
    l = []
    count = 0
    cur = None

    # 1st pass
    for i in range(n):
        if s[i] == cur:
            count += 1
        else:
            if cur is not None:
                l.append((cur, count))
            cur = s[i]
            count = 1
    l.append((cur, count))

    ans = 0
    
    # 2nd pass
    for i in l:
        ans += (i[1] * (i[1] + 1)) // 2
    
    for i in range(1, len(l) - 1):
        if l[i - 1][0] == l[i + 1][0] and l[i][1] == 1:
            ans += min(l[i - 1][1], l[i + 1][1])
        
    return ans