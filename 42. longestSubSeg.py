#------------------------------------------------------------
## better O(n) space 
#------------------------------------------------------------
from collections import *
def longestSubSeg(arr, n, k):
    zeroes = deque()
    st = 0
    res = 0
    for i in range(n):
        if arr[i] == 0:
            zeroes.append(i)
        if len(zeroes) >k:
            st = zeroes.popleft() + 1
        res = max(res, i - st+1)
    return res
#------------------------------------------------------------
## optimal O(1) space
#------------------------------------------------------------
def longestSubSeg(arr, n, k):
    l, r = 0, 0
    zeroes, res= 0, 0
    while r < n:
        if arr[r] == 0:
            zeroes+=1
        if zeroes > k:
            while l<r and zeroes > k:
                if(arr[l] == 0):
                    zeroes-=1
                l+=1
        res = max(res, r-l+1)
        r+=1
    return res
