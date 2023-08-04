class Solution {
public:
    void mirror(Node* currentNode) {
        if (currentNode == NULL || (currentNode->left == NULL && currentNode->right == NULL)) {
            return;
        }
        mirror(currentNode->left);
        mirror(currentNode->right);
        Node* temp = currentNode->left;
        currentNode->left = currentNode->right;
        currentNode->right = temp;
    }
};
