/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node* computeSum(Node* root,int& rem) {
    Node* res = root;
    while(root && rem) {
        int sum = (root->data + rem)%10;
        res = root;
        rem = (root->data + rem)/10;
        res->data = sum;
        root = root->next;
    }
    return res;
}

Node *addTwoNumbers(Node *num1, Node *num2)
{
    if(!num1) return num2;
    if(!num2) return num1;
    int rem = 0;
    int sum = 0;
    Node* res = num1;
    Node* head = num1;
    while (num1 && num2) {
        sum = (num1->data + num2->data + rem)%10;
        res = num1;
        rem = (num1->data + num2->data + rem)/10;
        res->data = sum;
        num1 = num1->next;
        num2 = num2->next;
    }
    if(num1) res = computeSum(num1, rem);
    if(num2) {
        res->next = num2;
        res = computeSum(num2, rem);
    }
    if(rem && res) {
        res->next = new Node(1);
    }
    return head;
}
