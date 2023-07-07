from os import *
from sys import *
from collections import *
from math import *

denominations = [1, 2, 5, 10, 20, 50, 100, 500, 1000]


def findMinimumCoins(amount):

	coins = [1000, 500, 100, 50, 20, 10, 5, 2, 1]
	coinCnt = 0
	for coin in coins:
		if amount == 0:
			break
		coinCnt += amount // coin
		amount -= amount // coin * coin
	
	return coinCnt
