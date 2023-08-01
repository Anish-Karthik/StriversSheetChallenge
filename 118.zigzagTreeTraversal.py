from os import *
from sys import *
from collections import *
from math import *

'''
# Binary tree node class for reference
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
'''

def zigzagTreeTraversal(root):
    if not root:
        return []
    q = deque()
    q.append(root)
    level, res = 0, []
    while q:
        size = len(q)
        tmp = []
        for _ in range(size):
            root = q.popleft()
            if root.left:
                q.append(root.left)
            if root.right:
                q.append(root.right)
            tmp.append(root.data)
        level+=1
        if level%2==0:
            res.extend(tmp[::-1])
        else:
            res.extend(tmp)
    return res
                
                

        
