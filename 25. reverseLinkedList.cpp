#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
// modifying original list
*****************************************************************/
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(!head) return head;
    LinkedListNode<int> *cur = head->next;
    LinkedListNode<int> *newHead = head;
    newHead->next = NULL;
    while(cur) {
        LinkedListNode<int> *next = cur->next;
        cur->next = newHead;
        newHead = cur;
        cur = next;
    }
    return newHead;
}

*****************************************************************/
// creating new list
*****************************************************************/
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(!head) return head;
    LinkedListNode<int> *cur = head->next;
    LinkedListNode<int> *newHead = head;
    newHead->next = NULL;
    while(cur) {
        LinkedListNode<int> *next = cur->next;
        cur->next = newHead;
        newHead = cur;
        cur = next;
    }
    return newHead;
}
