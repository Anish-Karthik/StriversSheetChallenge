from math import *
from collections import *
from sys import *
from os import *

def missingAndRepeating(arr, n):
    s1n, s2n = n*(n+1) //2, n*(n+1)*(2*n+1) // 6
    # let R be x and M be y
    s1, s2 = 0, 0
    for x in arr:
        s1 += x
        s2 += x*x
    # let eqn1 = x - y = s1 - s1n
    eqn1 = s1 - s1n
    # x2 - y2 = (x-y)(x+y) = s2 - s2n
    # let eqn2 = x + y = (s2 - s2n)/(s1 - s1n)
    eqn2 = (s2 - s2n)//(s1 - s1n)
    # eqn1 + eqn2 = 2x 
    # eqn2 - eqn1 = 2y or y = s1n - (s1 - x)

    x = (eqn1 + eqn2) // 2
    y = (eqn2 - eqn1) // 2

    return y, x

