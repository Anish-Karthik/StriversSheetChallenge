from os import *
from sys import *
from collections import *
from math import *

def compareVersions(a, b):
    a = list(map(int, a.split('.')))
    b = list(map(int, b.split('.')))
    n = max(len(a), len(b))
    for i in range(n):
        num1 = a[i] if i < len(a) else 0
        num2 = b[i] if i < len(b) else 0
        if num1 > num2:
            return 1
        elif num1 < num2:
            return -1
    return 0
