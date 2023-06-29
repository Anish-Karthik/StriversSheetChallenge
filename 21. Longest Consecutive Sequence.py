from math import *
from collections import *
from sys import *
from os import *

def lengthOfLongestConsecutiveSequence(arr, n):
    
    d = set(arr)
    ans = 1
    for x in d:
        if x-1 in d:
            continue
        cnt = 1
        while x+1 in d:
            cnt+=1
            x+=1
        ans = max(ans,cnt)
    return ans
                

