/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* root, int& k, int& num) {
        if (root == NULL) 
            return;
        
        inorder(root->left, k, num);
         k = k-1;
        if (k == 0)
            num = root->val;
        inorder(root->right, k, num);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        inorder(root, k, res);
        return res;
    }
};
