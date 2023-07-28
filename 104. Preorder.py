from os import *
from sys import *
from collections import *
from math import *

'''
	 
	 Following is the Binary Tree node structure:
	 
	 class TreeNode:
	     def __init__(self, data=0, left=None, right=None):
	         self.data = data
	         self.left = left
	         self.right = right
'''

def preOrder(root, res):
	if root:
		res.append(root.data)
		preOrder(root.left, res)
		preOrder(root.right, res)
def getPreOrderTraversal(root):
	res = []
	preOrder(root, res)
	return res
