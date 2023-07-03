'''
Following is the structure of the Node class already defined.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
'''



def firstNode(head):
    if head == None or head.next == None:
        return None
    fast = head
    slow = head
    entry = head
    while fast.next != None and fast.next.next != None:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            while slow != entry:
                slow = slow.next
                entry = entry.next
            return slow
    return None
