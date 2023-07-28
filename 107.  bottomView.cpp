#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

*************************************************************/

void verticalOrder(BinaryTreeNode<int> * root, int vertical, int level,
    unordered_map<int,pair<int,int>> &verticals) {
    if(!root) return;
    if(verticals.find(vertical) == verticals.end() ||
        verticals[vertical].first <= level){
            verticals[vertical] = {level,root->data};
    }
    verticalOrder(root->left, vertical-1, level+1, verticals);
    verticalOrder(root->right, vertical+1, level+1, verticals);
}

vector<int> bottomView(BinaryTreeNode<int> * root){
    // Write your code here.
    // vetical -> {level , data}
    unordered_map<int,pair<int,int>> verticals;
    verticalOrder(root, 0, 0, verticals);
    vector<int> res(verticals.size());

    int left = 0;
    for(auto it: verticals) {
        left = min(left, it.first);
    }

    for(auto it: verticals) {
        res[it.first-left] = it.second.second;
    }
    return res;
}
