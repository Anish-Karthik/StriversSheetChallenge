from math import *
from collections import *
from sys import *
from os import *

import sys
sys.setrecursionlimit(10**7)

def modularExponentiation(x, n, m):
	ans = 1
	while n > 0:
		if n & 1: 
			ans = (x * ans) % m 
		x = (x * x) % m
		n //= 2
	return ans

# Main.
t = int(input())
while (t > 0):
	lst = list(map(int,input().split()))
	x,n,m = lst[0], lst[1], lst[2]
	print(modularExponentiation(x, n, m))
	t -= 1
