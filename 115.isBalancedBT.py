from os import *
from sys import *
from collections import *
from math import *

'''
  ----Binary tree node class for reference-----
    class BinaryTreeNode:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

'''
def heightAndBal(root):
  if not root:
    return (True, 0)
  isvalidLeft, left = heightAndBal(root.left)
  isvalidRight, right = heightAndBal(root.right)
  return (abs(left-right)<2 and isvalidRight and isvalidLeft, max(left,right)+1)

def isBalancedBT(root):
  return heightAndBal(root)[0]

