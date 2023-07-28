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
def inorder(root, res):
    if root:
        inorder(root.left, res)
        res.append(root.data)
        inorder(root.right, res)

def getInOrderTraversal(root):
    res = []
    inorder(root, res)
    return res
