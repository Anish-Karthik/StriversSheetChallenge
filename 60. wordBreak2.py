from os import *
from sys import *
from collections import *
from math import *
setrecursionlimit(int(1e8))

def wordBreak(s, dictionaryList):
    dictionary = set(dictionaryList)
    res, n = [], len(s)
    def f(st, s, tmp):
        if st == n:
            res.append(" ".join(tmp))
            return
        
        for en in range(st+1, n+1):
            substr = s[st:en]
            if substr in dictionary:
                tmp.append(substr)
                f(en, s, tmp)
                tmp.pop()
        return

    f(0,s,[])
    return res
