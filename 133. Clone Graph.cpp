/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        
         if (node == NULL)
                return node;

        unordered_map<Node*, Node*> map;

        queue<Node*> myq;

        Node* clone = new Node();
        clone->val = node->val;
        map.insert({node, clone});

        myq.push(node);
        while (!myq.empty()) {
                Node* u = myq.front();
                myq.pop();
                vector<Node*> n = u->neighbors;
                auto it1 = map.find(u);
                Node* u_copy = it1->second;

                for (int i=0; i< n.size(); i++) {
                        Node* v = n[i];
                        Node* v_copy;
                        auto it2 = map.find(v);
                        if (it2 == map.end() ) {
                                v_copy = new Node();
                                v_copy->val = v->val;
                                map.insert({v, v_copy});
                                myq.push(v);
                        } else {
                                v_copy = it2->second;
                        }
                        u_copy->neighbors.push_back(v_copy);
                }

        }
        return clone;

    }
};
