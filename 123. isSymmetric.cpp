#include <bits/stdc++.h>  
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/
bool issym(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2){
    if(!root1&&!root2) return true;
    if(!root1 && root2 || !root2 && root1) return false;
    if(root1->data!=root2->data) return false;
    return issym(root1->left,root2->right)&&issym(root1->right,root2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root) {
	//Write your code here
    if(!root) return true;
    return issym(root->left,root->right);
}
