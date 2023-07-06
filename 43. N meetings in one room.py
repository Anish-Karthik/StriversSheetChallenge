from os import *
from sys import *
from collections import *
from math import *

def maximumMeetings(start, end):
    
    tmp = sorted(zip(start,end,range(len(end))), key = lambda x: x[1])
    en = -1
    res = []
    for l, r, i in tmp:
        if en < l:
            res.append(i+1)
            en = r

    return res
