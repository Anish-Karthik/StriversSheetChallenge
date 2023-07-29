#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
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


************************************************************/
void traveral(BinaryTreeNode<int> *root, vector<vector<int>>& res) {
    if(root) {
        res[1].push_back(root->data);
        traveral(root->left, res);
        res[0].push_back(root->data);
        traveral(root->right, res);
        res[2].push_back(root->data);
    }
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    // inorder, preorder, postorder
    vector<vector<int>> res = { {}, {}, {} };
    traveral(root, res);
    return res;
}
