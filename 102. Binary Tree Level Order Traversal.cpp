class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        
        while (!q1.empty() || !q2.empty()) {
            if (q1.empty()) {
                break;
            }
            TreeNode* top;
            vector<int> v1;
            while(!q1.empty()) {
                top = q1.front();
                q1.pop();
                v1.push_back(top->val);
                if (top->left) {
                    q2.push(top->left);
                }
                if (top->right) {
                    q2.push(top->right);
                }
            }
            res.push_back(v1);
            
            if (q2.empty()) {
                break;
            }
            
            vector<int> v2;
            while(!q2.empty()) {
                top = q2.front();
                q2.pop();
                v2.push_back(top->val);
                if (top->left) {
                    q1.push(top->left);
                }
                if (top->right) {
                    q1.push(top->right);
                }
            }
            res.push_back(v2);
        }
        
        return res;
    }
};
