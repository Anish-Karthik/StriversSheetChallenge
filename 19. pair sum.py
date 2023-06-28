from os import *
from sys import *
from collections import *
from math import *

def pairSum(arr, s):
    n = len(arr)
    map = {}
    ans = []

    for ele in arr:
        count = map.get(s - ele, 0)

        pair = [min(ele, s-ele), max(ele, s-ele)]

        while count > 0:
            ans.append(pair)
            count -= 1

        map[ele] = map.get(ele, 0) + 1
        
    return sorted(ans)
