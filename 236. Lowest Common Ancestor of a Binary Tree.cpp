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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        if (root == NULL) {
            return NULL;    
        }
        
        if ((root == p) || (root == q)) {
            return root; 
        }
        
        TreeNode *t1 = lowestCommonAncestor(root->left, p, q);
        
        TreeNode *t2 = lowestCommonAncestor(root->right, p, q);
        
        if ((t1 && t2) || ((t1 || t2) && (root == p) ||(root == q))) {
            return root;
        } else if (t1) {
            return t1;
        } else if (t2) {
            return t2;
        }
    
        return NULL;
    
    }
};
