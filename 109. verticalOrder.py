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

def verticalOrderTraversal(root):
    # Write your code here.
    # T.C : O(N)
    # S.C : O(N)
    verticals = defaultdict(list)
    q = deque()
    q.append((0, root))

    start = 0
    while root and q:
        vertical, root = q.popleft()
        start = min(vertical, start)
        verticals[vertical].append(root.data)
        if root.left:
            q.append((vertical-1, root.left))
        if root.right:
            q.append((vertical+1, root.right))
    
    res = [0] * len(verticals)
    for vertical, data in verticals.items():
        res[vertical - start] = data
    ans = []
    for arr in res:
        ans.extend(arr)
    return ans
