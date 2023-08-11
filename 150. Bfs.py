#User function Template for python3

from typing import List
from queue import Queue
class Solution:
    #Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, V: int, adj: List[List[int]]) -> List[int]:
        q = Queue()
        q.put(0)
        visited = set()
        res = []
        while not q.empty():
            node = q.get()
            if node not in visited:
                res.append(node)
            visited.add(node)
            for child in adj[node]:
                if child not in visited:
                    q.put(child)
        return res
            
