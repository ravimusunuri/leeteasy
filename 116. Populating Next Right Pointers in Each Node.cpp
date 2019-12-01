class Solution {
public:
    Node* connect(Node* root) {
         
        if (root ==  NULL) {
            return NULL;
        }
        
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(root);
        
        while (!q1.empty() || !q2.empty()) {
            if (q1.empty()) {
                break;
            }
            Node* top;
            Node* p1 = NULL; 
            while(!q1.empty()) {
                top = q1.front();
                q1.pop();
                top->next = NULL;
                if (p1 != NULL) {
                    p1->next = top;
                } 
                p1 = top;
                if (top->left) {
                    q2.push(top->left);
                }
                if (top->right) {
                    q2.push(top->right);
                }
            }      
            
            if (q2.empty()) {
                break;
            }
            
            p1 = NULL;
            while(!q2.empty()) {
                top = q2.front();
                q2.pop();
                
                top->next = NULL;
                if (p1 != NULL) {
                    p1->next = top;
                } 
                p1 = top;
                
                if (top->left) {
                    q1.push(top->left);
                }
                if (top->right) {
                    q1.push(top->right);
                }
            }
            
        }
        
        return root;
    }
};
