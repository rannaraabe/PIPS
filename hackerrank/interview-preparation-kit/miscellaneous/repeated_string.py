# Difficulty: Easy;

# There is a string, s, of lowercase English letters that is repeated infinitely many times. Given an integer, n, find and print the number of letter a's in the first n letters of the infinite string.

# s = 'abcac'
# n = 10
# The substring we consider is abcacabcac, the first 10 characters of the infinite string. There are 4 occurrences of a in the substring.

# Constraints:
# 1 <= |s| <= 100
# 1 <= n <= 10^12

# 25% of the test cases, n <= 10^6

import math

def repeatedString(s, n):
    return s.count("a") * (n // len(s)) + s[:n % len(s)].count("a")