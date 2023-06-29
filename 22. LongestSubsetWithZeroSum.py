from math import *
from collections import *
from sys import *
from os import *

def LongestSubsetWithZeroSum(arr):
    n = len(arr)
    prefixSum = [0] * (n+1)
    d = {0:0}
    res = 0
    for i in range(1,n+1):
        prefixSum[i] = arr[i-1] + prefixSum[i-1]
        if prefixSum[i] in d:
            res = max(res, i - d[prefixSum[i]])
            continue
        d[prefixSum[i]] = i
    return res
