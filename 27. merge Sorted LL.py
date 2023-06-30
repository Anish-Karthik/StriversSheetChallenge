from math import *
from collections import *
from sys import *
from os import *

import sys
from sys import stdin

# Following is the linked list node structure:
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
      
def sortTwoLists(first, second):
    
    # if any are empty
    if not first or not second:
        if first:
            return first
        return second
    
    ans = None
    head = None
    while first and second:
        tmp = None
        if first.data <= second.data:
            tmp = first
            first = first.next
        else:
            tmp = second
            second = second.next

        if not ans:
            ans = tmp
            ans.next = None
            head = tmp
        else:
            ans.next = tmp
            ans = tmp
    if first:
        ans.next = first
    if second:
        ans.next = second
    
    return head
# using extra space
def sortTwoLists(first, second):
    
    if not first or not second:
        if first:
            return first
        return second
    
    ans = None
    head = None
    while first and second:
        newNode = Node(min(first.data, second.data))

        if first.data <= second.data:
            first = first.next
        else:
            second = second.next

        if ans:
            ans.next = newNode
        else:
            head = newNode
        ans = newNode
    if first:
        ans.next = first
    if second:
        ans.next = second
    
    return head









## Driver Code
def ll(arr):
    
    if len(arr)==0:
        return None
    
    head = Node(arr[0])
    last = head
    
    for data in arr[1:]:
        
        last.next = Node(data)
        last = last.next
        
    return head

def printll(head):
    
    while head:
        
        print(head.data, end=' ')
        
        head = head.next
        
    print(-1)

    

t = int(sys.stdin.readline().strip())

for i in range(t):
    
    arr1=list(map(int, sys.stdin.readline().strip().split(" ")))
    arr2=list(map(int, sys.stdin.readline().strip().split(" ")))
    
    l1 = ll(arr1[:-1])
    l2 = ll(arr2[:-1])
    
    l = sortTwoLists(l1, l2)
    
    printll(l)

