class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        
        while (!s1.empty() || !s2.empty()) {
            if (s1.empty()) {
                break;
            }
            TreeNode* top;
            vector<int> v1;
            while(!s1.empty()) {
                top = s1.top();
                s1.pop();
                v1.push_back(top->val);
                if (top->left) {
                    s2.push(top->left);
                }
                if (top->right) {
                    s2.push(top->right);
                }
            }
            res.push_back(v1);
            
            if (s2.empty()) {
                break;
            }
            
            vector<int> v2;
            while(!s2.empty()) {
                top = s2.top();
                s2.pop();
                v2.push_back(top->val);
                
                if (top->right) {
                    s1.push(top->right);
                }
                
                if (top->left) {
                    s1.push(top->left);
                }
            }
            res.push_back(v2);
        }
        
        return res;
        
    }
};
