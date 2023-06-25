from os import *
from sys import *
from collections import *
from math import *

from sys import stdin,setrecursionlimit

class Solution:
    def __init__ (self, start, end):
        self.start = start
        self.end = end
# Answer
def mergeIntervals(arr):
    arr.sort(key = lambda x:x.start)
    res = [Solution(arr[0].start, arr[0].end)]
    for interval in arr:
        l,r = interval.start, interval.end
        if l <= res[-1].end:
            res[-1].end =  max(r, res[-1].end) 
        else:
            res.append(Solution(l,r))
    return res

n = int(input())
arr1 = list(map(int, stdin.readline().strip().split(" ")))
arr2 = list(map(int, stdin.readline().strip().split(" ")))
arr1.sort()
arr2.sort()
intervals = []
for i in range(n):
    a = Solution(arr1[i], arr2[i])
    intervals.append(a)

res = mergeIntervals(intervals)

for i in range(len(res)):
    print(res[i].start, res[i].end)
