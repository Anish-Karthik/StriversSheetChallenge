/****************************************************************

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

*****************************************************************/

Node* findIntersection(Node *l1, Node *l2)
{
    Node* tail = l1;
    while(tail->next){
        tail = tail->next;
    }

    //creating a loop
    tail->next = l1;

    //detecting and finding the intersection
    Node *fast = l2, *slow = l2;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast) {
            slow = l2;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            //undoing the loop
            tail->next = NULL;
            return slow;
        };
    }
    tail->next = NULL;
    return NULL;
}
