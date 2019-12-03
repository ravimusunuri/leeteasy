class Solution {
public:
    
      struct Node {
        int left_size;
        int node_size;
        int val;
        Node * left;
        Node * right;
        Node (int n) :
            val(n),
            node_size(1),
            left_size(0),
            left(NULL),
            right(NULL)
        {}
    };
    
    
    
    Node* insert(Node *root, int key, int* count) {
        if (!root) {
            return (new Node(key));
        } else if (root->val == key) {
            root->node_size++;
            *count = *count+ root->left_size;
        } else if (key < root->val) {
            root->left_size++;
            root->left = insert(root->left, key, count);
        } else {
            *count = *count+ root->left_size+root->node_size;
            root->right = insert(root->right, key, count);
        }
        return root;
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        } else if (nums.size() == 1) {
            return {0};
        }
        vector<int> count(nums.size());
        Node * root = NULL;
        for (int i = nums.size() - 1; i >= 0; i--) {
            root = insert(root, nums[i],&count[i]);
        }
        return count;
    }
    
};
