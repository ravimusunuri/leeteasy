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
    void preorder(TreeNode* root, string cur, vector<string>& res) {
        if (root == NULL) {
            return;
        }
        
        if ((root->left == NULL) && (root->right == NULL)) {
            if (cur.length())
                cur += "->";
            cur += to_string(root->val);
            
            res.push_back(cur);
            return;
        }
        
        if (cur.length())
            cur += "->";
        cur += to_string(root->val);
        preorder(root->left, cur, res);
        preorder(root->right, cur, res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        preorder(root, "", res);
        return res;
    }
};
