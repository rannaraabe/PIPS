# Difficulty: Easy;

# A student is taking a cryptography class and has found anagrams to be very useful. Two strings are anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency. For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.
# The student decides on an encryption scheme that involves two large strings. The encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Determine this number.

# Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character deletions required to make a and b anagrams. Any characters can be deleted from either of the strings.

# Constraints:
# 1 <= |a|,|b| <= 10^4
# The strings a and b consist of lowercase English alphabetic letters, ascii[a-z].

import math
import os
import random
import re
import sys

def makeAnagram(a, b):
    # cde 3
    # dcf 3
    
    size_a, size_b, dele = 0, 0, 0
    a = sorted(a)
    b = sorted(b)
    
    while size_a < len(a) and size_b < len(b):
        if a[size_a] == b[size_b]:
            size_a += 1
            size_b += 1
        elif a[size_a] < b[size_b]:
            dele += 1
            size_a += 1
        else:
            dele += 1
            size_b += 1
        
    if size_a < len(a): 
        dele += len(a)-size_a
    elif size_b < len(b):
        dele += len(b)-size_b
        
    return dele