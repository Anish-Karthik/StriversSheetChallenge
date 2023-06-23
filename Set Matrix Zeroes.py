from math import *
from collections import *
from sys import *
from os import *
 
from typing import List

def setZeros(mat: List[List[int]]) -> None:
    n, m = len(mat), len(mat[0])
    row, col = {}, {}
    for i in range(n) :
        for j in range(m) :
            if mat[i][j] == 0:
                row[i] = 1
                col[j] = 1
    for i in row:
        for j in range(m) :
            mat[i][j] = 0
    for j in col:
        for i in set(range(n)) - row.keys() :
            mat[i][j] = 0
