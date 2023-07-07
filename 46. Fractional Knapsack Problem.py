from os import *
from sys import *
from collections import *
from math import *

def maximumValue(items, n, wt):
	items.sort(key = lambda x: -(x[1]/x[0]))
	profit = 0
	for w, v in items:
		if wt == 0:
			break
		profit += min(wt, w) * (v/w)
		wt -= min(wt, w)
	return profit
