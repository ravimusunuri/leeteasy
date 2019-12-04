class Codec {
public:

    string serialize(TreeNode* root) {
        string serialized;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            
            serialized.append(cur ? to_string(cur->val) : string("null"));
            serialized.push_back(' ');
            
            if (cur) {    
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        
        return serialized;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string nodeLeft, nodeRight;
        ss >> nodeLeft;
        
        TreeNode* root = nodeLeft == "null" ? nullptr : new TreeNode(stoi(nodeLeft));
        
