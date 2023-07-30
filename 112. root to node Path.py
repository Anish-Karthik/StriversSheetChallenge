from os import *
from sys import *
from collections import *
from math import *

from typing import List


class TreeNode:   
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def getPath(root, res, x):
    if not root:
        return False
    if root.data == x:
        res.append(root.data)
        return True
    left = getPath(root.left, res, x)
    right = getPath(root.right, res, x)
    if left or right:
        res.append(root.data)
        return True
        
def pathInATree(root: TreeNode, x: int) -> List[int]:
    res = []
    getPath(root, res, x)
    return res[::-1]
