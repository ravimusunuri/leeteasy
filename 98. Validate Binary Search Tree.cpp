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
    
    bool isValid(TreeNode* root, long lo, long hi) {
        if (root == NULL)
            return true;
        
        return (((root->val >= lo) && (root->val <= hi)) && 
            (isValid (root->left, lo, (long)root->val-1)) && 
            (isValid (root->right, (long) root->val+1, hi)));
    }
    
    bool isValidBST(TreeNode* root) {
        return(isValid(root, INT_MIN, INT_MAX));
    }
};
