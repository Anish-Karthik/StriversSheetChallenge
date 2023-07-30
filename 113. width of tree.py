from os import *
from sys import *
from collections import *
from math import *

'''
  ----Binary tree node class for reference-----
    class TreeNode:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

'''

def getMaxWidth(root):
  q = deque()
  width = 0
  q.append(root)
  while root and q:
    size = len(q)
    width = max(width, size)
    for _ in range(size):
      root = q.popleft()
      if root.left:
        q.append(root.left)
      if root.right:
        q.append(root.right)
  return width


