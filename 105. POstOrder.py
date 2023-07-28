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

def postOrder(root, res):
	if root:
		postOrder(root.left, res)
		postOrder(root.right, res)
		res.append(root.data)
def getPostOrderTraversal(root):
	res = []
	postOrder(root, res)
	return res
