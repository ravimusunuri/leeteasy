class Solution {
public:
    int inOrderSucc(TreeNode* root) {
        while(root->left)
            root = root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (root->val == key) {  
            if (root->left && root->right) {
                int succ = inOrderSucc(root->right);
                root->val = succ;
                root->right = deleteNode(root->right, succ);
            } else if (root->left) {
                return root->left;
            } else {
                return root->right;
            }
        }
        return root;
    }
};
