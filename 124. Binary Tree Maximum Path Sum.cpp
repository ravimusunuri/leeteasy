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
    
    int maxPath(TreeNode* root, int& max_path) {
        int max_here = 0;
        int max_ret = 0;
        
        if (root == NULL) {
            return 0;
        }
        
        int l_sum = maxPath(root->left, max_path);
        int r_sum = maxPath(root->right, max_path);
        
        max_ret = max(max(l_sum, r_sum)+root->val, root->val);
        
        max_here = max(l_sum+r_sum+root->val, max_ret);
        
        if (max_path < max_here) {
            max_path = max_here;
        }
        
        
        return max_ret;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPath(root, res);
        return res;
    }
};
