bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL) {
        return  false;
    }
    if(root->data == x) {
        return true;
    }
    else if(root->data < x) {
        searchInBST(root->right,x);
    }
    else {
        searchInBST(root->left,x);
    }
}
