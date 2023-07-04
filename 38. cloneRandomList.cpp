#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(!head) return nullptr;
    unordered_map<LinkedListNode<int>*,LinkedListNode<int>*> hashMap;
    LinkedListNode<int>* temp = head;
    while(temp != NULL) {
        LinkedListNode<int>* newNode = new LinkedListNode<int>(temp->data);
        hashMap[temp] = newNode;
        temp = temp->next;
    }
    LinkedListNode<int>* t = head;
    while(t != NULL) {
        LinkedListNode<int>* node = hashMap[t];
        node->next = (t->next != NULL) ? hashMap[t->next]:NULL;
        node->random = (t->random != NULL) ? hashMap[t->random]:NULL;
        t = t->next;
    }
    return hashMap[head];
}
