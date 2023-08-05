#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode< int > *>q;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s-1;i++){
            BinaryTreeNode< int > *x=q.front();
            q.pop();
            x->next=q.front();
            if(x->left)q.push(x->left);
            if(x->right)q.push(x->right);
        }
        BinaryTreeNode< int > *y=q.front();
        q.pop();
        if(y->left)q.push(y->left);
        if(y->right)q.push(y->right);
    }
}
