/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     Node* ptr = head;
     Node* tail = head;
     int i = 0;
     for(i = 0; ptr->next; i++) {
          if(i >= k) {
               tail = tail->next;
          }
          ptr = ptr->next;
     }
     // cout<<k<<' '<<i<<'\n';
     if(k>i) {
          return rotate(head, k%(i+1));     
     }
     ptr->next = head;
     ptr = tail->next;
     tail->next = NULL;
     return ptr;
}
