from os import *
from sys import *
from collections import *
from math import *

def areAnagram(str1, str2):
    d1, d2 = Counter(str1), Counter(str2)
    return len(str1) == len(str2) and all((d1.get(k) == v for k, v in d2.items()))
