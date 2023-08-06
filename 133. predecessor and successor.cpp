/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{   
    private:
    
    void predecessor(Node* node, int k, Node*& pre){
        if(node == NULL)
            return;
        if(node->key >= k)
            predecessor(node->left, k, pre);
        else{
            pre = node;
            predecessor(node->right, k, pre);
        }
    }
    
    void successor(Node* node, int k, Node*& suc){
        if(node == NULL)
            return;
        if(node->key > k){
            suc = node;
            successor(node->left, k, suc);  
        }
        else{
            successor(node->right, k, suc);
        }
    }
    
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int k)
    {
        predecessor(root, k, pre);
        successor(root, k, suc);
    }
};
