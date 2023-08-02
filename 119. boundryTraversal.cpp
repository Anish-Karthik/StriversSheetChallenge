#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void left(TreeNode<int>* root, set<TreeNode<int>*> &st)

{

    if(root==NULL)

    return ;

    st.insert(root);

    cout<<root->data<<" ";

    if(root->left)

    left(root->left,st);

    else

    left(root->right,st);

}

void leaf(TreeNode<int>* root, set<TreeNode<int>*> &st, int &o)

{

    if(root==NULL)

    return ;

      leaf(root->left,st,o);

      

    if(root->left==NULL && root->right==NULL)

    {

      st.insert(root);

      if(st.size()!=o)

      {

          cout<<root->data<<" ";

          o++;

      }

     

    }

   

     leaf(root->right,st,o);

  

   

 

}

void right(TreeNode<int>* root, set<TreeNode<int>*> &st, int &o)

{

    if(root==NULL)

    return ;

     

     if(root->right!=NULL)

     right(root->right,st,o);

     else

     right(root->left,st,o);

     st.insert(root);

      if(st.size()!=o)

      {

          cout<<root->data<<" ";

          o++;

      }

     

 

}

vector<int> traverseBoundary(TreeNode<int>* root){

    if(root==NULL)

    return {};

    set<TreeNode<int>*> st;

   st.insert(root);

   cout<<root->data<<" ";

    

    left(root->left,st);

    int o=st.size();

   leaf(root,st,o);

   right(root->right,st,o);

   

    vector<int> ans;

    return ans;

    

}
