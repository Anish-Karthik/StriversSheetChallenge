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
TreeNode<int>* lca(TreeNode<int> *root, int x, int y){
    if(!root) return nullptr;
    if (root->data == x or root->data == y) return root;
    TreeNode<int>* left = lca(root->left, x, y);
    TreeNode<int>* right = lca(root->right, x, y);
    if (left and right) return root;
    return left?left:right;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return lca(root, x, y)->data;
}
