from os import * 
from sys import *
from collections import *
from math import *

class Node :

    def __init__(self) :
        self.links = [None] * 26
        self.cntPrefix = 0
        self.cntEndWith = 0

    def containsKey(self, ch) -> bool :
        return self.links[ord(ch) - ord('a')] != None

    def increasePrefix(self) :
        self.cntPrefix += 1
 
    def decreasePrefix(self) :
        self.cntPrefix -= 1

    def put(self, ch) :
        
        if self.containsKey(ch):
            return
        self.links[ord(ch) - ord('a')] = Node()   
        
    def get(self, ch) :
        if not self.containsKey(ch):
            return False
        return self.links[ord(ch) - ord('a')]   

    def delete(self, ch):
        self.links[ord(ch) - ord('a')].cntPrefix -= 1
        
    def setEnd(self) :
        self.cntEndWith += 1
        
    def deleteEnd(self) :
        self.cntEndWith -= 1

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        node = self.root
        for ch in word :
            node.put(ch)
            node = node.get(ch)
            node.increasePrefix()
        node.setEnd()


    def countWordsEqualTo(self, word):
        node = self.root
        for ch in word :
            node = node.get(ch)
            if not node:
                return 0
        return node.cntEndWith

    def countWordsStartingWith(self, word):
        node = self.root
        for ch in word :
            node = node.get(ch)
            if not node:
                return 0
        return node.cntPrefix

    def erase(self, word):
        if self.countWordsEqualTo(word) == 0:
            return
        node = self.root
        for ch in word :
            node = node.get(ch)
            node.decreasePrefix()
        node.deleteEnd()
            
