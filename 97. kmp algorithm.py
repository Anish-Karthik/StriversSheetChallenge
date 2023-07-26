from os import *
from sys import *
from collections import *
from math import *

def buildLPS(p):
    m = len(p)
    lps = [0] * m
    i = 0
    j = 1

    while j < m:
        if p[i] == p[j]:
            i += 1
            lps[j] = i
            j += 1
        else:
            if i != 0:
                i = lps[i-1]
            else:
                lps[j] = 0
                j += 1

    return lps

def findPattern(p, s):
    m = len(p)
    n = len(s)
    lps = buildLPS(p)
    i = 0
    j = 0
    while j < n:
        if s[j] == p[i]:
            i += 1
            j += 1
        if i == m:
            return True
        elif j < n and s[j] != p[i]:
            if i != 0:
                i = lps[i-1]
            else:
                j += 1

    return False
