class Solution {
public:
    
    int findInIdx(vector<int>& inorder, int val) {
        int i;
        for (i=0; i< inorder.size(); i++) {
            if (inorder[i] == val) {
                return i;  
            } 
        }
        return i;
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int in_lo, int in_hi) {
        static int p_idx = 0;
        if (in_lo > in_hi) 
            return NULL;
        TreeNode* root = new TreeNode(preorder[p_idx]);
        p_idx++;
        root->left = NULL;
        root->right = NULL;
        if (in_lo == in_hi) {
            return root;
        }
        int mid = findInIdx(inorder, root->val);
        root->left = build(preorder, inorder, in_lo, mid-1);
        root->right = build(preorder, inorder, mid+1, in_hi);
        return root;        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return(build(preorder, inorder, 0, inorder.size()-1));
    }
};
