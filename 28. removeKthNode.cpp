/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    Node * slow = NULL;
    Node * fast = head;
    int i = 0;
    for(i = 0; fast; i++) {
        if(i == K) {
            slow = head;
        }
        if(i > K) slow = slow->next;
        fast = fast->next;
    }
    if(K<i) {
        Node * tmp = slow->next;
        slow->next = tmp->next;
        delete tmp; 
    }
    if(K==i) return head->next;
    return head;
}
