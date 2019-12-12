/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* ret = st.top();
        st.pop();
        TreeNode* tmp = ret->right;
        while (tmp) {
            st.push(tmp);
            tmp=tmp->left;
        }
        return ret->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (st.size() > 0);
    }
};
