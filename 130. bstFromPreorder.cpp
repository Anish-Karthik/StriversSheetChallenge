/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

   public:

    int posi(vector<int>& inorder , int element , int size){

        for(int i=0; i<size ; i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1 ;
    }
    TreeNode* solve(vector<int> preorder,vector<int> &inorder,int &preorderindex,int inorderstart,int inorderend, int size ){
        if(preorderindex>=size || inorderstart>inorderend){
            return NULL ;
        }
        int element = preorder[preorderindex++];
        TreeNode* root = new TreeNode(element);
        int position = posi(inorder, element , size);
    root->left = solve(preorder,inorder,preorderindex,inorderstart,position-1,size);
    root->right = solve(preorder,inorder,preorderindex,position+1,inorderend,size);
        return root ; 
        
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder ;
        sort(inorder.begin(),inorder.end());
        
        int preorderindex = 0 ; 
        int inorderstart = 0 ; 
        int inorderend = inorder.size()-1 ; 
        int size = inorder.size();
        
    TreeNode* node=solve(preorder,inorder,preorderindex,inorderstart,inorderend,size);
        return node ; 
    }
};
