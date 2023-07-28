from os import *
from sys import *
from collections import *
from math import *

from sys import stdin, setrecursionlimit
from queue import Queue
setrecursionlimit(10**7)

# Following is the TreeNode class structure:
class BinaryTreeNode:
    def __init__(self, data):
        self.val = data
        self.left = None
        self.right = None

def getTopView(root):
    # Write your code here.
    # T.C : O(N)
    # S.C : O(N)
    verticals = {}
    q = deque()
    q.append((0, root))

    start = 0
    while root and q:
        vertical, root = q.popleft()
        start = min(vertical, start)
        if vertical not in verticals:
            verticals[vertical] = root.val
        if root.left:
            q.append((vertical-1, root.left))
        if root.right:
            q.append((vertical+1, root.right))
    
    res = [0] * len(verticals)
    for vertical, data in verticals.items():
        res[vertical - start] = data
    return res
