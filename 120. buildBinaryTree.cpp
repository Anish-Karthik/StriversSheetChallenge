#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int pres=0;
TreeNode<int> *f(vector<int>& preorder,vector<int>&inorder,int is,int ie){
    if(is>ie) return NULL;
    TreeNode<int> *root=new TreeNode<int>(preorder[pres++]);
    int inIn;
    for(int i=is;i<=ie;i++){
        if(inorder[i]==root->data){
            inIn=i;
            break;
        }
    }
    root->left=f(preorder,inorder,is,inIn-1);
    root->right=f(preorder,inorder,inIn+1,ie);
    return root;
}
TreeNode<int> *#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int pres=0;
TreeNode<int> *f(vector<int>& preorder,vector<int>&inorder,int is,int ie){
    if(is>ie) return NULL;
    TreeNode<int> *root=new TreeNode<int>(preorder[pres++]);
    int inIn;
    for(int i=is;i<=ie;i++){
        if(inorder[i]==root->data){
            inIn=i;
            break;
        }
    }
    root->left=f(preorder,inorder,is,inIn-1);
    root->right=f(preorder,inorder,inIn+1,ie);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    pres=0;
    int is=0;
    int ie=inorder.size()-1;
    return f(preorder,inorder,is,ie);
}(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    pres=0;
    int is=0;
    int ie=inorder.size()-1;
    return f(preorder,inorder,is,ie);
}
