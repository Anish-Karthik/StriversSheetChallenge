from os import *
from sys import *
from collections import *
from math import *

# Binary tree node class for reference
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def getLeftView(root)->list:
    res = []

    q = deque()
    q.append(root)
    res = []
    while root and len(q):
        res.append(q[0].data)
        size = len(q)
        for i in range(size):
            root = q.popleft()
            if root.left:
                q.append(root.left)
            if root.right:
                q.append(root.right)
    return res
